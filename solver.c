#include "includes\Main.h"


/** Function to row-reduce matrix using Gauss-Jordan elimination */
void reduceMatrix(struct _matrix *m, struct _matrix *i) {
	/** Create matrix to use for reference to verify matrix is reduced */
	struct _matrix *reference = createIdentityMatrix();
	
	/** Data structure for progress check */
	struct _progress *p = malloc(sizeof(struct _progress));
	p = checkProgress(m, reference);
	
	while (p->reduced != 1) {
		/** This is where the reduction process loop will go
		 *  Step 1: Check progress
		 *  Step 2: If not finished, take x,y coordinates returned and reduce that element
		 *  Step 3: Repeat
		 */
			
		reduceElement(m, i, &(m->m[p->x][p->y]), p);
		
		p = checkProgress(m, reference);
		
		#if DEBUG
			system("PAUSE");
		#endif
	}
	
	printf("[END] Reduction completed...\n");
	
	printLines(3);
	printMatrixAndId(m,i);
}

/** Function to reduce immediate element */
void reduceElement(struct _matrix *m, struct _matrix *i, struct _number *n, struct _progress *p) {
	int val = getNeededValue(p->x,p->y);
	
	struct _number operation;
	
	if (val == 1)
		operation = findComplementOne_(&(m->m[p->x][p->y]));
	else
		operation = findComplementZero(&(m->m[p->x][p->y]), &(m->m[p->x][(p->y)+1]));
}

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


/** Data structure and functions used to check progress. When reduced == 1, the reduction process is finished, otherwise, the functions will use the x and y coordinates returned
 *  to keep going until finished.
 */

/*
struct _progress {
	int reduced;
	int x;
	int y;
};
*/


/** Return only a pointer to the struct, not a copy of the whole thing */
struct _progress* checkProgress(struct _matrix *m, struct _matrix *r) {
	struct _progress *p = malloc(sizeof(struct _progress));

	// TODO: Actually check progress
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			if (m->m[i][j].n == r->m[i][j].n) {
				if (m->m[i][j].d == r->m[i][j].d) {
					// Do nothing; everything matched so far
				} else {
					p->reduced = 0;
					p->x = j;
					p->y = i;
					
					return p;
				}
			} else {
				p->reduced = 0;
				p->x = j;
				p->y = i;
				
				return p;
			}
		}
	}
	
	p->reduced = 1;
	p->x = 0;
	p->y = 0;
	
	return p;
}
