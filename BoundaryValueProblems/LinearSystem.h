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

#ifndef __LINEAR_SYSTEM_H__
#define __LINEAR_SYSTEM_H__

#include <string>
#include <vector>

class LinearSystem
{
	public:
	
		LinearSystem(std::string filename);
		virtual ~LinearSystem() {}
		
		virtual void solveSystem() = 0;

	protected:

		unsigned int order;
		double yMin, yMax, step;
        std::vector<double> coeffMatrix, constVector;
};

#endif // __LINEAR_SYSTEM_H__
