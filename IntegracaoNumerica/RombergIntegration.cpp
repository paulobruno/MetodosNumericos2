#include "RombergIntegration.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

RombergIntegration::RombergIntegration(std::string filename, std::vector<Function*>& functions)
{
	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> h1;

	if (h1 % 2)
	{
		std::cout << "H1 deve ser multiplo de 2 Digite 'make help' para ajuda.\nPrograma abortado.\n";
		exit(EXIT_FAILURE);
	}

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

	writeClosedNCfiles();
}

double RombergIntegration::calculateIntegral()
{
	closedNC = new ClosedNewtonCotes("closedNCforRomberg1.txt", 1);

	integral1 = closedNC->calculateIntegral();

	delete closedNC;


	closedNC = new ClosedNewtonCotes("closedNCforRomberg2.txt", 1);

	integral2 = closedNC->calculateIntegral();

	delete closedNC;


	return ((4/3)*integral2 - (1/3)*integral1);
}

void RombergIntegration::writeClosedNCfiles()
{
	std::ofstream fileTable1, fileTable2;
    fileTable1.open("closedNCforRomberg1.txt", std::ofstream::out);
    fileTable2.open("closedNCforRomberg2.txt", std::ofstream::out);

	double step1 = double(xMax - xMin) / (double)h1; 
	double step2 = double(xMax - xMin) / (double)h2; 

	fileTable1 << h1;
	fileTable2 << h2;

	for (int i = 0; i < h1; ++i)
	{
		double x1 = xMin + i*step1;
		fileTable1 << "\n" << x1 << "\t" << func->f(x1);

		double x2 = xMin + i*step2;
		fileTable2 << "\n" << x2 << "\t" << func->f(x2);
	}
}
