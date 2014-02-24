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

#include "MnTableReader.h"
#include "IntegrationMethod.h"
#include "Simpson38Rule.h"

#include <vector>
#include <stdio.h>

int main(int narg, char* argc[])
{
	MnTableReader table("mn2_table");
	Simpson38Rule simpson(table);

	printf("resposta: %lf\n", simpson.calculateIntegral());

	return 0;
}
