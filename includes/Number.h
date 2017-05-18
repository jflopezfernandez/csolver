#ifndef _NUMBER_H
#define _NUMBER_H

struct _number {
	int n;
	int d;
};


struct _number newNumber(int a, int b);
struct _number* createNumber(int a, int b);

/** Function that returns zero struct used during matrix creation
 *  Notes: Still haven't decided if the structs should be stack or heap-allocated
 *  TODO: Still needs implementation
 */

struct _number* createZeroNumberStruct();


void simplifyNumber(struct _number *n);
void printNumber(struct _number *n);

#endif // _NUMBER_H
