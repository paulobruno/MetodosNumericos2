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
	DoubleIntegration doubletrapezio(argc[1], 1);

	std::cout << "Integral: " << doubletrapezio.calculateIntegral() << "\n";

	return 0;
}
