/* 2014, Fortaleza, Ceara
 *
 * UNIVERSIDADE FEDERAL DO CEARA
 * CURSO DE COMPUTACAO
 * METODOS NUMERICOS II
 * PROFESSORA: Emanuele Marques dos Santos
 *
 * Jonas Lima da Silva             344090
 * Livio de Lima Sales             343158
 * Paulo Bruno de Sousa Serafim    354086
 */

#ifndef SIMPSON_38_RULE_H
#define SIMPSON_38_RULE_H

#include "IntegrationMethod.h"
#include <string>

class Simpson38Rule : public IntegrationMethod
{
	public:
		Simpson38Rule(MnTableReader table) : 
			IntegrationMethod(table) {}

		double calculateIntegral();
};

#endif // SIMPSON_38_RULE_H
