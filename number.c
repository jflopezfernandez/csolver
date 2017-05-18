#include "includes\Main.h"

/*
struct _number {
	//enum _numvalue value;
	
	int n; 		// Numerator
	int d; 		// Denominator
};

enum _numtype { RATIONAL, DECIMAL };
enum _numstat { NEGATIVE = -1, ZERO = 0, POSITIVE = 1 };

union _type {
	struct _number rat;
	double dec;
};


struct _num {
	enum _numtype 	status;
	enum _numstat 	absval;
	union _type 	type;
};
*/

void printNum(struct _num *n) {
	if (n->status == DECIMAL) {
		printf("%f", n->type.dec);
	} else if (n->status == RATIONAL) {
		printNumber(&(n->type.rat));
	}
}

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
