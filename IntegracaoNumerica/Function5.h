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

#ifndef FUNCTION5_H
#define FUNCTION5_H

#include "Function.h"
#include <cmath>

class Function5 : public Function
{
public:

	Function5() {}
	virtual ~Function5() {}

	double f(double x) {return (4/(1+x*x));}
};

#endif // FUNCTION5_H
