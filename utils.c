#include "includes\Main.h"

/** Euclidean Algorithm for finding the Greatest Common Denominator */

int getGCD(int m, int n) {
	if ((m == 0) || (n == 0))
		return 1;
	
	int r = m % n;
	
	while (r != 0) {
		m = n;
		n = r;
		
		r = m % n;
	}
	
	/** GCD should only be negative if both components are negative */
	if ((m < 0) && (n < 0)) {
		return n;
	} else if (n < 0) {
		return -n;
	} else {
		return n;
	}
}

void printCompilationInfo() {
	printf("Compiled on %s, at %s\n", __DATE__, __TIME__);
}

void printCStdVersion() {
	printf("C Standard Version: %i\n", __STDC_VERSION__);
}

void clearScreen() {
	system("cls");
}

void printLines(int n) {
	for (int i = 0; i < n; ++i) {
		printf("\n");
	}
}

void printDimension(int a) {
	printf("Matrix Dimension: %i\n", a);
}

void initializeProgram(int a) {
	clearScreen();
	printCompilationInfo();
	printCStdVersion();
	printLines(2);
	printDimension(a);
	printLines(3);
}
