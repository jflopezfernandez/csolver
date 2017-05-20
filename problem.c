#include "includes\Main.h"


/** Function that starts the program, allowing user to enter matrix information, etc. */
struct _dualmatrixsystem* initializeProblem() {
	struct _dualmatrixsystem *dms = malloc(sizeof(struct _dualmatrixsystem));
	
	struct _matrix *m1 = createMatrix();
	
	#if DEBUG
		printf("[DEBUG MODE] Setting up %ix%i test matrix...\n", DIMENSION, DIMENSION);
		
		#if (DIMENSION == 2)		
			#if GO
				printf("Invertible matrix\n\n");
				
				struct _number n1 = newNumber(0,1,1,1);
				struct _number n2 = newNumber(0,2,1,1);
				struct _number n3 = newNumber(0,3,1,1);
				struct _number n4 = newNumber(0,4,1,1);
				
				m1->m[0][0] = n1; m1->m[0][1] = n2;
				m1->m[1][0] = n3; m1->m[1][1] = n4;
				
				printLines(2);
				printMatrix(m1);
				printLines(4);
			#elif ID
				printf("Identity matrix\n\n");
				
				struct _number n1 = newNumber(0,1,1,1);
				struct _number n2 = newNumber(0,0,1,1);
				struct _number n3 = newNumber(0,0,1,1);
				struct _number n4 = newNumber(0,1,1,1);
				
				m1->m[0][0] = n1; m1->m[0][1] = n2;
				m1->m[1][0] = n3; m1->m[1][1] = n4;
				
				printLines(2);
				printMatrix(m1);
				printLines(4);
			#else
				printf("Singular matrix\n\n");
				
				struct _number n1 = newNumber(0,1,1,1);
				struct _number n2 = newNumber(0,2,1,1);
				struct _number n3 = newNumber(0,2,1,1);
				struct _number n4 = newNumber(0,4,1,1);
				
				m1->m[0][0] = n1; m1->m[0][1] = n2;
				m1->m[1][0] = n3; m1->m[1][1] = n4;
				
				printLines(2);
				printMatrix(m1);
				printLines(4);
			#endif // GO / ID
		#elif (DIMENSION == 3)
			#if ID
				struct _number n1 = newNumber(0,1,1,1);
				struct _number n2 = newNumber(0,0,1,1);
				struct _number n3 = newNumber(0,0,1,1);
				struct _number n4 = newNumber(0,0,1,1);
				struct _number n5 = newNumber(0,1,1,1);
				struct _number n6 = newNumber(0,0,1,1);
				struct _number n7 = newNumber(0,0,1,1);
				struct _number n8 = newNumber(0,0,1,1);
				struct _number n9 = newNumber(0,1,1,1);
				
				m1->m[0][0] = n1; m1->m[0][1] = n2; m1->m[0][2] = n3;
				m1->m[1][0] = n4; m1->m[1][1] = n5; m1->m[1][2] = n6;
				m1->m[2][0] = n7; m1->m[2][1] = n8; m1->m[2][2] = n9;
				
				printLines(2);
				printMatrix(m1);
				printLines(4);
			#else
				#if TEST
					struct _number n1 = newNumber( 0,-2, 4, 1);
					struct _number n2 = newNumber( 0, 1, 1, 1);
					struct _number n3 = newNumber( 0, 1, 1, 1);
					struct _number n4 = newNumber( 0,-1, 1, 1);
					struct _number n5 = newNumber( 0, 1, 1, 1);
					struct _number n6 = newNumber( 0, 1, 1, 1);
					struct _number n7 = newNumber( 0, 1, 1, 1);
					struct _number n8 = newNumber( 0, 1, 1, 1);
					struct _number n9 = newNumber( 0, 1, 1, 1);
					
					m1->m[0][0] = n1; m1->m[0][1] = n2; m1->m[0][2] = n3;
					m1->m[1][0] = n4; m1->m[1][1] = n5; m1->m[1][2] = n6;
					m1->m[2][0] = n7; m1->m[2][1] = n8; m1->m[2][2] = n9;
					
					printLines(2);
					printMatrix(m1);
					printLines(4);
				#endif
			#endif // ID
		#endif // 2x2/3x3
	#endif
	
	struct _matrix *m2 = createIdentityMatrix();
	
	dms->m1 = m1;
	dms->m2 = m2;
	
	printMatrixAndId(dms->m1,dms->m2);
	reduceMatrix(dms->m1,dms->m2);
	
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
