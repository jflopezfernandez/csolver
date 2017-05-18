#include "includes\Main.h"


void printNumber(struct _number *n) {
	if (n->status == DECIMAL) {
		printf("%.4f", n->type.dec);
	} else if (n->status == RATIONAL) {
		printRationalNumber(&(n->type.rat));
	}
}


/** Creating number structure on the stack */

struct _number newNumber(int status, int type, int a, int b, double c) {
	struct _number newNumber;
	
	if (status == RATIONAL) {
		// Create rational
		newNumber.status = RATIONAL;
		
		newNumber.type.rat.n = a;
		newNumber.type.rat.d = b;
	} else {
		// Create decimal
		newNumber.status = DECIMAL;
		
		newNumber.type.dec = c;
	}
	
	return newNumber;
}


/** Dynamic memory allocation of number structure on the heap */
/*
struct _number* createNumber(int status, int type, int a, int b, double c) {
	struct _number *newNumber = malloc(sizeof(struct _number));
	
	if (status == RATIONAL) {
		// Create rational
		newNumber->status = RATIONAL;
		
		newNumber->type.rat.n = a;
		newNumber->type.rat.d = b;
	} else {
		// Create decimal
		newNumber->status = DECIMAL;
		
		newNumber->type.dec = c;
	}
	
	return newNumber;
}
*/


/** Function that returns zero struct used during matrix creation
 *  Notes: Still haven't decided if the structs should be stack or heap-allocated
 *  (implemented on stack for now)
 *
 *  Struct type is rational
 */

struct _number createZeroNumberStruct() {
	struct _number newNumber;
	
	newNumber.status = RATIONAL;
	
	newNumber.type.rat.n = 0;
	newNumber.type.rat.d = 1;
	
	return newNumber;
}

/** Converts passed in integer to number structure - assumes whole numbers with no fractional parts */

struct _number convertToNumber(int a) {
	struct _number newNumber;
	
	newNumber.status = RATIONAL;
	
	newNumber.type.rat.n = a;
	newNumber.type.rat.d = 1;
	
	return newNumber;
}



/** Add Number */

struct _number addNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	/** Check to see if both numbers are decimal or rational
	 *  Convert the rational number to decimal, perform operation, then convert back if possible.
	 *  If not, leave in decimal form.
	 */
	
	if (a->status == b->status) {
		if (a->status == DECIMAL) {
			// Perform float arithmetic
			// ...
		} else {
			// Perform rational arithmetic
		}
	} else {
		if (a->status == RATIONAL) {
			//convertNumberToDecimal(a);
			// Perform float arithmetic
			// ...
		} else {
			//convertNumberToDecimal(b);
			// Perform float arithmetic
			// ...
		}
	}
	
	/*
	if (a->d != b->d) {
		result.n = (a->n * b->d) + (b->n * a->d);
		result.d = a->d * b->d;
	} else {
		result.n = a->n + b->n;
		result.d = a->d;
	}*/
	
	//simplify(&result);
	return result;
}


/** Subtract Number */
/*
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
*/


/** Multiply Number */
/*
struct _number mulNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	result.n = a->n * b->n;
	result.d = a->d * b->d;
	
	simplify(&result);
	return result;
}
*/


/** Divide Number */
/*
struct _number divNumber(struct _number *a, struct _number *b) {
	struct _number result;
	
	result.n = a->n * b->d;
	result.d = a->d * b->n;
	
	return result;
}
*/


/** Function to simplify fractions based on GCD */
/*
void simplify(struct _number *n) {
	int g = getGCD(n->n, n->d);
	
	if (g > 1) {
		n->n /= g;
		n->d /= g;
	}
}
*/


/** Function to print the number using printf function */

void printRationalNumber(struct _rational *n) {
	//simplify(n);
	
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
