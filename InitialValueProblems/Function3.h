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

#ifndef __FUNCTION3_H__
#define __FUNCTION3_H__

#include "Function.h"

class Function3 : public Function
{

	public:

		Function3() {}
		virtual ~Function3() {}

		double f(double v, double t) {return ( -2*v + t*t );}
};

#endif // __FUNCTION3_H__
