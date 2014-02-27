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

#ifndef SIMPSON_13_RULE_H
#define SIMPSON_13_RULE_H

#include "IntegrationMethod.h"
#include <string>

class Simpson13Rule : public IntegrationMethod
{
	public:
		Simpson13Rule(MnTableReader table) : 
			IntegrationMethod(table) {}

		double calculateIntegral();
};

#endif // SIMPSON_13_RULE_H
