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

#ifndef ROMBERG_INTEGRATION_H
#define ROMBERG_INTEGRATION_H

#include "Integration.h"
#include "ClosedNewtonCotes.h"
#include "Function.h"
#include <vector>
#include <string>

class RombergIntegration : public Integration
{
public:

	RombergIntegration(std::string filename, std::vector<Function*>& functions);
	virtual ~RombergIntegration() {}

	double calculateIntegral();

private:

	double m1, m2, xMin, xMax, integral1, integral2;

	Function* func;
	ClosedNewtonCotes* closedNC;

	void writeClosedNCfiles();
};

#endif // ROMBERG_INTEGRATION_H
