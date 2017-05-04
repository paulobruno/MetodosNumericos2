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

#include "ClosedNewtonCotes.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

ClosedNewtonCotes::ClosedNewtonCotes(std::string filename, int integrationMethod)
{
	typeMethod = integrationMethod;

	if (typeMethod < 1 || typeMethod > 6)
	{
		std::cout << "Metodo inexistente. Escolha um valor no intervalo [1,6]. Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	double tempX, tempFx;

	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> m;

	for (int i = 0; i <= m; ++i)
	{
		fileTable >> tempX >> tempFx;

		x.push_back(tempX);
		fx.push_back(tempFx);
	}
}

double ClosedNewtonCotes::calculateIntegral()
{
	// loads the values of the general ns
	const int d[6] = { 2, 6, 8, 90, 288, 840 };
	const int weight[6][7] = { 1,   1,   0,   0,   0,   0,   0,
							   1,   4,   1,   0,   0,   0,   0,
							   1,   3,   3,   1,   0,   0,   0,
							   7,  32,  12,  32,   7,   0,   0,
							  19,  75,  50,  50,  75,  19,   0,
							  41, 216,  27, 272,  27, 216,  41 };
							  
	if (m % (typeMethod))
	{
		std::cout << "O numero de intervalos para este metodo deve ser multiplo de " << typeMethod << ". Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	double sum = 0;

	for (int i = 0; i < m; i += typeMethod)
	{
		for (int j = 0; j <= typeMethod; ++j)
		{
			sum += fx[i+j]*weight[typeMethod-1][j]; 
		}
	}

	double step = (x[m] - x[0]) / (double)m;

	return ( ( (double)(typeMethod*step) / (double)d[typeMethod-1] ) * sum );
}
