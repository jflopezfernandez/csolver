/** CSOLVER: Program to solve systems of linear equations in C
 *  Author: Jose Lopez
 *  License: The Unlicense
 */



#include "includes\Main.h"


int main()
{
	initializeProgram(DIMENSION);
	
	struct _number n1;
	n1.status = RATIONAL;
	n1.type.rat.n = -1;
	n1.type.rat.d =  2;
	
	printNumber(&n1);
	printLines(2);
	
	convertToDecimal(&n1);
	printNumber(&n1);
	printLines(2);
	
	convertToRational(&n1);
	printNumber(&n1);
	printLines(2);
	
	
	return EXIT_SUCCESS;
}
