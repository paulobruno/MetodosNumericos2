// 2013, PAULO BRUNO DE SOUSA SERAFIM, Fortaleza - CE, Brasil

#include <stdlib.h>
#include <stdio.h>

#define SIZE 3

int main(int narg, char* argc[])
{
	double A[SIZE][SIZE] = { 2,  1,  3, 
	                         0, -1,  1,
	                         1,  0,  3};
	double I[SIZE][SIZE] = {1, 0, 0, 
	                        0, 1, 0, 
	                        0, 0, 1};
	double b[SIZE] = {16, 38, 38};
	int i, j, k, x, y;

	// matriz triangular superior
	for (k = 0; k < SIZE; ++k)
	{
	    double pivot = A[k][k];
	    
	    for (j = 0; j < SIZE; ++j)
		{
			I[k][j] /= pivot;
		}
		for (j = k; j < SIZE; ++j)
		{
			A[k][j] /= pivot;
		}

		for (i = 0; i < SIZE; ++i)
		{
			if (i != k)
			{
			    for (j = 0; j < SIZE; ++j)
			    {
					I[i][j] -= A[i][k] * I[k][j];
			    }
				for (j = k; j < SIZE; ++j)
				{
					A[i][j] -= A[i][k] * A[k][j];
				}
			}
		}
		
		
	    for (i = 0; i < SIZE; ++i)
	    {
		    for (j = 0; j < SIZE; ++j)
		    {
			    printf("\t%.4lf", A[i][j]);
		    }
		    printf("\t|");
		    for (j = 0; j < SIZE; ++j)
		    {
			    printf("\t%.4lf", I[i][j]);
		    }
		    printf("\n");
	    }
	    printf("\n");
	}


	return 0;
}
