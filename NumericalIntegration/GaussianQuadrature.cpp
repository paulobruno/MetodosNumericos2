/*********************************************/
/*                                           */
/*  2014, Fortaleza, Ceara                   */
/*                                           */
/*  UNIVERSIDADE FEDERAL DO CEARA            */
/*  CURSO DE COMPUTACAO                      */
/*  METODOS NUMERICOS II                     */
/*  PROFESSORA: Emanuele Marques dos Santos  */
/*                                           */
/*  Jose Orlando Barbosa Filho      336224   */
/*  Paulo Bruno de Sousa Serafim    354086   */
/*                                           */
/*********************************************/

#include "GaussianQuadrature.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>

GaussianQuadrature::GaussianQuadrature(std::string filename, std::vector<Function*>& functions)
{
	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> n;

	if (n < 1 || n > 5)
	{
		std::cout << "Metodo inexistente. Escolha um valor no intervalo [0,4]. Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	int funcIndex;
	fileTable >> funcIndex;

	if (funcIndex > functions.size())
	{
		std::cout << "Funcao inexistente. Escolha um valor de funcao valido. Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	func = functions[funcIndex-1];
	
	fileTable >> xMin >> xMax;
}

double GaussianQuadrature::calculateIntegral()
{
	// loads the values of the general methods
	const double A[5][5] = {        2.0,        0.0,        0.0,        0.0,        0.0,
							        1.0,        1.0,        0.0,        0.0,        0.0,
							 0.55555556, 0.88888889, 0.55555556,        0.0,        0.0,
							 0.34785485, 0.65214515, 0.65214515, 0.34785485,        0.0,
							 0.23692689, 0.47862867, 0.56888889, 0.47862867, 0.23692689 };
							
	const double t[5][5] = {        0.0,         0.0,        0.0,        0.0,        0.0,
							-0.57735027,  0.57735027,        0.0,        0.0,        0.0,
							-0.77459667,         0.0, 0.77459667,        0.0,        0.0,
							-0.86113631, -0.33998104, 0.33998104, 0.86113631,        0.0,
							-0.90617985, -0.53846931,        0.0, 0.53846931, 0.90617985 };
							
	double x_t, integral = 0;

    for (int i = 0 ; i < n ; ++i)
    {
    	x_t = ( (xMax - xMin) * t[n-1][i] + xMin + xMax ) / 2.0;
        integral += A[n-1][i] * func->f(x_t);
    }
    return ((xMax - xMin)*integral / 2.0);
}

