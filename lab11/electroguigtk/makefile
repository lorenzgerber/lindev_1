CC=gcc
CFLAGS= -Wall -std=c11 -pedantic -g

all: electrotestgtk

electrotestgtk: electrotestgtk.o voltage_box.o coupling_box.o resistor_box.o calc_result_box.o helper_functions.o
	$(CC) $(CFLAGS) -o electrotestgtk electrotestgtk.o voltage_box.o coupling_box.o resistor_box.o calc_result_box.o helper_functions.o -L/usr/lib -lresistance -lpower -lcomponent `pkg-config --cflags --libs gtk+-2.0`

electrotestgtk.o: electrotestgtk.c electrotestgtk.h voltage_box.h coupling_box.h resistor_box.h calc_result_box.h helper_functions.h
	$(CC) $(CFLAGS) -c electrotestgtk.c electrotestgtk.h voltage_box.h coupling_box.h resistor_box.h calc_result_box.h `pkg-config --cflags --libs gtk+-2.0`

voltage_box.o: voltage_box.c voltage_box.h helper_functions.h
	$(CC) $(CFLAGS) -c voltage_box.c voltage_box.h helper_functions.h `pkg-config --cflags --libs gtk+-2.0`

coupling_box.o: coupling_box.c coupling_box.h helper_functions.h
	$(CC) $(CFLAGS) -c coupling_box.c coupling_box.h helper_functions.h `pkg-config --cflags --libs gtk+-2.0`
	
resistor_box.o: resistor_box.c resistor_box.h helper_functions.h
	$(CC) $(CFLAGS) -c resistor_box.c resistor_box.h helper_functions.h `pkg-config --cflags --libs gtk+-2.0`
	
calc_result_box.o: calc_result_box.c calc_result_box.h helper_functions.h
	$(CC) $(CFLAGS) -c calc_result_box.c calc_result_box.h helper_functions.h `pkg-config --cflags --libs gtk+-2.0`

helper_functions.o: helper_functions.c helper_functions.h
	$(CC) $(CFLAGS) -c helper_functions.c helper_functions.h `pkg-config --cflags --libs gtk+-2.0`


clean:
	rm -f rm *.o *.so *.gch