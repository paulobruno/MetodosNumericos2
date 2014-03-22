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
	ClosedNewtonCotes closedNC(argc[1], (int)argc[2]);

	std::cout << "Integration: " << closedNC.calculateIntegral() << "\n";

	return 0;
}
