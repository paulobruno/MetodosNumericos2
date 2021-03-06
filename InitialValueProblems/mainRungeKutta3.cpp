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

#include "RungeKutta.h"
#include "Function.h"
#include "Function1.h"
#include "Function2.h"
#include "Function3.h"

int main(int narg, char* argc[])
{
	std::vector<Function*> functions;
	functions.push_back( new Function1() );
	functions.push_back( new Function2() );
	functions.push_back( new Function3() );
		
	RungeKutta rk3(argc[1], functions, 2);
	rk3.solveProblem();

	return 0;
}
