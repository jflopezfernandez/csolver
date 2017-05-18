/** CSOLVER: Program to solve systems of linear equations in C
 *  Author: Jose Lopez
 *  License: The Unlicense
 */



#include "includes\Main.h"


int main()
{
	initializeProgram(DIMENSION);
	
	/*
	struct _number n1 = newNumber(-1, 2);
	struct _number n2 = newNumber( 0, 1);
	struct _number n3 = newNumber( 0, 1);
	
	struct _number n4 = newNumber( 3, 1);
	struct _number n5 = newNumber( 1, 1);
	struct _number n6 = newNumber( 0, 1);
	
	struct _number n7 = newNumber( 0, 1);
	struct _number n8 = newNumber( 0, 1);
	struct _number n9 = newNumber( 1, 1);
	
	struct _matrix *m = createMatrix();
	struct _matrix *i = createIdentityMatrix();
	
	setMatrixProgrammatically(m, &n1, &n2, &n3,
								 &n4, &n5, &n6,
								 &n7, &n8, &n9);
	printLines(2);
	printMatrixAndId(m,i);
	reduceMatrix(m,i);
	*/
	

	/*
	struct _number {
		//enum _numvalue value;
		
		int n; 		// Numerator
		int d; 		// Denominator
	};

	enum _numtype { RATIONAL, DECIMAL };
	enum _numstat { NEGATIVE = -1, ZERO = 0, POSITIVE = 1 };

	union _type {
		struct _number rat;
		double dec;
	};


	struct _num {
		enum _numtype 	status;
		enum _numstat 	absval;
		union _type 	type;
	};

	void printNum(struct _num *n) {
		if (n->status == DECIMAL) {
			printf("%f", n->type.dec);
		} else if (n->status == RATIONAL) {
			printNumber(&(n->type.rat));
		}
	}
	*/
	
	struct _num n1;
	n1.status = 0;
	n1.type.rat.n = 1;
	n1.type.rat.d = 2;
	
	printNum(&n1);
	
	struct _num n2;
	n2.status = 0;
	n2.type.rat.n = -1;
	n2.type.rat.d =  1;
	
	printNum(&n2);
	
	struct _num n3;
	n3.status = 1;
	n3.type.dec = 1.618;
	
	printNum(&n3);
	
	return EXIT_SUCCESS;
}
