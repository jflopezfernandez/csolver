#ifndef _SOLVER_H
#define _SOLVER_H


/** Function to row-reduce matrix using Gauss-Jordan elimination */
void reduceMatrix(struct _matrix *m, struct _matrix *i);

/** Get Needed value function determines whether the needed value is a 1 or a 0, depending on where in the matrix
 *  it is.The function takes in the element position as parameters and returns 1 or 0 accordingly.
 */

int getNeededValue(int a, int b);

/** These functions find the complement of the specified number, depending on whether they are looking for a one or a zero, as determined by the getNeededValue function
 *
 *  Notes: The first function takes only one parameter because the inverse is the only necessary number to get it to one. In contrast, the get zero, a linear combination
 *  of the available factors may be needed to get a zero using elementary row operations/linear combinations, so more information is needed
 */

struct _number findComplementOne_(struct _number *n);
struct _number findComplementZero(struct _number *m, struct _number *n);


/** Having found the necessary complement, this function carries out the operation on both the matrix and its complementary identity matrix */
struct _number carryOutOperation(struct _matrix *m, struct _matrix *i, struct _number *n);

#endif // _SOLVER_H
