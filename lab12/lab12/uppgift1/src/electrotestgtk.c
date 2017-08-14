/*
 * @file electrotestgtk.c
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief Main of GUI application for electrotest library.
 *
 */
#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include "electrotestgtk.h"
#include "voltage_box.h"
#include "resistor_box.h"
#include "coupling_box.h"
#include "calc_result_box.h"
#include "helper_functions.h"
#include <resistance.h>
#include <power.h>
#include <component.h>
#include "linumtest.h"


void test_button_clicked (GtkWidget *test_button, gpointer* data) {

	GdkColor color_green;
	gdk_color_parse ("green", &color_green);
	GdkColor color_red;
	gdk_color_parse ("red", &color_red);



	if(bTestElectricFunctions(TRUE)){
		gtk_widget_modify_bg (GTK_WIDGET(test_button),GTK_STATE_NORMAL, &color_green);
		gtk_widget_modify_bg (GTK_WIDGET(test_button),GTK_STATE_PRELIGHT, &color_green);
	} else {
		gtk_widget_modify_bg (GTK_WIDGET(test_button), GTK_STATE_NORMAL, &color_red);
		gtk_widget_modify_bg (GTK_WIDGET(test_button), GTK_STATE_PRELIGHT, &color_red);
	}


}


/**
 * @brief closeApp callback function
 *
 * Function to close main GTK application window.
 *
 * @param window, pointer to the main window widget
 * @param data, pointer for extra data, not used
 */
void closeApp ( GtkWidget *window, gpointer data ) {
  gtk_main_quit();
}


/**
 * @brief Main of electrotestgtk Application
 *
 * Application GTK+ gui frontend for electrotest libraries.
 * The Main file constructs the GUI by calling the three respective
 * constructor functions. Interfacing to the libraries happens
 * mostly in the calc_results_box gui part. Currently the application
 * does not implement advanced user input validation and relies on
 * the functionality in the libraries.  *
 */
gint main (gint argc, gchar *argv[]) {

	GtkWidget *window;
	GtkWidget *global_vbox;
	GtkWidget *upper_left_vbox;
	GtkWidget *upper_hbox;
	GtkWidget *test_button;
	GtkWidget *data = NULL;

	struct gui_comp gui;
	struct gui_comp* gui_pt = &gui;
	gfloat resistor_values[3] = {1, 1, 1};

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Electrotest");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),400, 250);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);

	global_vbox = gtk_vbox_new(FALSE, 5);

	gui.voltage_box = voltage_box_new();
	gui.coupling_box = coupling_box_new();
	gui.resistor_box = resistor_box_new();
	gui.calc_result_box = calc_result_box_new(gui_pt);
	gui.resistor_values = resistor_values;

	upper_left_vbox = gtk_vbox_new(FALSE, 5);
	gtk_container_add(GTK_CONTAINER(upper_left_vbox), gui.voltage_box);
	gtk_container_add(GTK_CONTAINER(upper_left_vbox), gui.coupling_box);

	upper_hbox = gtk_hbox_new(FALSE, 5);
	gtk_container_add(GTK_CONTAINER(upper_hbox),upper_left_vbox);
	gtk_container_add(GTK_CONTAINER(upper_hbox),gui.resistor_box);
	gtk_container_add(GTK_CONTAINER(global_vbox), upper_hbox);


    gtk_container_add(GTK_CONTAINER(global_vbox), gui.calc_result_box);
    gtk_container_add(GTK_CONTAINER(window), global_vbox);

    test_button = gtk_button_new_with_label("Test");
    gtk_container_add(GTK_CONTAINER(global_vbox), test_button);

	g_signal_connect(GTK_OBJECT(test_button), "clicked",
		   GTK_SIGNAL_FUNC(test_button_clicked), (gpointer *) data);

    g_signal_connect(G_OBJECT(window), "destroy",
          G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}

