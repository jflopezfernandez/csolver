#ifndef _PROBLEM_H
#define _PROBLEM_H

struct _dualmatrixsystem {
	struct _matrix *m1;
	struct _matrix *m2;
};

/** Function that starts the program, allowing user to enter matrix information, etc. */
struct _dualmatrixsystem* initializeProblem();

/** Function to print matrix alongside its complemenatary identity matrix */
void printMatrixAndId(struct _matrix *m1, struct _matrix *m2);

/** Free DMS */
void freeDMS(struct _dualmatrixsystem *dms);

#endif // _PROBLEM_H
