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

#include "GaussianQuadrature.h"
#include "ClosedNewtonCotes.h"
#include <iostream>
#include <vector>
#include <time.h>

#include "Function.h"
#include "Function1.h"
#include "Function2.h"

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
    
    double infIntegral, supIntegral, midIntegral;
    
    timestamp_t inicio, fim;
	inicio = get_timestamp();
	
		std::vector<Function*> functions;
	
		functions.push_back( new Function1() );
		functions.push_back( new Function2() );

		GaussianQuadrature quadrature(argc[1], functions);
		midIntegral = quadrature.calculateIntegral();

		std::cout << "Quad: " << midIntegral << '\n';

		ClosedNewtonCotes infTrapezio(argc[2], 1);
		infIntegral = infTrapezio.calculateIntegral();
	
		std::cout << "Inf: " << infIntegral << '\n';
	
		ClosedNewtonCotes supTrapezio(argc[3], 1);
		supIntegral = supTrapezio.calculateIntegral();

		std::cout << "Sup: " << supIntegral << '\n';
	
		std::cout << "Integral: " << infIntegral + midIntegral + supIntegral << "\n";

    fim = get_timestamp();	
	
	std::cout << "tempo: " << (fim - inicio)/1000.0L << " milissegundos.\n";

	return 0;
}
