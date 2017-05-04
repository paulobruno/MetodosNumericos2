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

#ifndef __GAUSSIAN_ELIMINATION_H__
#define __GAUSSIAN_ELIMINATION_H__

#include "LinearSystem.h"

class GaussianElimination : public LinearSystem
{
	public:
	
		GaussianElimination(std::string filename) : LinearSystem(filename) {}
		virtual ~GaussianElimination() {}

		void solveSystem();		
};

#endif // __GAUSSIAN_ELIMINATION_H__
