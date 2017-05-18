# csolver
C Program to solve systems of linear equations

This is a side-project I'm working on to solve systems of linear equations using a matrix system. The first feature I'm working on implementing is matrix row reduction using Gauss-Jordan elimination. So far the matrices can be arbitrary sizes, but that's a compile-time implementation using macro definitions. Eventually I'm going to implement the feature as a run-time component using dynamic-memory allocation. For now, recompilation of the program for different sized matrices isn't too much of a hassle though, since the executable is 64kb and a makefile is used to speed up compilation.

There are no OS dependencies. The standard C library is the only thing used, but I do use the C99 standard, not ANSI C, so a "newer" C compiler is required.
