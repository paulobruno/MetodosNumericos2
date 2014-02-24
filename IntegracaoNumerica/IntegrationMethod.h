#ifndef INTEGRATION_METHOD_H
#define INTEGRATION_METHOD_H

#include "MnTableReader.h"
#include <vector>

class IntegrationMethod
{
	public:
		IntegrationMethod(MnTableReader table);
		virtual ~IntegrationMethod() {}

		virtual double calculateIntegral() = 0;

	private:
		unsigned int m;
		std::vector<double> x, fx;
};

#endif // INTEGRATION_METHOD_H
