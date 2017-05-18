/** CSOLVER: Program to solve systems of linear equations in C
 *  Author: Jose Lopez
 *  License: The Unlicense
 */



#include "includes\Main.h"


int main()
{
	initializeProgram(DIMENSION);
	
	/** Rational */

	struct _number n1;
	n1.status = RATIONAL;
	n1.type.rat.n = -1;
	n1.type.rat.d =  2;
	
	printNumber(&n1);
	printf(" + ");
	
	struct _number n2;
	n2.status = DECIMAL;
	n2.type.dec = 0.250;
	
	printNumber(&n2);
	printf(" = ");
	
	struct _number result1 = addNumber(&n1,&n2);
	printNumber(&result1);
	
	printLines(4);
	
	/** Decimal */
	struct _number n3;
	n3.status = DECIMAL;
	n3.type.dec = 0.4;
	
	printNumber(&n3);
	printf(" + ");
	
	struct _number n4;
	n4.status = RATIONAL;
	n4.type.rat.n = 3;
	n4.type.rat.d = 5;
	
	printNumber(&n4);
	printf(" = ");
	
	struct _number result2 = subNumber(&n3,&n4);
	printNumber(&result2);
	
	printLines(3);
	printf("Attempting to convert results to rational format...\n");
	printLines(3);
	
	convertToRational(&result1);
	convertToRational(&result2);
	printNumber(&result1);
	printLines(1);
	printNumber(&result2);
	
	printLines(3);
	
	printf("%f =?= %f --> ", ((double) -1 / (double) 5), 0.200000);
	if ((0.2000 == 0.200000) && (((double) -1 / (double) 5) == -.2000000)) {
		printf("TRUE\n");
	} else {
		printf("FALSE\n");
	}
	
	printLines(3);
	
	
	
	/** Rational->Decimal + Decimal */
	// ...
	
	
	return EXIT_SUCCESS;
}
