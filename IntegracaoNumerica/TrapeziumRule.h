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

#ifndef TRAPEZIUM_RULE_H
#define TRAPEZIUM_RULE_H

#include "IntegrationMethod.h"
#include <string>

class TrapeziumRule : public IntegrationMethod
{
	public:
		TrapeziumRule(MnTableReader table) : 
			IntegrationMethod(table) {}

		double calculateIntegral();
};

#endif // TRAPEZIUM_RULE_H
