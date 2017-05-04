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

#include "Jacobi.h"
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

		Jacobi jacobiEvalue(argc[1]);
		jacobiEvalue.calculateEigenvalue();
		
    fim = get_timestamp();	
	
	int order;
	std::vector<double> evaluesMatrix, evectorsMatrix;
	
	order = jacobiEvalue.getOrder();
	evaluesMatrix  = jacobiEvalue.getEigenvaluesMatrix();
	evectorsMatrix = jacobiEvalue.getEigenvectorsMatrix();

    // print eigenvalues matrix
    std::cout << "\n\033[0;32mMatrix of eigenvalues:\033[0m\n";
    for (unsigned int l = 0; l < order; ++l)
    {   
        for (unsigned int c = 0; c < order; ++c)
        {         
            std::cout << evaluesMatrix[l*order + c] << '\t';
        }
        
        std::cout  << '\n';
    }
    
    // print eigenvectors matrix
    std::cout << "\n\033[0;32mMatrix of unit eigenvectors:\033[0m\n";
    for (unsigned int l = 0; l < order; ++l)
    {   
        for (unsigned int c = 0; c < order; ++c)
        {         
            std::cout << evectorsMatrix[l*order + c] << '\t';
        }
        
        std::cout  << '\n';
    }
    std::cout  << '\n';
    
	
	std::cout << "tempo: " << (fim - inicio)/1000.0L << " milissegundos.\n";
    
	return 0;
}
