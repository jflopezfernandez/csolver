#include "includes\Main.h"


/** Function to row-reduce matrix using Gauss-Jordan elimination */
void reduceMatrix(struct _matrix *m, struct _matrix *i) {
	/** Create matrix to use for reference to verify matrix is reduced */
	struct _matrix *reference = createIdentityMatrix();
	
	/** Data structure for progress check */
	struct _progress *p = malloc(sizeof(struct _progress));
	p = checkProgress(m, reference);
	
	/** The number of elements traversed in the first column is DIMENSION ? */
	
	// Variable to force exit out of loop even if matrix is not yet reduced
	#if DEBUG
		#if STOP
			int count = 0;
		#endif
	#endif
	
	while (p->reduced != 1) {
		#if DEBUG
			#if STOP
				if (count == 10)
				break;
			#endif
		#endif
			
		/** This is where the reduction process loop will go
		 *  Step 1: Check progress
		 *  Step 2: If not finished, take x,y coordinates returned and reduce that element
		 *  Step 3: Repeat
		 */
			
		reduceElement(m, i, &(m->m[p->x][p->y]), p);
		p = checkProgress(m, reference);
		
		printP(p);
		printLines(3);
		
		printf(" \t---------------------------------- \n\n");
		printMatrixAndId(m,i);
		printf("\n \t---------------------------------- \n");
		
		printLines(4);
		
		#if DEBUG
			#if STOP
				++count;
			#endif
		#endif
	}
	
	printf("[END] Reduction completed...\n");
	
	printLines(3);
	printMatrixAndId(m,i);
}

/** Function to reduce immediate element */
void reduceElement(struct _matrix *m, struct _matrix *i, struct _number *n, struct _progress *p) {
	int val = getNeededValue(p->x,p->y);
	
	#if DEBUG
		printf("[%i][%i] - Needed value: %i\n", p->x, p->y, val);
	#endif
	
	struct _number operand;
	struct _linear_combination_solution *solution;
	
	/** Determine needed scalar value to convert to necessary value */
	if (val == 1) {
		operand = findComplementOne_(&(m->m[p->x][p->y]));
		
		printf("\n\nOperand: ");
		printNumber(&operand);
		printLines(3);
		
		doMultiply(m,i,&operand, p);
	} else {
		#if DEBUG
			printf("[%s]: passing in %i and %i\n", __func__, p->x, p->y);
		#endif
			
		solution = findComplementZero(m, p->x, p->y);
		
		if (solution->solution_found == TRUE)
			linearCombination(m,i,solution,p);
	}
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
	
	if (n->status == DECIMAL) {
		// Need to find multiplicative inverse for a decimal, if possible
		result.status = DECIMAL;
		
		#if DEBUG
			printf("[Error: %s] No decimal implementation!\n", __func__);
		#endif
		
	} else if (n->status == RATIONAL) {
		result.status = RATIONAL;
		
		// Check to see if fraction is negative
		if (n->type.rat.n < 0) {
			result.type.rat.n = -(n->type.rat.d);
			result.type.rat.d = -(n->type.rat.n);
		} else if (n->type.rat.n == 0) {
			printf("[Error] No multiplicative complement to make 1\n");
		} else {
			result.type.rat.n = n->type.rat.d;
			result.type.rat.d = n->type.rat.n;
		}
	} else {
		#if DEBUG
			printf("[Error: %s] No type!\n");
		#endif
	}
	
	return result;
}

/** We need a linear combination of the rows to generate a zero in these elements. One way to get them is to brute force the solution, which I'll do initially
 *  just to get a working prototype going.
 */

struct _linear_combination_solution* findComplementZero(struct _matrix *m, int x, int y) {
	#if DEBUG
		printf("[%s] Entering function...\n", __func__);
	#endif
		
	struct _linear_combination_solution *solution = malloc(sizeof(struct _linear_combination_solution));
	solution->solution_found = FALSE;
	
	solution->n1 = createZeroNumberStruct();
	solution->n2 = createZeroNumberStruct();
	solution->n3 = createZeroNumberStruct();
	
	solution->c1 = createZeroNumberStruct();
	solution->c2 = createZeroNumberStruct();
	solution->c3 = createZeroNumberStruct();
	
