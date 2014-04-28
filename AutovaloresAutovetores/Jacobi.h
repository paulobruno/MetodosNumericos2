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
#include <vector>

class Jacobi : public Eigenvalue
{
    public:
    
        Jacobi(std::string filename) : Eigenvalue(filename) {}
        virtual ~Jacobi() {}
        
        void calculateEigenvalue();
        
        std::vector<double>& getEigenvaluesMatrix() {return evaluesMatrix;}
        std::vector<double>& getEigenvectorsMatrix() {return evectorsMatrix;}

    private:

        std::vector<double> evaluesMatrix, evectorsMatrix;
        
};

#endif // __JACOBI_H__
