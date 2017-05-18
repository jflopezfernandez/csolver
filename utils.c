#include "includes\Main.h"

/** Euclidean Algorithm for finding the Greatest Common Denominator */

int getGCD(int m, int n) {
	if ((m == 0) || (n == 0))
		return 1;
	
	int remainder = m % n;
	
	while (remainder != 0) {
		m = n;
		n = remainder;
		
		remainder = m % n;
	}
	
	return n;
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

void initializeProgram() {
	clearScreen();
	printCompilationInfo();
	printCStdVersion();
	printLines(2);
}
