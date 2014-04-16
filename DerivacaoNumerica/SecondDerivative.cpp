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
            return ((func->f(xi) - 2*func->f(xi-step) + func->f(xi-2*step)) / (step*step));
            break;
    
        case FORWARD:
            return ((func->f(xi+2*step) - 2*func->f(xi+step) + func->f(xi)) / (step*step));
            break;
            
        case CENTRAL:
            return ((func->f(xi+step) - 2*func->f(xi) + func->f(xi-step)) / (step*step));
            break;
            
        default:
            std::cout << "Erro, contate o administrador.\nPrograma abortado.\n";
	        exit(EXIT_FAILURE);
            break;   
    }
}
