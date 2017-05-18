CC=gcc
OUTPUT=-o csolver.exe
CFLAGS=-c -g
OBJS=main.o number.o utils.o matrix.o solver.o problem.o

all: csolver.exe

#csolver.exe: $(OBJS)
#	$(CC) $(OUTPUT) $(OBJS)

csolver.exe: main.o number.o utils.o
	$(CC) $(OUTPUT) main.o number.o utils.o
	
main.o: main.c
	$(CC) $(CFLAGS) main.c
	
number.o: number.c
	$(CC) $(CFLAGS) number.c

#matrix.o: matrix.c
#	$(CC) $(CFLAGS) matrix.c

#solver.o: solver.c
#	$(CC) $(CFLAGS) solver.c

#problem.o: problem.c
#	$(CC) $(CFLAGS) problem.c

utils.o: utils.c
	$(CC) $(CFLAGS)  utils.c