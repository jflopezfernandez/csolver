#include "includes\Main.h"


/** Function to row-reduce matrix using Gauss-Jordan elimination */
void reduceMatrix(struct _matrix *m, struct _matrix *i);

/** Get Needed value function determines whether the needed value is a 1 or a 0, depending on where in the matrix
 *  it is.
 */

int getNeededValue(int a, int b) {
	if (a == b)
		return 1;
	else
		return 0;
}

/** These functions find the complement of the specified number, depending on whether they are looking for a one or a zero, as determined by the getNeededValue function
 *
 *  Notes: The first function takes only one parameter because the inverse is the only necessary number to get it to one. In contrast, the get zero, a linear combination
 *  of the available factors may be needed to get a zero using elementary row operations/linear combinations, so more information is needed
 */

struct _number findComplementOne_(struct _number *n) {
	struct _number result;
	
	// Check to see if fraction is negative
	if (n->n < 0) {
		result.n = -(n->d);
		result.d = -(n->n);
	} else if (n->n == 0) {
		printf("[Error] No multiplicative complement to make 1\n");
	} else {
		result.n = n->d;
		result.d = n->n;
	}
	
	return result;
}

struct _number findComplementZero(struct _number *m, struct _number *n) {
	struct _number result;
	
	// If both numbers are positive, we will have to multiply by a negative
	if ((m->n > 0) && (n->n > 0)) {
		// Both positive
		printf("Both numbers are positive.\n");
	} else if (n->n < 0) {
		// Target number is negative
		if (m->n < 0) {
			// Both numbers are negative
			printf("Both numbers are negative.\n");
		} else {
			// Target number is negative, current number is positive
			printf("Target is negative, current is positive.\n");
		}
	} else {
		// Target number is positive, current number is negative
		printf("Target is positive, current is negative.\n");
	}
	
	return result;
}


/** Having found the necessary complement, this function carries out the operation on both the matrix and its complementary identity matrix */
struct _number carryOutOperation(struct _matrix *m, struct _matrix *i, struct _number *n) {
	int valNeeded = getNeededValue(0,0);
	struct _number operation;
	
	if (valNeeded == 1)
		operation = findComplementOne_(n);
	else
		operation = findComplementZero(m, n);
}
