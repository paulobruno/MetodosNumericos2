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

#ifndef __POWER_METHOD_H__
#define __POWER_METHOD_H__

#include "Eigenvalue.h"
#include <string>
#include <vector>

class PowerMethod : public Eigenvalue
{
    public:
    
        PowerMethod(std::string filename) : Eigenvalue(filename) {}
        virtual ~PowerMethod() {}
        
        virtual void calculateEigenvalue() = 0;
        
        double getEigenvalue() {return evalue;}
        std::vector<double>& getEigenvector() {return evector;}

    protected:

        double evalue;
        std::vector<double> evector;
};

#endif // __POWER_METHOD_H__
