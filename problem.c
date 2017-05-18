#include "includes\Main.h"


/** Function to print matrix alongside its complemenatary identity matrix */
void printMatrixAndId(struct _matrix *m1, struct _matrix *m2) {
	for (int i = 0; i < DIMENSION; ++i) {
		
		/** Matrix 1 */
		for (int j = 0; j < DIMENSION; ++j) {
			printRationalNumber(&(m1->m[i][j]));
		}
		
		printf("   |   ");
		
		/** Matrix 2 */
		for (int k = 0; k < DIMENSION; ++k) {
			printRationalNumber(&(m2->m[i][k]));
		}
		
		printLines(2);
	}
}
