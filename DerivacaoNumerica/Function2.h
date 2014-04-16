/*********************************************/
/*                                           */
/*  2014, Fortaleza, Ceara                   */
/*                                           */
/*  UNIVERSIDADE FEDERAL DO CEARA            */
/*  CURSO DE COMPUTACAO                      */
/*  METODOS NUMERICOS II                     */
/*  PROFESSORA: Emanuele Marques dos Santos  */
/*                                           */
/*  Jose Orlando Barbosa Filho      336224   */
/*  Paulo Bruno de Sousa Serafim    354086   */
/*                                           */
/*********************************************/

#ifndef FUNCTION2_H
#define FUNCTION2_H

#include "Function.h"

class Function2 : public Function
{
public:

	Function2() {}
	virtual ~Function2() {}

	double f(double x) {return ( 2*x*x*x*x - 6*x*x*x - 12*x - 8 );}
};

#endif // FUNCTION2_H
