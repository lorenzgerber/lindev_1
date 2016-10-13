# Makefile
# Lorenz Gerber
CC=gcc
CFLAGS= -std=c11

all: program1

program1: main.o a_functions.o b_functions.o c_functions.o d_functions.o
	$(CC) $(CFLAGS) -o program1 a_functions.o b_functions.o c_functions.o d_functions.o main.o

program1.o a_functions.o b_functions.o c_functions.o d_functions.o: a_functions.c a.h b_functions.c b.h c_functions.c c.h d_functions.c d.h main.c main.h
	$(CC) $(CFLAGS) -c -g a_functions.c b_functions.c c_functions.c d_functions.c main.c

clean:
	 rm -f rm *.o

