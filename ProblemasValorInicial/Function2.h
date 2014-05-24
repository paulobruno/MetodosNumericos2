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

#ifndef __FUNCTION2_H__
#define __FUNCTION2_H__

#include "Function.h"
#include <cmath>

class Function2 : public Function
{

	public:

		Function2() {}
		virtual ~Function2() {}

		double f(double v, double t) {return ( (1 + 4*t)*sqrt(v) );}
};

#endif // __FUNCTION2_H__
