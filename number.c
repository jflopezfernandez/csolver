#include "includes\Main.h"

/** Creating number structure on the stack */

struct _number newNumber(int a, int b) {
	struct _number newNumber;
	
	newNumber.n = a;
	newNumber.d = b;
	
	return newNumber;
}

/** Dynamic memory allocation of number structure on the heap */

struct _number* createNumber(int a, int b) {
	struct _number *newNumber = malloc(sizeof(struct _number));
	
	newNumber->n = a;
	newNumber->d = b;
	
	return newNumber;
}

/** Function to simplify fractions based on GCD */

void simplify(struct _number *n) {
	int g = getGCD(n->n, n->d);
	
	if (g > 1) {
		n->n /= g;
		n->d /= g;
	}
}

void printNumber(struct _number *n) {
	simplify(n);
	
	if (n->d != 0) {
		if (n->n == 0) {
			printf("%5i ", n->n);
		} else if (n->d == 1) {
			printf("%5i ", 0);
		} else {
			printf("%5i/%i ", n->n, n->d);
		}
	} else {
		printf("    NaN ");
	}
}
