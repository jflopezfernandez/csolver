/** CSOLVER: Program to solve systems of linear equations in C
 *  Author: Jose Lopez
 *  License: The Unlicense
 */



#include "includes\Main.h"


int main(int argc, char *argv[])
{
	initializeProgram(DIMENSION);
	
	/** ----------- ACTUAL OPERATION ----------- **/
	/*
	if ((argc == 2) && (atoi(argv[1]) == 0)) {
		// Fractional part matrix
		printf("Mode: FRACTIONAL\n");
		enterMatrixByRowFractional(m);
		printLines(3);
		printMatrix(m);
	} else {
		// Integral-type matrix
		printf("Mode: INTEGER\n");
		enterMatrixByRow(m);
		printLines(3);
		printMatrix(m);
	}*/
	
	/** ----------- TESTING ----------- **/
	
	struct _dualmatrixsystem *p = initializeProblem();
	
	freeDMS(p);
	return EXIT_SUCCESS;
}
