#ifndef _NUMBER_H
#define _NUMBER_H

struct _number {
	int n; 		// Numerator
	int d; 		// Denominator
};

/** Creating number structure on the stack */
struct _number newNumber(int a, int b);

/** Dynamic memory allocation of number structure on the heap */
struct _number* createNumber(int a, int b);

/** Function that returns zero struct used during matrix creation
 *  Notes: Still haven't decided if the structs should be stack or heap-allocated
 *  (implemented on stack for now)
 */

struct _number createZeroNumberStruct();

/** Converts passed in integer to number structure - assumes whole numbers with no fractional parts */
struct _number convertToNumber(int a);

/** Add Number */
struct _number addNumber(struct _number *a, struct _number *b);

/** Subtract Number */
struct _number subNumber(struct _number *a, struct _number *b);

/** Multiply Number */
struct _number mulNumber(struct _number *a, struct _number *b);

/** Divide Number */
struct _number divNumber(struct _number *a, struct _number *b);

/** Function to simplify fractions based on GCD */
void simplifyNumber(struct _number *n);


/** Function to print the number using printf function */
void printNumber(struct _number *n);



#endif // _NUMBER_H
