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

#ifndef __FUNCTION4_H__
#define __FUNCTION4_H__

#include "Function.h"

class Function4 : public Function
{

	public:

		Function4() {}
		virtual ~Function4() {}

		double f(double v, double t) {return ( 1 - t*t + 2 * v );}
};

#endif // __FUNCTION4_H__
