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

#include "PowerIteration.h"
#include <cmath>
#include <iostream>

void PowerIteration::calculateEigenvalue()
{
    unsigned int k = 1;
    double oldEvalue, zVector[order];
    
    // initialize eigenvector and auxiliary vector Z
    for (unsigned int i = 0; i < order; ++i)
    {
        evector.push_back(1);
        zVector[i] = 0;
    }
    
    
    // prints matrix
    std::cout << "\033[0;32mMatriz A:\033[0m\n";
    
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {         
            std::cout << matrix[i*order + j] << '\t';
        }
        std::cout << '\n';
    }
    
    std::cout << '\n';
    
    
    // calculates first vector Z
    for (unsigned int i = 0; i < order; ++i)
    {
        zVector[i] = 0;
        
        for (unsigned int j = 0; j < order; ++j)
        {
            zVector[i] += matrix[i*order + j] * evector[j];
            
        }
    }
    
    evalue = 0;
    
    
    // main loop
    do
    {
        oldEvalue = evalue;
        
        //calculate next vector Q
        double norm = 0;
        
        for (unsigned int i = 0; i < order; ++i)
        {
            norm += zVector[i]*zVector[i];
        }
        
        norm = sqrt(norm);
        
        for (unsigned int i = 0; i < order; ++i)
        {
            evector[i] = zVector[i]/norm;
        }
        
        
        // calculates next vector Z
        for (unsigned int i = 0; i < order; ++i)
        {
            zVector[i] = 0;
            
            for (unsigned int j = 0; j < order; ++j)
            {
                zVector[i] += matrix[i*order + j] * evector[j];
                
            }
        }
        
        
        // calculates greatest absolute eigenvalue
        evalue = 0;
        
        for (unsigned int i = 0; i < order; ++i)
        {
            evalue += evector[i]*zVector[i];
        }
        
        
        // print results
        std::cout << "k = " << k << '\n' << "\033[0;31mUnit Eigenvector:\033[0m\n";
    
        for (unsigned int i = 0; i < order; ++i)
        {            
            std::cout << evector[i] << '\n';
        }
        
        std::cout << "\033[0;33mEigenvalue: \033[0m" << evalue << "\n\n";
        
        ++k;
    }
    while (evalue - oldEvalue > error);
    
    
    // reprints matrix for convenience
    std::cout << "\033[0;32mMatriz A:\033[0m\n";   
    
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {         
            std::cout << matrix[i*order + j] << '\t';
        }
        std::cout << '\n';
    }
    
    std::cout << '\n';
}
