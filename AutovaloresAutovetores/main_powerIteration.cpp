/*********************************************/
/*                                           */
/*  2014, Fortaleza, Ceara                   */
/*                                           */
/*  UNIVERSIDADE FEDERAL DO CEARA            */
/*  CURSO DE COMPUTACAO                      */
/*  METODOS NUMERICOS II                     */
/*  PROFESSORA: Emanuele Marques dos Santos  */
/*                                           */
/*  Paulo Bruno de Sousa Serafim    354086   */
/*                                           */
/*********************************************/

#include "PowerIteration.h"
#include <iostream>

int main(int narg, char* argc[])
{
	PowerIteration powItEvalue("teste2.txt");

    powItEvalue.calculateEigenvalue();

	return 0;
}
