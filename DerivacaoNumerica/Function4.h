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

#ifndef FUNCTION4_H
#define FUNCTION4_H

#include "Function.h"
#include <cmath>

class Function4 : public Function
{
public:

	Function4() {}
	virtual ~Function4() {}

	double f(double x) {return ( 1 - x - 4*x*x*x + 2*pow(x,5) );}
};

#endif // FUNCTION4_H
