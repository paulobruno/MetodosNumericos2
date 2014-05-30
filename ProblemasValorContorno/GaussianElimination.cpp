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

#include "GaussianElimination.h"
#include <iostream>

void GaussianElimination::solveSystem()
{
	double cVector[order];
	double cMatrix[order][order];
	
    // set the number of decimals of std::cout
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    
    // initilizes coefficient matrix and print initial matrix
    std::cout << "\n\033[0;33mInitial matrix:\033[0m\n";
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
            // initializes A as the initial matrix;
            cMatrix[i][j] = coeffMatrix[i*order + j];
            std::cout << cMatrix[i][j] << '\t';
        }
        std::cout  << '\n';
    }
    std::cout  << '\n';
    
    // solves the system
    // TODO
    
}
