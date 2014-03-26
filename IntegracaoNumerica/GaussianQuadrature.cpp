/*********************************************/
/*                                           */
/*  2014, Fortaleza, Ceara                   */
/*                                           */
/*  UNIVERSIDADE FEDERAL DO CEARA            */
/*  CURSO DE COMPUTACAO                      */
/*  METODOS NUMERICOS II                     */
/*  PROFESSORA: Emanuele Marques dos Santos  */
/*                                           */
/*  Jose Orlando Barbosa Filho      336224   */
/*  Paulo Bruno de Sousa Serafim    354086   */
/*                                           */
/*********************************************/

#include "GaussianQuadrature.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>

GaussianQuadrature::GaussianQuadrature(std::string filename, std::vector<Function*>& functions);
{
	Integral = 0;

	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> n;

	if (n < 0 || n > 4)
	{
		std::cout << "Metodo inexistente. Escolha um valor no intervalo [0,4]. Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	int funcIndex;
	fileTable >> funcIndex;

	if (funcIndex > functions.size())
	{
		std::cout << "Funcao inexistente. Escolha um valor de funcao valido. Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

	func = functions[funcIndex-1];
	
	fileTable >> xMin >> xMax;
}

double GaussianQuadrature::calculateIntegral()
{
    switch(n)

    {
        case 2:
        {
            Vetor_X[0] = -0.70710678;
            Vetor_X[1] =  0.70710678;
            Peso[0] = 0.88622692;
            Peso[1] = 0.88622692;
            break;
        }
        case 3:
        {
            Vetor_X[0] = -1.22474487;
            Vetor_X[1] =  0;
            Vetor_X[2] =  1.22474487;
            Peso[0] = 0.29540897;
            Peso[1] = 1.18163590;
            Peso[2] = 0.29540897;
            break;
        }
        case 4:
        {
            Vetor_X[0] = -1.65068012;
            Vetor_X[1] = -0.52464762;
            Vetor_X[2] =  0.52464762;
            Vetor_X[3] =  1.65068012;
            Peso[0] = 0.08131283;
            Peso[1] = 0.80491409;
            Peso[2] = 0.80491409;
            Peso[3] = 0.08131283;
            break;
        }
        default:
        {
            return(-1);
        }
    }
    for (int i=0 ; i<n ; i++)
    {
        Integral += Peso[i]*(funcao_fx(Vetor_X[i]));
    }
    return(Integral);
}

