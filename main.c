/** CSOLVER: Program to solve systems of linear equations in C
 *  Author: Jose Lopez
 *  License: The Unlicense
 */



#include "includes\Main.h"


int main()
{
	initializeProgram(DIMENSION);
	
	struct _number n1 = newNumber(-1, 2);
	struct _number n2 = newNumber( 3, 1);
	struct _number n3 = newNumber( 4, 1);
	
	struct _number n4 = newNumber( 2, 1);
	struct _number n5 = newNumber(-1, 1);
	struct _number n6 = newNumber( 7, 8);
	
	struct _number n7 = newNumber( 2, 1);
	struct _number n8 = newNumber( 1, 1);
	struct _number n9 = newNumber(-1, 3);
	
	struct _matrix *m = createMatrix();
	struct _matrix *i = createIdentityMatrix();
	
	setMatrixProgrammatically(m, &n1, &n2, &n3,
								 &n4, &n5, &n6,
								 &n7, &n8, &n9);
	printLines(2);
	printMatrixAndId(m,i);
	reduceMatrix(m,i);
	
	return EXIT_SUCCESS;
}
