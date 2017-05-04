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

#ifndef __FIRST_DERIVATIVE_H__
#define __FIRST_DERIVATIVE_H__

#include "Differentiation.h"
#include "Function.h"
#include <vector>
#include <string>

enum derivativeType
{
    BACKWARD = 0,
    FORWARD  = 1,
    CENTRAL  = 2,
    LAGRANGE = 3
};

class FirstDerivative : public Differentiation
{
    public:
    
        FirstDerivative(std::string filename);
        FirstDerivative(std::string filename, int diffMethod);
        FirstDerivative(std::string filename, const std::vector<Function*>& functions, int diffMethod);
        
        virtual ~FirstDerivative() {if(func != NULL) delete func;}
        
        friend class RichardsonExtrapolation;
        
        double calculateDerivative();

    private:

        int n;
        double xi, step;
        Function *func;
        derivativeType diffType;
        std::vector<double> x, fx;
        
        double calculateLagrangeDiff();
        
        FirstDerivative() {} // used by class RichardsonExtrapolation
};

#endif // __FIRST_DERIVATIVE_H__
