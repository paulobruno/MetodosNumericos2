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

#include "InverseIteration.h"
#include <iostream>

int main(int narg, char* argc[])
{
	InverseIteration invItEvalue("teste3.txt");

    invItEvalue.calculateEigenvalue();

	return 0;
}
