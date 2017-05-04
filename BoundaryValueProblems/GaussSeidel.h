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

#ifndef __GAUSS_SEIDEL_H__
#define __GAUSS_SEIDEL_H__

#include "LinearSystem.h"
#include <string>

class GaussSeidel : public LinearSystem
{
	public:
	
		GaussSeidel(std::string filename) : LinearSystem(filename) {}
		virtual ~GaussSeidel() {}

		void solveSystem();

		void setError(double error) {this->error = error;}

	private:

		double error;
};

#endif // __GAUSS_SEIDEL_H__
