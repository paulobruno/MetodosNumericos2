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

#ifndef __ADAMS_PREDICTOR_CORRECTOR_H__
#define __ADAMS_PREDICTOR_CORRECTOR_H__

#include "InitialValueProblem.h"
#include <vector>
#include <string>

enum pcMethod
{
    ADAMS_THIRD_ORDER    = 0,
    ADAMS_FOURTH_ORDER   = 1
};

class AdamsPredictorCorrector : public InitialValueProblem
{
	public:
	
		AdamsPredictorCorrector(std::string filename, const std::vector<Function*>& functions, int pcType);
		virtual ~AdamsPredictorCorrector() {}
		
		void solveProblem();

	private:

		pcMethod pcOrder;
};

#endif // __ADAMS_PREDICTOR_CORRECTOR_H__
