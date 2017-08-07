/*
 * @file electrotestgtk.h
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief Header of GUI application for electrotest library.
 *
 */
#ifndef ELECTROTESTGTK_H_
#define ELECTROTESTGTK_H_

#include  <gtk/gtk.h>

/**
 * @brief Struct with pointers to all gui and data parts
 *
 * The struct contains pointers to the three GtkWidget gui
 * parts and the float array that contains the current resistor
 * values.
 */
struct gui_comp {
	GtkWidget* voltage_box;
	GtkWidget* coupling_box;
	GtkWidget* resistor_box;
	GtkWidget* calc_result_box;
	float* resistor_values;
};


#endif /* ELECTROTESTGTK_H_ */
