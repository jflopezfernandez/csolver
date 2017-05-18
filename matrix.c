#include "includes\Main.h"

/** Stack-allocated matrix structure
 *  Notes: all elements initialized to zero by default using createZeroNumberStruct() function in Number.h
 */

/*
struct _matrix* createMatrix() {
	struct _matrix *newMatrix = malloc(sizeof(struct _matrix));
	
	struct _number zeroElement = createZeroNumberStruct();
	setMatrix(newMatrix, &zeroElement);
	
	return newMatrix;
}
*/
/** Dynamic allocation of matrix structure on the heap */
/*struct _matrix* createMatrix();
*/

/** Heap-allocated identity matrix */
/*struct _matrix* createIdentityMatrix() {
	struct _matrix *m = malloc(sizeof(struct _matrix));
	
	struct _number one_ = newNumber(1,1);
	struct _number zero = newNumber(0,1);
	
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			if (i == j) {
				m->m[i][j] = one_;
			} else {
				m->m[i][j] = zero;
			}
		}
	}
	
	return m;
}
*/

/** Function to allow user to enter matrix by row
 *  Notes: function assumes no fractional values need to be entered;
 *         all values entered are then internally converted to number structures
 */
/*
void enterMatrixByRow(struct _matrix *m) {
	int a;
	
	for (int i = 0; i < DIMENSION; ++i) {
		printf("Enter row %i: ", i + 1);
		for (int j = 0; j < DIMENSION; ++j) {
			scanf("%i", &a);
			struct _number n = convertToNumber(a);
			m->m[i][j] = n;
		}
		printf("\n");
	}
}
*/

/** Sets entire matrix to single number structure */
/*
void setMatrix(struct _matrix *m, struct _number *n) {
	for (int i = 0; i < DIMENSION; ++i) {
		for (int j = 0; j < DIMENSION; ++j) {
			m->m[i][j] = *n;
		}
	}
}
*/

/** Set entire matrix programmatically */
/*
void setMatrixProgrammatically(struct _matrix *m, 	struct _number *n00, struct _number *n01, struct _number *n02,
													struct _number *n10, struct _number *n11, struct _number *n12,
													struct _number *n20, struct _number *n21, struct _number *n22) {
	
	m->m[0][0].n = n00->n; 	m->m[0][1].n = n01->n; 	m->m[0][2].n = n02->n;
	m->m[0][0].d = n00->d; 	m->m[0][1].d = n01->d; 	m->m[0][2].d = n02->d;
	
	m->m[1][0].n = n10->n; 	m->m[1][1].n = n11->n; 	m->m[1][2].n = n12->n;
	m->m[1][0].d = n10->d; 	m->m[1][1].d = n11->d; 	m->m[1][2].d = n12->d;
	
	m->m[2][0].n = n20->n; 	m->m[2][1].n = n21->n; 	m->m[2][2].n = n22->n;
	m->m[2][0].d = n20->d; 	m->m[2][1].d = n21->d; 	m->m[2][2].d = n22->d;
	
}
*/

/** Print function for matrix */
/*
void printMatrix(struct _matrix *m) {
	printf("   ");
	
	for (int k = 0; k < (DIMENSION * 8); ++k) {
		printf("-");
	}
	
	printLines(2);
	
	for (int i = 0; i < DIMENSION; ++i) {
		printf(" |");
		
		for (int j = 0; j < DIMENSION; ++j) {
			printRationalNumber(&(m->m[i][j]));
			printf("  |");
		}
		
		printLines(2);
	}
	
	printf("   ");
	for (int k = 0; k < (DIMENSION * 8); ++k) {
		printf("-");
	}
}
*/
/** Void function to free passed-in matrix structure */
/*
void freeMatrix(struct _matrix *m) {
	free(m);
}
*/

/** -------------- USER FUNCTIONS --------------- */
/*
void matrix() {
	struct _matrix *m = createMatrix();
	enterMatrixByRow(m);
	printMatrix(m);
}
*/

/*
void imatrix() {
	struct _matrix *i = createIdentityMatrix();
	printMatrix(i);
	
	freeMatrix(i);
}
*/
