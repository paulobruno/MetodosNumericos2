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

#include "TridiagonalMatrix.h"
#include <iostream>

void TridiagonalMatrix::solveSystem()
{
	for (unsigned int i = 0; i < order; ++i)
	{
		belowDiagonal.push_back(0);
		mainDiagonal.push_back(0);
		aboveDiagonal.push_back(0);
	}

	// transform matrix in 3 vectors
	for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
        	if (i == j)
        	{
        		mainDiagonal[i] = coeffMatrix[i*order + j];
    		}
    		else if (i == (j-1))
    		{
    			aboveDiagonal[i] = coeffMatrix[i*order + j];
    		}
    		else if (i == (j+1))
    		{
    			belowDiagonal[i] = coeffMatrix[i*order + j];
    		}
        }
    }
    
    
    // solve the tridiagonal system, adapted from http://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
    unsigned int newOrder = order - 1;
    
    aboveDiagonal[0] /= mainDiagonal[0];
    constVector[0] /= mainDiagonal[0];
    
    for (unsigned int i = 1; i < newOrder; ++i)
    {
    	aboveDiagonal[i] /= mainDiagonal[i] - belowDiagonal[i] * aboveDiagonal[i-1];
    	
    	constVector[i] = (constVector[i]  - belowDiagonal[i] * constVector[i-1]) /
    	                 (mainDiagonal[i] - belowDiagonal[i] * aboveDiagonal[i-1]);
    }
    
	constVector[newOrder] = (constVector[newOrder]  - belowDiagonal[newOrder] * constVector[newOrder-1]) /
	                    	(mainDiagonal[newOrder] - belowDiagonal[newOrder] * aboveDiagonal[newOrder-1]);

	for (unsigned int i = newOrder; i-- > 0;)
	{
		constVector[i] -= aboveDiagonal[i] * constVector[i+1];
	}
	
	for (unsigned int i = 0; i < order; ++i)
	{
		std::cout << constVector[i] << '\n';
	}
}
