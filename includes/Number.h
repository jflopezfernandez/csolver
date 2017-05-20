#ifndef _NUMBER_H
#define _NUMBER_H


#define RATIONAL_CONVERSION_PRECISION_LIMIT 20



struct _rational {
	//enum _numvalue value;
	
	int n; 		// Numerator
	int d; 		// Denominator
};

enum _numtype { RATIONAL, DECIMAL };
enum _numstat { NEGATIVE = -1, ZERO = 0, POSITIVE = 1 };

union _type {
	struct _rational rat;
	double dec;
};

struct _number {
	enum _numtype 	status;
	enum _numstat 	absval; 		// This is determined via a function, not programmatically
	union _type 	type;
};

/** By reference pass to allow quick value editing */
void modifyRationalNumberElement(struct _rational *r, int element, int value);

/** Determines whether number is negative, positive, or zero */
void testNumber(struct _number *n);

/** Generic function to print number structure data type. Function determines whether number is rational or decimal and takes action accordingly. */
void printNumber(struct _number *n);

/** Creating number structure on the stack */
struct _number newNumber(int status, int a, int b, double c);

/** Dynamic memory allocation of number structure on the heap */
struct _number* createNumber(int status, int a, int b, double c);

/** Function that returns zero struct used during matrix creation
 *  Notes: Still haven't decided if the structs should be stack or heap-allocated
 *  (implemented on stack for now)
 */

struct _number createZeroNumberStruct();

/** Converts passed in integer to number structure - assumes whole numbers with no fractional parts */
struct _number convertToNumber(int a);

/** Converts passed in integer to number structure pointer; also assumes whole numbers with no fractional parts */
struct _number* convertToPNumber(int a);

/** Function to convert rational numbers to decimal form */
void convertToDecimal(struct _number *n);

/** Function to convert decimal numbers to rational form */
void convertToRational(struct _number *n);

/** Add Number */
struct _number addNumber(struct _number *a, struct _number *b);

/** Subtract Number */
struct _number subNumber(struct _number *a, struct _number *b);

/** Multiply Number */
struct _number mulNumber(struct _number *a, struct _number *b);

/** Divide Number */
struct _number divNumber(struct _number *a, struct _number *b);

/** Function to simplify fractions based on GCD */
void simplify(struct _number *n);


/** Function to print the number using printf function */
void printRationalNumber(struct _number *n);


/** GCD function that returns number structure */
struct _number getNumberGCD(int a, int b);

/** Need a copy constructor pls */
void setEqualTo(struct _number *a, struct _number *b);

/** Get number status */
void getNumberStatus(struct _number *n);

/** Returns true if both are rational and equivalent or false if not */
int testForEquality(struct _number *a, struct _number *b);


#endif // _NUMBER_H
