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

#ifndef __FUNCTION1_H__
#define __FUNCTION1_H__

#include "Function.h"

class Function1 : public Function
{

	public:

		Function1() {}
		virtual ~Function1() {}

		double f(double v, double t) {return ( v*t*t*t - 1.5*v );}
};

#endif // __FUNCTION1_H__
