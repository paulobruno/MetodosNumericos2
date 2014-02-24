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

#include "Simpson38Rule.h"

double Simpson38Rule::calculateIntegral()
{
	double sum = fx[0];

	for (int i = 1; i < m; ++i)
	{
		if (i % 3) 
			sum += 3*fx[i];
		else 
			sum += 2*fx[i];
	}

	sum += fx[m];
	
	return ( (3 * (x[m] - x[0]) * sum) / (8*m) );
}
