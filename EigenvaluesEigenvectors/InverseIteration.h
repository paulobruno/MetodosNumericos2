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

#ifndef __INVERSE_ITERATION_H__
#define __INVERSE_ITERATION_H__

#include "PowerMethod.h"
#include <string>

class InverseIteration : public PowerMethod
{
    public:
    
        InverseIteration(std::string filename) : PowerMethod(filename) {}
        virtual ~InverseIteration() {}

        void calculateEigenvalue();
};

#endif // __INVERSE_ITERATION_H__
