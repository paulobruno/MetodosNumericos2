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

#include "Simpson38Rule.h"
#include <iostream>
#include <cstdlib>

double Simpson38Rule::calculateIntegral()
{
	if (m % 3) // m is not a multiple of 3
	{
		std::cout << "O numero de intervalos para o metodo 3/8 de Simpson deve ser multiplo de 3.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	double sum = fx[0];

	for (int i = 1; i < m; ++i)
	{
		if (i % 3) // i is not a multiple of 3
			sum += 3*fx[i];
		else // i is a multiple of 3
			sum += 2*fx[i];
	}

	sum += fx[m];
	
	return ( (3 * (x[m] - x[0]) * sum) / (8*m) );
}
