#include "includes\Main.h"


/** Function that starts the program, allowing user to enter matrix information, etc. */
struct _dualmatrixsystem* initializeProblem() {
	struct _dualmatrixsystem *dms = malloc(sizeof(struct _dualmatrixsystem));
	
	struct _matrix *m1 = createMatrix();
	struct _matrix *m2 = createIdentityMatrix();
	
	dms->m1 = m1;
	dms->m2 = m2;
	
	printMatrixAndId(dms->m1,dms->m2);
	
	return dms;
}


/** Function to print matrix alongside its complemenatary identity matrix */
void printMatrixAndId(struct _matrix *m1, struct _matrix *m2) {
	for (int i = 0; i < DIMENSION; ++i) {
		
		/** Matrix 1 */
		for (int j = 0; j < DIMENSION; ++j) {
			printNumber(&(m1->m[i][j]));
		}
		
		printf("   |   ");
		
		/** Matrix 2 */
		for (int k = 0; k < DIMENSION; ++k) {
			printNumber(&(m2->m[i][k]));
		}
		
		printLines(2);
	}
}


/** Free DMS */
void freeDMS(struct _dualmatrixsystem *dms) {
	/** Free every matrix element */
	// ...
	
	/** Free every matrix */
	// ...
	
	/** Finally, free the dms */
	free(dms);
}
