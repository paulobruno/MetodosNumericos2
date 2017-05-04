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
	
		InverseIteration invItEvalue(argc[1]);
		invItEvalue.calculateEigenvalue();
    
    fim = get_timestamp();	

	std::vector<double> evector;
	int order;
	double evalue;
	
	order = invItEvalue.getOrder();
	evalue = invItEvalue.getEigenvalue();
	evector = invItEvalue.getEigenvector();

    // print results
    std::cout << "\nResults: \n" << "\033[0;31mUnit Eigenvector:\033[0m\n";

    for (unsigned int i = 0; i < order; ++i)
    {            
        std::cout << evector[i] << '\n';
    }
    
    std::cout << "\033[0;33mEigenvalue: \033[0m" << evalue << "\n\n";
    
	
	std::cout << "tempo: " << (fim - inicio)/1000.0L << " milissegundos.\n";

	return 0;
}