	#if PRINT
		printf("Solution: \n");
		printf("\t"); printNumber(&(solution->n1)); printf("\n");
		printf("\t"); printNumber(&(solution->n2)); printf("\n");
		printf("\t"); printNumber(&(solution->n3)); printf("\n");
	#endif
	
	if (m->m[x][y].status == RATIONAL) {
		if (m->m[x][y].type.rat.n < 0) {
			// Target is negative
			
			/** Brute force to find a linear combination that adds up to the target */
			for (int i = 1; i < DIMENSION * DIMENSION; ++i) {
				for (int j = 0; j < DIMENSION * DIMENSION; ++j) {
					for (int k = 0; k < DIMENSION * DIMENSION; ++k) {
						/** c1*m[0][0] + c2*m[1][0] + c3*m[2][0] --> target */
						
						int t = m->m[x][y].type.rat.n;
						printf("target: %i\n", t);
						
						
						struct _number coefficient1 = convertToNumber(k);
						struct _number coefficient2 = convertToNumber(j);
						struct _number coefficient3 = convertToNumber(i);
						
						struct _number r1 = mulNumber(&coefficient1,&(m->m[0][0]));
						struct _number r2 = mulNumber(&coefficient2,&(m->m[2][0]));
						struct _number r3 = mulNumber(&coefficient3,&(m->m[1][0]));
						
						struct _number s1 = addNumber(&r1,&r2); 
						struct _number s2 = addNumber(&s1,&r3); 
						
						#if PRINT
							printf("\nSum: ");
							printNumber(&s2);
							printLines(2);
						#endif
						
						struct _number ref;
						
						ref.status = RATIONAL;
						ref.type.rat.n = m->m[x][y].type.rat.n;
						ref.type.rat.d = m->m[x][y].type.rat.d;
						
						convertToDecimal(&s2);
						convertToDecimal(&ref);
						
						struct _number test;
						test.status = DECIMAL;
						test = subNumber(&s2, &ref);
						
						if (test.type.dec == 0) {
							#if DEBUG
								printf("[SUCCESS: %s] Solution found!\n", __func__);
							#endif
								
							solution->solution_found = TRUE;
							
							solution->n1 = coefficient1; solution->c1 = m->m[x+0][y];
							solution->n2 = coefficient2; solution->c2 = m->m[x+1][y];
							solution->n3 = coefficient3; solution->c3 = m->m[x+2][y];
							
							return solution;
						} else {
							
						}
					}
				}
			}
		} else {
			// Target is positive
		}
	} else if (m->m[x][y].status == DECIMAL) {
		// decimal stuff
		
		#if DEBUG
			printf("[Error: %s] Decimal not yet implemented!\n", __func__);
		#endif
			
	} else {
		#if DEBUG
			printf("[Error - %s] No status type!\n", __func__);
		#endif
	}
	
	/** Failure: */
	
	
	/*
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
	} else if (m->n == 0) {
		// Target number is positive, current number is zero
		printf("Target is positive, current is zero\n");
	} else {
		// Target is positive, current is negative
	}*/
	
	return solution;
}


/** Multiply matrices by passed-in number structure to obtain 1 */
void doMultiply(struct _matrix *m1, struct _matrix *m2, struct _number *n, struct _progress *p) {
	struct _number result1;
	struct _number result2;
	
	/** Multiply across the entire row of the matrix */
	for (int i = 0; i < DIMENSION; ++i) {
		result1 = mulNumber(&(m1->m[p->x][i]),n);
		result2 = mulNumber(&(m2->m[p->x][i]),n);
		
		printNumber(&(m1->m[p->x][i])); printf(" x "); printNumber(n); printf(" = "); printNumber(&result1); printLines(1);
		printNumber(&(m2->m[p->x][i])); printf(" x "); printNumber(n); printf(" = "); printNumber(&result2); printLines(3);
	}
	
	
	printf("Result1: "); printNumber(&result1); printLines(2);
	printf("Result2: "); printNumber(&result2); printLines(2);
	
	setEqualTo(&(m1->m[p->x][p->y]),&result1);
	setEqualTo(&(m2->m[p->x][p->y]),&result2);
	
}


