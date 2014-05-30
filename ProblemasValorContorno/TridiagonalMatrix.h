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

#ifndef __TRIDIAGONAL_MATRIX_H__
#define __TRIDIAGONAL_MATRIX_H__

#include "LinearSystem.h"
#include <string>
#include <vector>

class TridiagonalMatrix : public LinearSystem
{
	public:
	
		TridiagonalMatrix(std::string filename) : LinearSystem(filename) {}
		virtual ~TridiagonalMatrix() {}

		void solveSystem();

	private:

		std::vector<double> belowDiagonal, mainDiagonal, aboveDiagonal;
};

#endif // __TRIDIAGONAL_MATRIX_H__
