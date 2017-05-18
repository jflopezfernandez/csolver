#include "includes\Main.h"


struct _matrix* createMatrix() {
	struct _matrix *newMatrix = malloc(sizeof(struct _matrix));
	
	return newMatrix;
}

void freeMatrix(struct _matrix *m) {
	free(m);
}

