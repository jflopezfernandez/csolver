#ifndef _MAIN_H
#define _MAIN_H

#define DIMENSION 3

#define DEBUG 1

#if DEBUG
	#include "COMPILATION_AND_DEBUG_SETTINGS.h"
#endif


/** C Library Headers */
#include <stdio.h>
#include <stdlib.h>


/** Application Headers */
#include "Utils.h"
#include "Number.h"

#if MAIN_SOLO
	// Do nothing
#else
	#include "Matrix.h"
	#include "Solver.h"
	#include "Problem.h"
#endif


#endif // _MAIN_H
