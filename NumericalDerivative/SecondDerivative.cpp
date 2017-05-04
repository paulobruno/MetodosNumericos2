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

#include "SecondDerivative.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

SecondDerivative::SecondDerivative(std::string filename, int diffMethod)
{
	diffType = (derivativeType)diffMethod;
	
	std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);

    file >> n;

    if (n != 3)
    {
	    std::cout << "Numero de pontos incorreto. Devem ser usados 3 pontos. Digite 'make help' para ajuda.\nPrograma abortado.\n";
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

SecondDerivative::SecondDerivative(std::string filename, const std::vector<Function*>& functions, int diffMethod)
{
	diffType = (derivativeType)diffMethod;
	
	if (diffType != BACKWARD && diffType != FORWARD && diffType != CENTRAL)
	{
        std::cout << "Metodo inexistente. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);	    
	}
	
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);

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

double SecondDerivative::calculateDerivative()
{	
    switch (diffType)
    {
        case BACKWARD:
	        if (func == NULL)
            {
    	        return ((fx[2] - 2*fx[1] + fx[0]) / (step*step));
            }
            else
            {
            	return ((func->f(xi) - 2*func->f(xi-step) + func->f(xi-2*step)) / (step*step));
            }
            break;
    
        case FORWARD:
	        if (func == NULL)
            {
    	        return ((fx[2] - 2*fx[1] + fx[0]) / (step*step));
            }
            else
            {
            	return ((func->f(xi+2*step) - 2*func->f(xi+step) + func->f(xi)) / (step*step));
        	}
            break;
            
        case CENTRAL:
	        if (func == NULL)
            {
    	        return ((fx[2] - 2*fx[1] + fx[0]) / (step*step));
            }
            else
            {
            	return ((func->f(xi+step) - 2*func->f(xi) + func->f(xi-step)) / (step*step));
            }
            break;
            
        default:
            std::cout << "Erro, contate o administrador.\nPrograma abortado.\n";
	        exit(EXIT_FAILURE);
            break;   
    }
}
