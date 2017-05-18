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


/** Function that returns zero struct used during matrix creation
 *  Notes: Still haven't decided if the structs should be stack or heap-allocated
 *  (implemented on stack for now)
 */

struct _number createZeroNumberStruct() {
	struct _number newNumber;
	
	newNumber.n = 0;
	newNumber.d = 1;
	
	return newNumber;
}

/** Converts passed in integer to number structure - assumes whole numbers with no fractional parts */
struct _number convertToNumber(int a) {
	struct _number newNumber;
	
	newNumber.n = a;
	newNumber.d = 1;
	
	return newNumber;
}


/** Add Number */
struct _number addNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	if (a->d != b->d) {
		result.n = (a->n * b->d) + (b->n * a->d);
		result.d = a->d * b->d;
	} else {
		result.n = a->n + b->n;
		result.d = a->d;
	}
	
	simplify(&result);
	return result;
}


/** Subtract Number */
struct _number subNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	if (a->d != b->d) {
		result.n = (a->n * b->d) - (b->n * a->d);
		result.d = a->d * b->d;
	} else {
		result.n = a->n - b->n;
		result.d = a->d;
	}
	
	simplify(&result);
	return result;
}


/** Multiply Number */
struct _number mulNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	result.n = a->n * b->n;
	result.d = a->d * b->d;
	
	simplify(&result);
	return result;
}


/** Divide Number */
struct _number divNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	result.n = a->n * b->d;
	result.d = a->d * b->n;
	
	return result;
}


/** Function to simplify fractions based on GCD */

void simplify(struct _number *n) {
	int g = getGCD(n->n, n->d);
	
	if (g > 1) {
		n->n /= g;
		n->d /= g;
	}
}

/** Function to print the number using printf function */

void printNumber(struct _number *n) {
	simplify(n);
	
	if (n->d != 0) {
		if (n->n == 0) {
			printf("%5i ", n->n);
		} else if (n->d == 1) {
			printf("%5i ", n->n);
		} else {
			printf("%5i/%i ", n->n, n->d);
		}
	} else {
		printf("    NaN ");
	}
}
