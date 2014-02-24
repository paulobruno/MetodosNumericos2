#ifndef SIMPSON_38_RULE_H
#define SIMPSON_38_RULE_H

#include "IntegrationMethod.h"
#include <string>

class Simpson38Rule : public IntegrationMethod
{
	public:
		Simpson38Rule(MnTableReader table) : 
			IntegrationMethod(MnTableReader table) {}

		double calculateIntegral();
};

#endif // SIMPSON_38_RULE_H
