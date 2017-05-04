#include "AdamsPredictorCorrector.h"
#include "RungeKutta.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

AdamsPredictorCorrector::AdamsPredictorCorrector(std::string filename, const std::vector<Function*>& functions, int pcType)
{
	pcOrder = (pcMethod)pcType;

	if ((pcOrder != ADAMS_THIRD_ORDER) && (pcOrder != ADAMS_FOURTH_ORDER))
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

void AdamsPredictorCorrector::solveProblem()
{
    // set the number of decimals of std::cout
    std::cout.setf( std::ios::fixed, std:: ios::floatfield );
    
	RungeKutta rk4;

	double a = (xMax - xMin) / step;
	int m = (int) a;

	switch (pcOrder)
	{
		case ADAMS_THIRD_ORDER:
			// calculate the previous values
			rk4.xMin = this->xMin;
			rk4.xMax = this->xMin + 2 * this->step;
			rk4.step = this->step;
			rk4.func = this->func;
			rk4.y0   = this->y0;
			rk4.rkOrder = FOURTH_ORDER; // Runge-Kutta 4th Order
			
			y = rk4.solveProblem(this);
		
			for (unsigned int i = 2; i <= m; ++i)
			{
				double auxY = y[i] + step*(23*func->f(y[i], step*i) - 16*func->f(y[i-1], step*(i-1)) + 5*func->f(y[i-2], step*(i-2))) / 12.0;
				double auxDiffY = func->f(auxY, step*(i+1));
				y.push_back(y[i] + step*(5*auxDiffY + 8*func->f(y[i], step*i) - func->f(y[i-1], step*(i-1))) / 12.0); 
			}
			break;

		case ADAMS_FOURTH_ORDER:
			// calculate the previous values
			rk4.xMin = this->xMin;
			rk4.xMax = this->xMin + 3 * this->step;
			rk4.step = this->step;
			rk4.func = this->func;
			rk4.y0   = this->y0;
			rk4.rkOrder = FOURTH_ORDER; // Runge-Kutta 4th Order
			
			y = rk4.solveProblem(this);
			
			for (unsigned int i = 3; i <= m; ++i)
			{
				double auxY = y[i] + step*(55*func->f(y[i], step*i) - 59*func->f(y[i-1], step*(i-1)) + 37*func->f(y[i-2], step*(i-2)) - 9*func->f(y[i-3], step*(i-3))) / 24.0;
				double auxDiffY = func->f(auxY, step*(i+1));
				y.push_back(y[i] + step*(9*auxDiffY + 19*func->f(y[i], step*i) - 5*func->f(y[i-1], step*(i-1)) + func->f(y[i-2], step*(i-2))) / 24.0);
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
