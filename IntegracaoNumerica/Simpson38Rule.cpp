#include "Simpson38Rule.h"

double Simpson38Rule::calculateIntegral()
{
	double sum = fx[0];

	for (int i = 1; i < m; ++i)
	{
		if (i % 3) 
			sum += 3*fx[i];
		else 
			sum += 2*fx[i];
	}

	sum += fx[m];
	
	return ( (3 * (x[m] - x[0]) * sum) / (8*m) );
}
