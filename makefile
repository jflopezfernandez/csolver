CC=gcc
OUTPUT=-o csolver.exe
CFLAGS=-c -g
OBJS=main.o number.o utils.o matrix.o

all: csolver.exe

csolver.exe: $(OBJS)
	$(CC) $(OUTPUT) $(OBJS)
	
main.o: main.c
	$(CC) $(CFLAGS) main.c
	
number.o: number.c
	$(CC) $(CFLAGS) number.c

matrix.o: matrix.c
	$(CC) $(CFLAGS) matrix.c

utils.o: utils.c
	$(CC) $(CFLAGS)  utils.c