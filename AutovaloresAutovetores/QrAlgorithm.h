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

#ifndef __QR_ALGORITHM_H__
#define __QR_ALGORITHM_H__

#include "Eigenvalue.h"
#include <string>

class QrAlgorithm : public Eigenvalue
{
    public:
    
        QrAlgorithm(std::string filename) : Eigenvalue(filename) {evaluesMatrix = NULL; evectorsMatrix = NULL;}
        virtual ~QrAlgorithm() {delete evaluesMatrix; delete evectorsMatrix;}

        void calculateEigenvalue();
        
        double* getEigenvaluesMatrix() {return evaluesMatrix;}
        double* getEigenvectorsMatrix() {return evectorsMatrix;}

    private:

        double *evaluesMatrix, *evectorsMatrix;
};

#endif // __QR_ALGORITHM_H__
