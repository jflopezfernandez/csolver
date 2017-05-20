#ifndef _SOLVER_H
#define _SOLVER_H

/** Data structure and functions used to check progress. When reduced == 1, the reduction process is finished, otherwise, the functions will use the x and y coordinates returned
 *  to keep going until finished.
 */

struct _progress {
	int reduced;
	int x;
	int y;
};

struct _linear_combination_solution {
	int solution_found;
	
	struct _number n1;
	struct _number n2;
	struct _number n3;
	
	struct _number c1;
	struct _number c2;
	struct _number c3;
};


/** Function to row-reduce matrix using Gauss-Jordan elimination */
void reduceMatrix(struct _matrix *m, struct _matrix *i);

/** Function to reduce immediate element */
void reduceElement(struct _matrix *m, struct _matrix *i, struct _number *n, struct _progress *p);

/** Get Needed value function determines whether the needed value is a 1 or a 0, depending on where in the matrix
 *  it is.The function takes in the element position as parameters and returns 1 or 0 accordingly.
 */

int getNeededValue(int a, int b);

/** These functions find the complement of the specified number, depending on whether they are looking for a one or a zero, as determined by the getNeededValue function
 *
 *  Notes: The first function takes only one parameter because the inverse is the only necessary number to get it to one. In contrast, the get zero, a linear combination
 *  of the available factors may be needed to get a zero using elementary row operations/linear combinations, so more information is needed
 */

struct _number findComplementOne_(struct _number *n);

/** We need a linear combination of the rows to generate a zero in these elements. One way to get them is to brute force the solution, which I'll do initially
 *  just to get a working prototype going.
 */

struct _linear_combination_solution* findComplementZero(struct _matrix *m, int x, int y);


/** Multiply matrices by passed-in number structure to obtain 1 */
void doMultiply(struct _matrix *m1, struct _matrix *m2, struct _number *n, struct _progress *p);


/** Add matrix row */
void doSum(struct _matrix *m1, struct _matrix *m2, struct _number *n, struct _progress *p);


/** Return only a pointer to the struct, not a copy of the whole thing */
struct _progress* checkProgress(struct _matrix *m, struct _matrix *r);


	#if DEBUG
		/** Function to print the contents of the progress structure for debug */
		void printP(struct _progress *p);
	#endif
	
		
/** Linear Combination Operations to get Zero */
void linearCombination(struct _matrix *m, struct _matrix *i, struct _linear_combination_solution *s, struct _progress *p);

#endif // _SOLVER_H
