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

#ifndef __HOUSEHOLDER_TRANSFORMATION_H__
#define __HOUSEHOLDER_TRANSFORMATION_H__

#include "Eigenvalue.h"
#include <string>
#include <vector>

class HouseholderTransformation : Eigenvalue
{
    public:
    
        HouseholderTransformation(std::string filename) : Eigenvalue(filename) {}
        virtual ~HouseholderTransformation() {}

        void calculateEigenvalue();
        
        std::vector<double>& getEigenvaluesMatrix() {return evaluesMatrix;}
        std::vector<double>& getEigenvectorsMatrix() {return evectorsMatrix;}

    private:

        std::vector<double> evaluesMatrix, evectorsMatrix;        
};

#endif // __HOUSEHOLDER_TRANSFORMATION_H__
