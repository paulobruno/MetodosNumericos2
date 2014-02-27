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

#include "MnTableReader.h"
#include <fstream>

MnTableReader::MnTableReader(std::string filename)
{
	readTable(filename);
}

void MnTableReader::readTable(std::string filename)
{
	unsigned int i;
	double tempX, tempFx;

	std::ifstream fileTable;
    fileTable.open(filename.c_str(), std::ifstream::in);

	fileTable >> m;

	for (i = 0; i <= m; ++i)
	{
		fileTable >> tempX >> tempFx;

		x.push_back(tempX);
		fx.push_back(tempFx);
	}
}
