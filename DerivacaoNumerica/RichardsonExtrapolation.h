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

#ifndef __RICHARDSON_EXTRAPOLATION_H__
#define __RICHARDSON_EXTRAPOLATION_H__

#include "Differentiation.h"
#include "FirstDerivative.h"
#include "Function.h"
#include <vector>
#include <string>

class RichardsonExtrapolation : public Differentiation
{
    public:
    
        RichardsonExtrapolation(std::string filename, int diffMethod);
        RichardsonExtrapolation(std::string filename, const std::vector<Function*>& functions, int diffMethod);
        ~RichardsonExtrapolation() {} // don't delete func because FirstDerivative already do this
        
        double calculateDerivative();

    private:
    
        FirstDerivative *firstDiff;
        
        double xi, step1, step2;
        Function *func;
        derivativeType diffType;
};

#endif // __RICHARDSON_EXTRAPOLATION_H__
