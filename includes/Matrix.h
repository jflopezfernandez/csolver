#ifndef _MATRIX_H
#define _MATRIX_H

#define DIMENSION 3

struct _matrix {
	struct _number m[DIMENSION][DIMENSION];
};

/** Stack-allocated matrix structure
 *  Notes: all elements initialized to zero by default using createZeroNumberStruct() function in Number.h
 */
struct _matrix newMatrix();

/** Dynamic allocation of matrix structure on the heap */
struct _matrix* createMatrix();

/** Print function for matrix */
void printMatrix(struct _matrix *m);

/** Void function to free passed-in matrix structure */
void freeMatrix(struct _matrix *m);

#endif // _MATRIX_H
