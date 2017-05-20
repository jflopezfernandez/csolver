#ifndef _MAIN_H
#define _MAIN_H

#define DIMENSION 3

#define TRUE 	1
#define FALSE 	0

#define DEBUG 1

#if DEBUG
	#include "COMPILATION_AND_DEBUG_SETTINGS.h"
#endif

/** Debug macros */
#define STOP 	1
#define GO 		0
#define ID 		0
#define TEST 	1
#define PRINT 	0



/** C Library Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** Application Headers */
#include "Utils.h"
#include "Number.h"
#include "Matrix.h"
#include "Solver.h"
#include "Problem.h"


#endif // _MAIN_H
