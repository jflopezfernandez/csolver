#ifndef _MATRIX_H
#define _MATRIX_H

struct _matrix {
	struct _number m[DIMENSION][DIMENSION];
};

/** Stack-allocated matrix structure
 *  Notes: all elements initialized to zero by default using createZeroNumberStruct() function in Number.h
 */
/*
struct _matrix newMatrix();
*/

/** Dynamic allocation of matrix structure on the heap */
/*
struct _matrix* createMatrix();
*/
/** Heap-allocated identity matrix */
/*
struct _matrix* createIdentityMatrix();
*/
/** Sets entire matrix to single number structure */
/*
void setMatrix(struct _matrix *m, struct _number *n);
*/
/** Set entire matrix programmatically */
/*
void setMatrixProgrammatically(struct _matrix *m, 	struct _number *n00, struct _number *n01, struct _number *n02,
													struct _number *n10, struct _number *n11, struct _number *n12,
													struct _number *n20, struct _number *n21, struct _number *n22);
*/

/** Function to allow user to enter matrix by row
 *  Notes: function assumes no fractional values need to be entered;
 *         all values entered are then internally converted to number structures
 */
/*
void enterMatrixByRow(struct _matrix *m);
*/
/** Print function for matrix */
/*
void printMatrix(struct _matrix *m);
*/
/** Void function to free passed-in matrix structure */
/*
void freeMatrix(struct _matrix *m);
*/
/** -------------- USER FUNCTIONS --------------- */
/*
void matrix();
void imatrix();
*/
#endif // _MATRIX_H
