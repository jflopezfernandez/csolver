/** CSOLVER: Program to solve systems of linear equations in C
 *  Author: Jose Lopez
 *  License: The Unlicense
 */


#include "includes\Main.h"


int main()
{
	initializeProgram();
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			struct _number n = newNumber(i,j);
			printNumber(&n);
			printLines(1);
		}
	}
	
	
	return EXIT_SUCCESS;
}
