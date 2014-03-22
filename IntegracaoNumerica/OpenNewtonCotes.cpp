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

#include "OpenNewtonCotes.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

OpenNewtonCotes::OpenNewtonCotes(std::string filename, const std::vector<Function*>& functions)
{
	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> n;

	if (n < 0 || n > 4)
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

	// loads the values of the general methods
	const double alpha[4] = { 1.5, 1.333333, 0.208333, 0.3 };
	const int weight[4][5] = { 1,   1,   0,   0,   0,
							   2,  -1,   2,   0,   0,
							  11,   1,   1,   11,  0,
							  11, -14,  26,  -14,  11 };
}

double OpenNewtonCotes::calculateIntegral()
{
	double step = ( (xMax - xMin) / (double)(n+2) );

	if (n > 0)	
	{
		double sum = 0;

		for (int i = 1; i <= n+1; ++i)
		{
			sum += func->f(xMin + i*step) * weight[n-1][i-1];
		}

		return (alpha[n-1] * step * sum);
	}
	else
	{
		return ( 2 * step * func->f( (xMin + xMax)/2 ) );
	}
}
