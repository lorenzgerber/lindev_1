/*
 * @file resistor_box.c
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief GUI part to enter Resistor values
 * from electrotestgtk application.
 *
 */
#include <gtk/gtk.h>
#include <stdlib.h>
#include "helper_functions.h"
#include "resistor_box.h"

char* const resistor_names[] = { "res1", "res2", "res3" };
char* const resistor_labels[] = {"1:", "2:", "3:"};

/**
 * @brief Constructor for resistor_box GUI part
 *
 * This GUI part contains three resistor input field.
 *
 * @return GtkWidget Contains the constructed GUI part.
 */
GtkWidget* resistor_box_new(void){

	GtkWidget* upperrightvbox;
	GtkWidget* resistor_frame;

	upperrightvbox = gtk_vbox_new(FALSE, 5);


	for(int i = 0; i < 3; i++){
		add_widget_with_label_hbox(GTK_CONTAINER(upperrightvbox),
				resistor_labels[i],
				gtk_entry_with_name_new(resistor_names[i]));
	}

	resistor_frame = gtk_frame_new("Resistors (Ohm)");
	gtk_container_add(GTK_CONTAINER(resistor_frame), upperrightvbox);

	return resistor_frame;
}

/**
 * @brief Updates the value_array with values from the GUI
 *
 * The Function assumes a gfloat array of size 3.
 *
 * @param resistor_box The GUI part to access the user input.
 * @value_array Float array of size 3 that contains the resistor values
 */
gfloat* update_resistor_values(GtkWidget* resistor_box, gfloat *value_array){

	for(int i = 0; i < 3; i++){
		value_array[i] = (gfloat) atof(gtk_entry_get_text(
				GTK_ENTRY( (GtkWidget *) find_child(resistor_box, resistor_names[i]))));
	}

	return value_array;
}


