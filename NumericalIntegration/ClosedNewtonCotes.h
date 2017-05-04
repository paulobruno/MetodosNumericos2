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

#ifndef CLOSED_NEWTON_COTES_H
#define CLOSED_NEWTON_COTES_H

#include "Integration.h"
#include <vector>
#include <string>

class ClosedNewtonCotes : public Integration
{
public:

	ClosedNewtonCotes(std::string filename, int integrationMethod);

	double calculateIntegral();
	
	friend class RombergIntegration;

protected:

	ClosedNewtonCotes() {}

	int m, typeMethod;
	std::vector<double> x, fx;
};

#endif // CLOSED_NEWTON_COTES_H
