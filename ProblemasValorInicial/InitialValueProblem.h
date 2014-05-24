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

#ifndef __INITIAL_VALUE_PROBLEM_H__
#define __INITIAL_VALUE_PROBLEM_H__

#include "Function.h"
#include <vector>

class InitialValueProblem
{
	public:
	
		virtual ~InitialValueProblem() {}

		virtual void solveProblem() = 0;

	protected:

		double y0, xMin, xMax, step;
		Function* func;
		std::vector<double> y;
};

#endif // __INITIAL_VALUE_PROBLEM_H__
