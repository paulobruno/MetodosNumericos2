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

#ifndef __EIGENVALUE_H__
#define __EIGENVALUE_H__

#include <string>
#include <vector>

class Eigenvalue
{
    public:
    
        Eigenvalue(std::string filename);
        virtual ~Eigenvalue() {}
        
        virtual void calculateEigenvalue() = 0;
        
        int getOrder() {return order;}
        
    protected:
    
        int order;
        double error, mi; // mi used only in shift iteration
        std::vector<double> matrix;
};

#endif // __EIGENVALUE_H__
