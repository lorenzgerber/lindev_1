# Makefile
# Lorenz Gerber
CC=gcc
CFLAGS= -std=c11

all : program1

program1 : main.o a_functions.o b_functions.o c_functions.o d_functions.o
	$(CC) $(CFLAGS) -o program1 a_functions.o b_functions.o c_functions.o d_functions.o main.o

main.o : main.c
	$(CC) $(CFLAGS) -c main.c  

a_functions.o: a_functions.c a.h
	$(CC) $(CFLAGS) -c a_functions.c

b_functions.o: b_functions.c b.h
	$(CC) $(CFLAGS) -c b_functions.c 

c_functions.o: c_functions.c c.h
	$(CC) $(CFLAGS) -c c_functions.c

d_functions.o: d_functions.c d.h
	$(CC) $(CFLAGS) -c d_functions.c

install: 
	cp ./program1 /usr/bin/

uninstall: 
	rm /usr/bin/program1

clean:
	 rm -f rm *.o
