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

#include "ShiftIteration.h"
#include <iostream>

int main(int narg, char* argc[])
{
	ShiftIteration shiftItEvalue(argc[1]);
    shiftItEvalue.calculateEigenvalue();
    
	std::vector<double> evector;
	int order;
	double evalue;
	
	order = shiftItEvalue.getOrder();
	evalue = shiftItEvalue.getEigenvalue();
	evector = shiftItEvalue.getEigenvector();

    // print results
    std::cout << "\nResults: \n" << "\033[0;31mUnit Eigenvector:\033[0m\n";

    for (unsigned int i = 0; i < order; ++i)
    {            
        std::cout << evector[i] << '\n';
    }
    
    std::cout << "\033[0;33mEigenvalue: \033[0m" << evalue << "\n\n";

	return 0;
}
