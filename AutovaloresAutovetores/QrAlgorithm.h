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
#include <vector>

class QrAlgorithm : public Eigenvalue
{
    public:
    
        QrAlgorithm(std::string filename) : Eigenvalue(filename) {}
        virtual ~QrAlgorithm() {}

        void calculateEigenvalue();
        
        std::vector<double>& getEigenvaluesMatrix() {return evaluesMatrix;}
        std::vector<double>& getEigenvectorsMatrix() {return evectorsMatrix;}

    private:

        std::vector<double> evaluesMatrix, evectorsMatrix;
};

#endif // __QR_ALGORITHM_H__
