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

#include "MnTableReader.h"
#include "IntegrationMethod.h"
#include "Simpson13Rule.h"
#include "Simpson38Rule.h"

#include <vector>
#include <iostream>

int main(int narg, char* argc[])
{
	MnTableReader table("mn2_table.txt");
	Simpson13Rule simpson(table);

	std::cout << "Resposta: " << simpson.calculateIntegral() << "\n";

	return 0;
}
