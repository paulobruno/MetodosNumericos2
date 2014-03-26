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

#include "DoubleIntegration.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

DoubleIntegration::DoubleIntegration(std::string filename, int integrationMethod)
{
	typeMethod = integrationMethod;

	if (typeMethod < 1 || typeMethod > 6)
	{
		std::cout << "Metodo inexistente. Escolha um valor no intervalo [1,6]. Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	int iAux, jAux;
	double tempX, tempY, tempFx;

	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> mx >> my;

	for (int i = 0; i < (mx+1)*(my+1); ++i)
	{
		fileTable >> iAux >> jAux >> tempX >> tempY >> tempFx;

		x.push_back(tempX);
		y.push_back(tempY);
		fx.push_back(tempFx);
	}
}

double DoubleIntegration::calculateIntegral()
{
	std::vector<double>:: iterator it;
	std::vector<double> integration;
	std::vector<double> tempFx(my + 1);

	ClosedNewtonCotes::m = my;

	for (int i = 0; i <= mx; ++i)
	{
		ClosedNewtonCotes::x.push_back(this->x[i]);
	}

	for (it = this->fx.begin(); it < this->fx.end(); ++it)
	{
		for (int i = 0; i <= my; ++i)
		{
			tempFx[i] = (*it);
			++it;
		}

		ClosedNewtonCotes::fx = tempFx;

		integration.push_back(ClosedNewtonCotes::calculateIntegral());
	}

	ClosedNewtonCotes::m = integration.size() - 1;
	ClosedNewtonCotes::fx = integration;

	return ClosedNewtonCotes::calculateIntegral();
}
