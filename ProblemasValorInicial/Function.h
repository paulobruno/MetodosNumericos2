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

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

class Function
{

	public:

		Function() {}
		virtual ~Function() {}

		virtual double f(double v, double t) = 0;
};

#endif // __FUNCTION_H__
