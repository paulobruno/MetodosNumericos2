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

#include "HouseholderTransformation.h"
#include <iostream>

int main(int narg, char* argc[])
{
	HouseholderTransformation houseTransf(argc[1]);

    houseTransf.calculateEigenvalue();

	return 0;
}
