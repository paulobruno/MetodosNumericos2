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

#include "QrAlgorithm.h"
#include <iostream>
#include <vector>

int main(int narg, char* argc[])
{
	QrAlgorithm qrAlg(argc[1]);
    qrAlg.calculateEigenvalue();

	std::vector<double> evaluesMatrix, evectorsMatrix;
	int order;
	
	order = qrAlg.getOrder();
	evaluesMatrix  = qrAlg.getEigenvaluesMatrix();
	evectorsMatrix = qrAlg.getEigenvectorsMatrix();

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
}
