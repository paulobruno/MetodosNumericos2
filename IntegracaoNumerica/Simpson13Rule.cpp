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

#include "Simpson13Rule.h"
#include <iostream>
#include <cstdlib>

double Simpson13Rule::calculateIntegral()
{
	if (m % 2) // m is odd
	{
		std::cout << "O numero de intervalos para o metodo 1/3 de Simpson deve ser par.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	double sum = fx[0];

	for (int i = 1; i < m; ++i)
	{
		if (i % 2) // i is odd
			sum += 4*fx[i];
		else // i is even
			sum += 2*fx[i];
	}

	sum += fx[m];
	
	return ( ((x[m] - x[0]) * sum) / (3*m) );
}
