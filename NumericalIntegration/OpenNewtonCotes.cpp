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

	if (n < 2 || n > 5)
	{
		std::cout << "Metodo inexistente. Escolha um valor no intervalo [2,5]. Digite 'make help' para ajuda.\nPrograma abortado.\n";
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

double OpenNewtonCotes::calculateIntegral()
{
	// loads the values of the general methods
	const double alpha[4] = { 1.5, 1.333333, 0.208333, 0.3 };
	const int weight[4][5] = { 1,   1,   0,    0,   0,
							   2,  -1,   2,    0,   0,
							  11,   1,   1,   11,   0,
							  11, -14,  26,  -14,  11 };
							  
	double step = ( (xMax - xMin) / (double)(n+1) );

	double sum = 0;

	for (int i = 1; i <= n; ++i)
	{
		sum += func->f(xMin + i*step) * weight[n-2][i-1];
	}

	return (alpha[n-2] * step * sum);
}
