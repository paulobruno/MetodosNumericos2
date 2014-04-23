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

#ifndef __JACOBI_H__
#define __JACOBI_H__

#include "Eigenvalue.h"
#include <string>

class Jacobi : public Eigenvalue
{
    public:
    
        Jacobi(std::string filename) : Eigenvalue(filename) {evectorsMatrix = NULL; evaluesMatrix  = NULL;}
        virtual ~Jacobi() {delete evaluesMatrix; delete evectorsMatrix;}
        
        void calculateEigenvalue();
        
        double* getEigenvaluesMatrix() {return evaluesMatrix;}
        double* getEigenvectorsMatrix() {return evectorsMatrix;}

    private:

        double *evaluesMatrix, *evectorsMatrix;
        
};

#endif // __JACOBI_H__
