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

int main(int narg, char* argc[])
{
	Jacobi jacobiEvalue(argc[1]);
    jacobiEvalue.calculateEigenvalue();

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
    
	return 0;
	return 0;
}
