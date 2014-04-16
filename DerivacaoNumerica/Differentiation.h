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

#ifndef __DIFFERENTIATION_H__
#define __DIFFERENTIATION_H__

class Differentiation
{
public:

	virtual ~Differentiation() {}

	virtual double calculateDerivative() = 0;

};

#endif // __DIFFERENTIATION_H__
