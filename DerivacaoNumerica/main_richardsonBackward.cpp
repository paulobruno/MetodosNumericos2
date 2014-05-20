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

#include "RichardsonExtrapolation.h"
#include <iostream>
#include <vector>

#include "Function.h"

#include <sys/time.h>

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(int narg, char* argc[])
{
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    std::cout.precision(8);
    
    timestamp_t inicio, fim;
	inicio = get_timestamp();
	
		RichardsonExtrapolation richDiff(argc[1], 0);

		std::cout << "Richardson Backward Derivative: " << richDiff.calculateDerivative() << "\n";

    fim = get_timestamp();	
	
	std::cout << "tempo: " << (fim - inicio)/1000.0L << " milissegundos.\n";

	return 0;
}
