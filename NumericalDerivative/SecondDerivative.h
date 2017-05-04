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

#ifndef __SECOND_DERIVATIVE_H__
#define __SECOND_DERIVATIVE_H__

#include "Differentiation.h"
#include "Function.h"
#include <vector>
#include <string>

enum derivativeType
{
    BACKWARD = 0,
    FORWARD  = 1,
    CENTRAL  = 2
};

class SecondDerivative : public Differentiation
{
    public:
    
    	SecondDerivative(std::string filename, int diffMethod);
        SecondDerivative(std::string filename, const std::vector<Function*>& functions, int diffMethod);
        ~SecondDerivative() {if(func != NULL) delete func;}
        
        double calculateDerivative();

    private:

		int n;
        double xi, step;
        Function *func;
        derivativeType diffType;
		std::vector<double> x, fx;
};

#endif // __SECOND_DERIVATIVE_H__
