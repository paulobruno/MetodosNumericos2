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

#ifndef __RUNGE_KUTTA_H__
#define __RUNGE_KUTTA_H__

#include "InitialValueProblem.h"
#include "AdamsPredictorCorrector.h"
#include <vector>
#include <string>

enum rkMethod
{
    FORWARD_EULLER = 0,
    SECOND_ORDER   = 1,
    THIRD_ORDER    = 2,
    FOURTH_ORDER   = 3
};

class RungeKutta : public InitialValueProblem
{
	public:
	
		RungeKutta(std::string filename, const std::vector<Function*>& functions, int rungeKuttaMethod);
		virtual ~RungeKutta() {delete func;}
		
		void solveProblem();
		
		friend class AdamsPredictorCorrector;

	private:
	
		rkMethod rkOrder;
		
		// used by AdamsPredictorCorrector
		RungeKutta() {} 
		std::vector<double>& solveProblem(AdamsPredictorCorrector* adamsPc);
};

#endif // __RUNGE_KUTTA_H__
