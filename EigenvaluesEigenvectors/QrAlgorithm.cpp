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
#include <fstream>
#include <cstdlib>
#include <cmath>

void QrAlgorithm::calculateEigenvalue()
{
    unsigned int k = 1;
    double errorSum;double A[order][order], Q[order][order], R[order][order], X[order][order], P[order][order];
    
    // set the number of decimals of std::cout
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    
    // initilizes matrices and print initial matrix
    std::cout << "\n\033[0;31mInitial matrix:\033[0m\n";
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
            // initialize A as the initial matrix;
            A[i][j] = matrix[i*order + j];
            std::cout << A[i][j] << '\t';
            
            // initialize Q and X matrices as identity
            if (i == j)
            {
                Q[i][j] = 1;
                X[i][j] = 1;
            }
            else
            {
                Q[i][j] = 0;
                X[i][j] = 0;
            }
        }
        std::cout  << '\n';
    }
    std::cout  << '\n';
    
    // start R values with A
    for (unsigned int l = 0; l < order; ++l)
    {   
        for (unsigned int c = 0; c < order; ++c)
        {         
            R[l][c] = A[l][c];
        }
    }
    
    // main loop 
    do
    {
        // initilize P matrix as identity matrix
        for (unsigned int l = 0; l < order; ++l)
        {
            for (unsigned int c = 0; c < order; ++c)
            {
                if (l == c)
                {
                    Q[l][c] = 1;
                }
                else
                {
                    Q[l][c] = 0;
                }
            }
        }   
        
        for (unsigned int i = 1; i < order; ++i)
        {
            for (unsigned int j = 0; j < i; ++j)
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
                    double denominator = sqrt( (R[i][j]*R[i][j]) + (R[j][j]*R[j][j]) );
                    
                    P[j][j] =  R[j][j] / denominator;
                    P[j][i] =  R[i][j] / denominator;
                    P[i][i] = -R[j][j] / denominator;
                    P[i][j] =  R[i][j] / denominator;
                    
                
                    // construct matrix [P]t[R] and saves in B
                    double B[order][order], qAux[order][order], xAux[order][order];
                    
                    for (unsigned int l = 0; l < order; ++l)
                    {
                        for (unsigned int c = 0; c < order; ++c)
                        {
                            B[l][c] = 0;
                            
                            for (unsigned int m = 0; m < order; ++m)
                            {
                                B[l][c] += P[m][l]*R[m][c]; // multiply transpose P and R
                            }
                        }
                    }
                    
                    // transfer contents from B to R
                    for (unsigned int l = 0; l < order; ++l)
                    {   
                        for (unsigned int c = 0; c < order; ++c)
                        {         
                            R[l][c] = B[l][c];
                        }
                    }
                    
                    // accumulates the P values in the Q matrix and all the Q values in the matrix X
                    for (unsigned int l = 0; l < order; ++l)
                    {
                        for (unsigned int c = 0; c < order; ++c)
                        {
                            qAux[c][l] = 0;
                            xAux[c][l] = 0;
                            
                            for (unsigned int m = 0; m < order; ++m)
                            {
                                qAux[c][l] += P[m][l]*Q[c][m]; // multiply transpose P and transpose Q
                                xAux[c][l] += P[m][l]*X[c][m]; // multiply transpose P and transpose X
                            }
                        }
                    }
                    
                    // transfer contents from auxiliary Q and auxiliary X to Q and X
                    for (unsigned int l = 0; l < order; ++l)
                    {   
                        for (unsigned int c = 0; c < order; ++c)
                        {         
                            Q[l][c] = qAux[l][c];
                            X[l][c] = xAux[l][c];
                        }
                    }
                }
            }
        }
                    
        // print calculated matrix Q
        std::cout << "k = " << k << "\n\033[0;33mQ matrix:\033[0m\n";
        for (unsigned int l = 0; l < order; ++l)
        {   
            for (unsigned int c = 0; c < order; ++c)
            {         
                std::cout << Q[l][c] << '\t';
            }
            std::cout  << '\n';
        }
        
        // print calculated matrix R
        std::cout << "\033[0;33mR matrix:\033[0m\n";
        for (unsigned int l = 0; l < order; ++l)
        {   
            for (unsigned int c = 0; c < order; ++c)
            {         
                std::cout << R[l][c] << '\t';
            }
            std::cout  << '\n';
        }    
                    
        // calculates the new values of A
        for (unsigned int l = 0; l < order; ++l)
        {
            for (unsigned int c = 0; c < order; ++c)
            {
                A[l][c] = 0;
                
                for (unsigned int m = 0; m < order; ++m)
                {
                    A[l][c] += R[l][m]*Q[m][c];
                }
            }
        }
        
        // assign values of A to R
        for (unsigned int l = 0; l < order; ++l)
        {
            for (unsigned int c = 0; c < order; ++c)
            {
                R[l][c] = A[l][c];
            }
        }
        
        // print calculated matrix A
        std::cout << "\033[0;31mNew matrix:\033[0m\n";
        for (unsigned int l = 0; l < order; ++l)
        {   
            for (unsigned int c = 0; c < order; ++c)
            {         
                std::cout << A[l][c] << '\t';
            }
            std::cout  << '\n';
        }
       
        // verify error
        errorSum = 0;
        
        for (unsigned int l = 1; l < order; ++l)
        {
            for (unsigned int c = 0; c < l; ++c)
            {
                errorSum += A[l][c]*A[l][c];
            }
        }
        
        ++k;
        std::cout << '\n';
        
    } while (errorSum > error);
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
