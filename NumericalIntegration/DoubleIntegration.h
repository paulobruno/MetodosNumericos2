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

#ifndef MULTIPLE_INTEGRATION_H
#define MULTIPLE_INTEGRATION_H

#include "ClosedNewtonCotes.h"
#include <vector>
#include <string>

class DoubleIntegration : public ClosedNewtonCotes
{
public:
	
	DoubleIntegration(std::string filename, int integrationMethod);

	double calculateIntegral();

private:

	int mx, my;

	std::vector<double> x, y, fx;
};

#endif // MULTIPLE_INTEGRATION_H
