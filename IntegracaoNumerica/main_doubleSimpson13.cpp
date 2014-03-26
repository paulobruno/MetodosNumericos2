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

#include "DoubleIntegration.h"
#include <iostream>

int main(int narg, char* argc[])
{
	DoubleIntegration doublesimpson13(argc[1], 2);

	std::cout << "Integration: " << doublesimpson13.calculateIntegral() << "\n";

	return 0;
}
