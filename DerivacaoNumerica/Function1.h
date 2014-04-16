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

#ifndef FUNCTION1_H
#define FUNCTION1_H

#include "Function.h"

class Function1 : public Function
{
public:

	Function1() {}
	virtual ~Function1() {}

	double f(double x) {return ( -0.1*x*x*x*x - 0.15*x*x*x - 0.5*x*x - 0.25*x + 1.2 );} 
};

#endif // FUNCTION1_H
