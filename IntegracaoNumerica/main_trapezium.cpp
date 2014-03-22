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

#include "ClosedNewtonCotes.h"
#include <iostream>

int main(int narg, char* argc[])
{
	ClosedNewtonCotes trapezio(argc[1], 1);

	std::cout << "Integral: " << trapezio.calculateIntegral() << "\n";

	return 0;
}
