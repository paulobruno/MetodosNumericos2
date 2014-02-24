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

#include "IntegrationMethod.h"

IntegrationMethod::IntegrationMethod(MnTableReader table)
{
	m = table.getM();
	x = table.getVectorX();
	fx = table.getVectorFx();
}
