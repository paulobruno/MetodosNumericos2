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

#ifndef GAUSSIAN_QUADRATURE_H
#define GAUSSIAN_QUADRATURE_H

#include "Integration.h"
#include "Function.h"
#include <vector>
#include <string>

class GaussianQuadrature : public Integration
{
	public:
		
		GaussianQuadrature(std::string filename, std::vector<Function*>& functions);
		virtual ~GaussianQuadrature() {delete func;}

		double calculateIntegral();
	
	private:
	
		int m, n;
		double xMin, xMax;
		Function *func;
};
#endif // GAUSSIAN_QUADRATURE_H
