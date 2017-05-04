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

#ifndef FUNCTION1_H
#define FUNCTION1_H

#include "Function.h"
#include <cmath>

class Function1 : public Function
{
public:

	Function1() {}
	virtual ~Function1() {}

	double f(double x) {return (1/(sqrt(x)));} 
};

#endif // FUNCTION1_H
