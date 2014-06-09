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

#include "RungeKutta.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

RungeKutta::RungeKutta(std::string filename, const std::vector<Function*>& functions, int rungeKuttaMethod)
{
	rkOrder = (rkMethod)rungeKuttaMethod;
	
	if ((rkOrder != FORWARD_EULLER) && (rkOrder != SECOND_ORDER) && (rkOrder != THIRD_ORDER) && (rkOrder != FOURTH_ORDER))
	{
        std::cout << "Metodo inexistente. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);	    
	}
	
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);

    file >> y0;

    int funcIndex;
    file >> funcIndex;

    if (funcIndex > functions.size())
    {
	    std::cout << "Funcao inexistente. Escolha um valor de funcao valido. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }

    func = functions[funcIndex-1];

    file >> step;

    if (step < 0)
    {
	    std::cout << "Step inadequado. Escolha um valor de step positivo. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }

    file >> xMin;
    file >> xMax;
}

void RungeKutta::solveProblem() 
{
    // set the number of decimals of std::cout
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    
	double a = (xMax - xMin) / step;
	int m = (int) a;
	
	y.push_back(y0);

	switch (rkOrder)
	{
		case FORWARD_EULLER:
			for (unsigned int i = 0; i < m; ++i)
			{
				y.push_back( y[i] + step*func->f(y[i], step*i) );
			}
			break;
	
		case SECOND_ORDER:
			for (unsigned int i = 0; i < m; ++i)
			{
				double k1 = step * func->f( y[i]     , step*i );
				double k2 = step * func->f( y[i] + k1, step*(i+1) );
				y.push_back( y[i] + (k1 + k2) / 2.0 );
			}			
			break;
			
		case THIRD_ORDER:
			for (unsigned int i = 0; i < m; ++i)
			{
				double k1 = step * func->f( y[i]            , step*i );
				double k2 = step * func->f( y[i] + 0.5*k1   , step*(i+0.5) );
				double k3 = step * func->f( y[i] - k1 + 2*k2, step*(i+1));
				y.push_back( y[i] + (k1 + 4*k2 + k3) / 6.0 );
			}		
			break;
			
		case FOURTH_ORDER:
			for (unsigned int i = 0; i < m; ++i)
			{
				double k1 = step * func->f( y[i]                  , step*i );
				double k2 = step * func->f( y[i] + k1/3.0         , step*(i+(1.0/3.0)) );
				double k3 = step * func->f( y[i] + k1/3.0 + k2/3.0, step*(i+(2.0/3.0)));
				double k4 = step * func->f( y[i] + k1 - k2 + k3   , step*(i+1));
				y.push_back( y[i] + (k1 + 3*k2 + 3*k3 + k4) / 8.0 );
			}		
			break;
			
		default:
            std::cout << "Erro, metodo incorreto.\nPrograma abortado.\n";
	        exit(EXIT_FAILURE);
			break;
	}
	
	std::cout << "\t--- t ---\t---- v ----\n";
	for (unsigned int i = 0; i <= m; ++i)
	{
    	std::cout.precision(7);
		std::cout << '\t' << step*i;
		std::cout.precision(15);
		std::cout << '\t' << y[i] << '\n';
	}
}

std::vector<double>& RungeKutta::solveProblem(AdamsPredictorCorrector* adamsPc) 
{
	int m = (xMax - xMin) / step;
	
	y.push_back(y0);

	switch (rkOrder)
	{
		case FORWARD_EULLER:
			for (unsigned int i = 0; i < m; ++i)
			{
				y.push_back( y[i] + step*func->f(y[i], step*i) );
			}
			break;
	
		case SECOND_ORDER:
			for (unsigned int i = 0; i < m; ++i)
			{
				double k1 = step * func->f( y[i]     , step*i );
				double k2 = step * func->f( y[i] + k1, step*(i+1) );
				y.push_back( y[i] + (k1 + k2) / 2.0 );
			}			
			break;
			
		case THIRD_ORDER:
			for (unsigned int i = 0; i < m; ++i)
			{
				double k1 = step * func->f( y[i]            , step*i );
				double k2 = step * func->f( y[i] + 0.5*k1   , step*(i+0.5) );
				double k3 = step * func->f( y[i] - k1 + 2*k2, step*(i+1));
				y.push_back( y[i] + (k1 + 4*k2 + k3) / 6.0 );
			}		
			break;
			
		case FOURTH_ORDER:
			for (unsigned int i = 0; i < m; ++i)
			{
				double k1 = step * func->f( y[i]                  , step*i );
				double k2 = step * func->f( y[i] + k1/3.0         , step*(i+(1.0/3.0)) );
				double k3 = step * func->f( y[i] + k1/3.0 + k2/3.0, step*(i+(2.0/3.0)));
				double k4 = step * func->f( y[i] + k1 - k2 + k3   , step*(i+1));
				y.push_back( y[i] + (k1 + 3*k2 + 3*k3 + k4) / 8.0 );
			}		
			break;
			
		default:
            std::cout << "Erro, metodo incorreto.\nPrograma abortado.\n";
	        exit(EXIT_FAILURE);
			break;
	}
	
	return y;
}
