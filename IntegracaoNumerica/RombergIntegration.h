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

	RombergIntegration(std::string filename, std::vector<Function*>& functions, int integrationMethod);
	virtual ~RombergIntegration() {delete func;}

	double calculateIntegral();

private:

	int typeMethod;
	double h1, h2, xMin, xMax;

	Function* func;
};

#endif // ROMBERG_INTEGRATION_H
