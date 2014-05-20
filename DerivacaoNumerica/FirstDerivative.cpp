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

#include "FirstDerivative.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

FirstDerivative::FirstDerivative(std::string filename)
{
    diffType = LAGRANGE;
    
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);
    
    file >> n;

    if (n != 3)
    {
	    std::cout << "Numero de pontos incorreto. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }
    
    double tempX, tempFx;
    
    for (unsigned int i = 0; i < n; ++i)
    {
		file >> tempX >> tempFx;

		x.push_back(tempX);
		fx.push_back(tempFx);
    }
    
    file >> xi;
    
    // default values
    step = 0;
    func = NULL;
}

FirstDerivative::FirstDerivative(std::string filename, int diffMethod)
{
	diffType = (derivativeType)diffMethod;
	
	std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);

    file >> n;

    if (n < 2 || n > 4)
    {
	    std::cout << "Numero de pontos incorreto. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }
    
    double tempX, tempFx;
    
    for (unsigned int i = 0; i < n; ++i)
    {
		file >> tempX >> tempFx;

		x.push_back(tempX);
		fx.push_back(tempFx);
    }
    
    step = x[1] - x[0];
    
    // default values
    xi = 0;
    func = NULL;
}

FirstDerivative::FirstDerivative(std::string filename, const std::vector<Function*>& functions, int diffMethod)
{
	diffType = (derivativeType)diffMethod;
	
	if (diffType != BACKWARD && diffType != FORWARD && diffType != CENTRAL)
	{
        std::cout << "Metodo inexistente. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);	    
	}
	
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);

    file >> n;

    if (n < 2 || n > 4)
    {
	    std::cout << "Numero de pontos incorreto. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }

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

    file >> xi;
}

double FirstDerivative::calculateDerivative()
{
    switch (diffType)
    {
        case BACKWARD:
            if (n == 2)
            {
            	if (func == NULL)
                {
                	return ((fx[1] - fx[0]) / step);
               	}
               	else
               	{
               		return ((func->f(xi) - func->f(xi-step)) / step);
               	}
            }
            else if (n == 3)
            {
                if (func == NULL)
                {
                	return ((3*fx[2] - 4*fx[1] + fx[0]) / (2*step));
               	}
               	else
               	{
               		return ((3*func->f(xi) - 4*func->f(xi-step) + func->f(xi-2*step)) / (2*step));
               	}
            }
            else
            {
	            std::cout << "Numero de pontos incorreto. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	            exit(EXIT_FAILURE);
            }
            break;
    
        case FORWARD:
            if (n == 2)
            {
                if (func == NULL)
                {
               		return ((fx[1] - fx[0]) / step);
               	}
               	else
               	{
                	return ((func->f(xi+step) - func->f(xi)) / step);
               	}
            }
            else if (n == 3)
            {
                if (func == NULL)
                {
               		return ((-fx[2] + 4*fx[1] - 3*fx[0]) / (2*step));
               	}
               	else
               	{
                	return ((-func->f(xi+2*step) + 4*func->f(xi+step) - 3*func->f(xi)) / (2*step));
               	}
            }
            else
            {
	            std::cout << "Numero de pontos incorreto. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	            exit(EXIT_FAILURE);
            }
            break;
            
        case CENTRAL:
            if (n == 2)
            {
                if (func == NULL)
                {
               		return ((fx[1] - fx[0]) / step); // in this case step = 2*h
               	}
               	else
               	{
                	return ((func->f(xi+step) - func->f(xi-step)) / step); // in this case step = 2*h
               	}
            }
            else if (n == 4)
            {
                if (func == NULL)
                {
               		return ((-fx[3] + 8*fx[2] - 8*fx[1] + fx[0]) / (12*step));
               	}
               	else
               	{
                	return ((-func->f(xi+2*step) + 8*func->f(xi+step) - 8*func->f(xi-step) + func->f(xi-2*step)) / (12*step));
               	}
            }
            else
            {
	            std::cout << "Numero de pontos incorreto. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	            exit(EXIT_FAILURE);
            }
            break;
            
        case LAGRANGE:
            return calculateLagrangeDiff();
            break;
            
        default:
            std::cout << "Erro, contate o administrador.\nPrograma abortado.\n";
	        exit(EXIT_FAILURE);
            break;           
    }
}

double FirstDerivative::calculateLagrangeDiff()
{
    return ( (fx[0]*(2*xi - x[1] - x[2]) / ((x[0]-x[1])*(x[0]-x[2]))) + 
             (fx[1]*(2*xi - x[0] - x[2]) / ((x[1]-x[0])*(x[1]-x[2]))) + 
             (fx[2]*(2*xi - x[0] - x[1]) / ((x[2]-x[0])*(x[2]-x[1]))) );
}
