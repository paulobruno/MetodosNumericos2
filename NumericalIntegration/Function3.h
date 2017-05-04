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

#ifndef FUNCTION3_H
#define FUNCTION3_H

#include "Function.h"
#include <cmath>

class Function3 : public Function
{
public:

	Function3() {}
	virtual ~Function3() {}

	double f(double x) {return (2*pow(x,3)+3*x*x+6*x+1);}
};

#endif // FUNCTION3_H
