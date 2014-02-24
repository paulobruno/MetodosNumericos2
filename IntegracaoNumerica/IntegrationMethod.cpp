#include "IntegrationMethod.h"

IntegrationMethod::IntegrationMethod(MnTableReader table)
{
	m = table.getM();
	x = table.getVectorX();
	fx = table.getVectorFx();
}
