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
#include <fstream>
#include <cstdlib>
#include <cmath>

void Jacobi::calculateEigenvalue()
{
    unsigned int k = 1;
    double errorSum;
    double A[order][order], P[order][order], X[order][order];
    
    // set the number of decimals of std::cout
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    
    // initilizes matrices and print initial matrix
    std::cout << "\n\033[0;33mInitial matrix:\033[0m\n";
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
            // initializes A as the initial matrix;
            A[i][j] = matrix[i*order + j];
            std::cout << A[i][j] << '\t';
            
            // accumulative X matrix as identity
            if (i == j)
            {
                X[i][j] = 1;
            }
            else
            {
                X[i][j] = 0;
            }
        }
        std::cout  << '\n';
    }
    std::cout  << '\n';
    
    // main loop 
    do
    {
        for (unsigned int i = 0; i < order-1; ++i)
        {
            for (unsigned int j = i+1; j < order; ++j)
            {
                if ( (A[i][j] > error) || (A[i][j] < (0 - error)) ) // if the value of Aij is not close enough to zero
                {
                    // initilize P matrix as identity matrix
                    for (unsigned int l = 0; l < order; ++l)
                    {
                        for (unsigned int c = 0; c < order; ++c)
                        {
                            if (l == c)
                            {
                                P[l][c] = 1;
                            }
                            else
                            {
                                P[l][c] = 0;
                            }
                        }
                    }   
                
                    // calculate P matrix
                    double theta;
                    
                    if (A[i][i] == A[j][j])
                    {
                        theta = M_PI_4;
                    }
                    else
                    {
                        theta = atan( (2*A[i][j]) / (A[i][i] - A[j][j]) ) / 2.0;
                    }
                    
                    P[i][i] =  cos(theta);
                    P[i][j] = -sin(theta);
                    P[j][j] =  cos(theta);
                    P[j][i] =  sin(theta);
                    
                
                    // multiply matrix [A][P] and saves in AP and creates an auxiliary X matrix
                    double AP[order][order], xAux[order][order];
                    
                    for (unsigned int l = 0; l < order; ++l)
                    {
                        for (unsigned int c = 0; c < order; ++c)
                        {
                            AP[l][c] = 0;
                            
                            for (unsigned int m = 0; m < order; ++m)
                            {
                                AP[l][c] += A[l][m]*P[m][c];
                            }
                        }
                    }
                    
                    // calculates the new values of A and keep accumulative P matrix
                    for (unsigned int l = 0; l < order; ++l)
                    {
                        for (unsigned int c = 0; c < order; ++c)
                        {
                            A[l][c] = 0;
                            xAux[l][c] = 0;
                            
                            for (unsigned int m = 0; m < order; ++m)
                            {
                                A[l][c] += P[m][l]*AP[m][c]; // multiply transpose P and AP
                                xAux[l][c] += X[l][m]*P[m][c];                                
                            }
                        }
                    }
                    
                    // print calculated matrix A and transfer contents from xAux to X
                    std::cout << "\nk = " << k << " - pair(" << i+1 << ',' << j+1 << ")\n\033[0;31mNew matrix:\033[0m\n";
                    for (unsigned int l = 0; l < order; ++l)
                    {   
                        for (unsigned int c = 0; c < order; ++c)
                        {         
                            std::cout << A[l][c] << '\t';
                            X[l][c] = xAux[l][c];
                        }
                        
                        std::cout  << '\n';
                    }
                }
            }
        }
       
        // verify error
        errorSum = 0;
        
        for (unsigned int l = 0; l < order; ++l)
        {
            for (unsigned int c = 0; c < order; ++c)
            {   
                if (l != c)
                {  
                    errorSum += A[l][c]*A[l][c];
                }
            }
        }
        
        ++k;
        std::cout << '\n';
    }
    while (errorSum > error);
    // end of main loop
    
    
    // assign the values for the eigenvalues and eigenvectors matrices
    for (unsigned int l = 0; l < order; ++l)
    {   
        for (unsigned int c = 0; c < order; ++c)
        {         
            evaluesMatrix.push_back ( A[l][c] );
            evectorsMatrix.push_back( X[l][c] );
        }
    }
}
