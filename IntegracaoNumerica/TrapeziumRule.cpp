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

#include "TrapeziumRule.h"
#include <iostream>
#include <cstdlib>

double TrapeziumRule::calculateIntegral()
{
	double sum = fx[0];

	for (int i = 1; i < m; ++i)
	{
		sum += 2*fx[i];
	}

	sum += fx[m];
	
	return ( ((x[m] - x[0]) * sum) / (2*m) );
}
