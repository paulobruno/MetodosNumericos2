#include "RombergIntegration.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

RombergIntegration::RombergIntegration(std::string filename, std::vector<Function*>& functions, int integrationMethod)
{
	typeMethod = integrationMethod - 1;

	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> h1;

	h2 = h1 / 2;

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

double RombergIntegration::calculateIntegral()
{
	ClosedNewtonCotes cn1, cn2;
	
	int m1 = (xMax - xMin) / h1;
	int m2 = (xMax - xMin) / h2;

	cn1.m = m1;
	cn2.m = m2;
	
	cn1.typeMethod = typeMethod;
	cn2.typeMethod = typeMethod;

	for (int i = 0; i <= m1; ++i)
	{
		double x1 = xMin + i*h1;
		
		cn1.x.push_back(x1);
		cn1.fx.push_back(func->f(x1));
	}
	
	for (int i = 0; i <= m2; ++i)
	{	
		double x2 = xMin + i*h2;
		
		cn2.x.push_back(x2);
		cn2.fx.push_back(func->f(x2));
	}
	
	return ((4/3)*cn2.calculateIntegral() - (1/3)*cn1.calculateIntegral());
}
