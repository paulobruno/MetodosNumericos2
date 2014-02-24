/* 2014, Fortaleza, Ceara
 *
 * UNIVERSIDADE FEDERAL DO CEARA
 * CURSO DE COMPUTACAO
 * METODOS NUMERICOS II
 * PROFESSORA: Emanuele Marques dos Santos
 *
 * Jonas Lima da Silva             344090
 * Livio de Lima Sales             343158
 * Paulo Bruno de Sousa Serafim    354086
 */

#ifndef MN_TABLE_READER_H
#define MN_TABLE_READER_H

#include <string>
#include <vector>

class MnTableReader
{
	public:
		MnTableReader(std::string filename);
		virtual ~MnTableReader() {}

		unsigned int getM() {return m;}

		std::vector<double>& getVectorX() {return x;}
		std::vector<double>& getVectorFx() {return fx;}

	private:
		unsigned int m;
		std::vector<double> x;
		std::vector<double> fx;

		void readTable(std::string filename);
};

#endif // MN_TABLE_READER_H