/** Add matrix row */
void doSum(struct _matrix *m1, struct _matrix *m2, struct _number *n, struct _progress *p) {
	for (int i = 0; i < DIMENSION; ++i) {
		struct _number result1 = addNumber(&(m1->m[p->x][i]),n);
		struct _number result2 = addNumber(&(m2->m[p->x][i]),n);
	}
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


/** Return only a pointer to the struct, not a copy of the whole thing
 *  Important! C/C++ are naturally row-major so it's very important that this function analyzes the matrices in column-major form, as
 *  that is how it is done when using row reduction technique.
 */


struct _progress* checkProgress(struct _matrix *m, struct _matrix *r) {
	struct _progress *p = malloc(sizeof(struct _progress));
	p->reduced = 0;
	p->x = 0;
	p->y = 0;

	// TODO: Actually check progress
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			#if DEBUG
				printf("[%i][%i]\n", j, i);
			#endif
			
			p->x = j;
			p->y = i;
			
			if (m->m[j][i].status == RATIONAL) {
				if (m->m[j][i].type.rat.n == r->m[j][i].type.rat.n) {
					if (m->m[j][i].type.rat.d == r->m[j][i].type.rat.d) {
						// Do nothing; everything matched so far
					} else {
						// Mismatch
						p->reduced = 0;
						p->x = j;
						p->y = i;
							
						return p;
					} // end if (m->m[j][i].type.rat.d == r->m[j][i].type.rat.d)
				} else {
					p->reduced = 0;
					p->x = j;
					p->y = i;
						
					return p;
				} // end if (m->m[j][i].type.rat.n == r->m[j][i].type.rat.n)
			} else if (m->m[j][i].status == DECIMAL) {
				if (m->m[j][i].type.dec == r->m[j][i].type.dec) {
					// Do nothing; match
				} else {
					// Mismatch
				}
			} else {
				#if DEBUG
					printf("[Error: %s] No type assigned to number structure in matrix!\n");
				#endif
			} // end if (m->m[j][i].status == RATIONAL)
		} // end for [j]
	} // end for [i]
	
	p->reduced = 1;
	p->x = 0;
	p->y = 0;
	
	return p;
} // struct _progress* checkProgress(struct _matrix *m, struct _matrix *r)

#if DEBUG
	/** Function to print the contents of the progress structure for debug */

	void printP(struct _progress *p) {
		printf("\n\nProgress: \n");
		printf("\tReduced: %i\n", p->reduced);
		printf("\tX: %i\n", p->x);
		printf("\tY: %i\n\n\n", p->y);
	}

#endif
	

/** Linear Combination Operations to get Zero */
void linearCombination(struct _matrix *m, struct _matrix *i, struct _linear_combination_solution *s, struct _progress *p) {
	struct _number n1 = s->n1; // k
	struct _number n2 = s->n2; // j
	struct _number n3 = s->n3; // i
	
	struct _number c1 = s->c1; // m->m[x+0][y]
	struct _number c2 = s->c2; // m->m[x+2][y]
	struct _number c3 = s->c3; // m->m[x+1][y]
	
	
	if (n1.type.rat.n == 0) {
		if (n2.type.rat.n == 0) {
			// j,k = 0
			struct _number p1 = mulNumber(&n3,&c3);
			doSum(m,i,&p1,p);
		} else {
			// k = 0
			struct _number p1 = mulNumber(&n3,&c3);
			struct _number p2 = mulNumber(&n2,&c2);
			struct _number p3 = addNumber(&p1,&p2);
			
			doSum(m,i,&p3,p);
		}
	} else if (n2.type.rat.n == 0) {
		// j = 0
		
		struct _number p1 = mulNumber(&n3,&c3);
		struct _number p2 = mulNumber(&n1,&c1);
		
		struct _number r1 = addNumber(&p1,&p2);
		
		doSum(m,i,&r1,p);
	} else {
		// j,k,i =/= 0
		
		struct _number p1 = mulNumber(&n3,&c3);
		struct _number p2 = mulNumber(&n2,&c2);
		struct _number p3 = mulNumber(&n1,&c1);
		
		struct _number r1 = addNumber(&p1,&p2);
		struct _number r2 = addNumber(&r1,&p3);
		
		doSum(m,i,&r2,p);
	}
}
