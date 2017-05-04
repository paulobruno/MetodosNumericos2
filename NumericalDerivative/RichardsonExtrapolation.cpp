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

#include "RichardsonExtrapolation.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

RichardsonExtrapolation::RichardsonExtrapolation(std::string filename, int diffMethod)
{

}

RichardsonExtrapolation::RichardsonExtrapolation(std::string filename, const std::vector<Function*>& functions, int diffMethod)
{
	diffType = (derivativeType)diffMethod;
	
	if (diffType != BACKWARD && diffType != FORWARD && diffType != CENTRAL)
	{
        std::cout << "Metodo inexistente. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);	    
	}
	
    std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);

    file >> step1;

    if (step1 < 0)
    {
	    std::cout << "Step inadequado. Escolha um valor de step positivo. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }
    
    step2 = step1 / 2.0;
    
    int funcIndex;
    file >> funcIndex;

    if (funcIndex > functions.size())
    {
	    std::cout << "Funcao inexistente. Escolha um valor de funcao valido. Digite 'make help' para ajuda.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }

    func = functions[funcIndex-1];

    file >> xi;

    firstDiff = new FirstDerivative();
    firstDiff->xi = this->xi;
    firstDiff->func = this->func;
            
    switch (diffType)
    {
        case BACKWARD:
            firstDiff->n = 3;
            firstDiff->diffType = BACKWARD;
            break;
    
        case FORWARD:
            firstDiff->n = 3;
            firstDiff->diffType = FORWARD;
            break;
            
        case CENTRAL:
            firstDiff->n = 4;
            firstDiff->diffType = CENTRAL;
            break;
            
        default:
            std::cout << "Erro, contate o administrador.\nPrograma abortado.\n";
	        exit(EXIT_FAILURE);
            break;   
    }
}

double RichardsonExtrapolation::calculateDerivative()
{
    double d1, d2;

    firstDiff->step = this->step1;
    d1 = firstDiff->calculateDerivative();
    
    firstDiff->step = this->step2;
    d2 = firstDiff->calculateDerivative();

    return ( (4.0*d2 - d1) / 3.0 );
}
