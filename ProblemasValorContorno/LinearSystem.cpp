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

#include "LinearSystem.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

LinearSystem::LinearSystem(std::string filename)
{
	std::ifstream file;
    file.open(filename.c_str(), std::ifstream::in);
    
    // reads step
    file >> step;
    
    // reads yMin and yMax
    file >> yMin >> yMax;
    
    // reads order
    file >> order;
    
    if (order < 2)
    {
        std::cout << "Ordem incorreta. Ordem precisa ser no minimo 2.\nPrograma abortado.\n";
	    exit(EXIT_FAILURE);
    }
    
    // reads matrix
    for (unsigned int i = 0; i < order; ++i)
    {
        for (unsigned int j = 0; j < order; ++j)
        {
            double temp;
            file >> temp;
            
            coeffMatrix.push_back(temp);
        }
    }
    
    // reads vectors
    for (unsigned int i = 0; i < order; ++i)
    {   
        double temp;
        file >> temp;
            
    	constVector.push_back(temp);
	}
}
