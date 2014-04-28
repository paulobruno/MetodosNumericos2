#include "RombergIntegration.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

RombergIntegration::RombergIntegration(std::string filename, std::vector<Function*>& functions)
{
	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> m1;

	m2 = m1 / 2;

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

	double h1 = (xMax - xMin) / (double)m1;
	double h2 = (xMax - xMin) / (double)m2;

	fileTable1 << m1;
	fileTable2 << m2;

	for (int i = 0; i < m1; ++i)
	{
		double x1 = xMin + i*h1;
		fileTable1 << "\n" << x1 << "\t" << func->f(x1);

		double x2 = xMin + i*h2;
		fileTable2 << "\n" << x2 << "\t" << func->f(x2);
	}
}
