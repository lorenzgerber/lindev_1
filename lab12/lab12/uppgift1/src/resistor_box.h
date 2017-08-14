/*
 * @file resistor_box.h
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief Header for GUI part to enter Resistor values
 * from electrotestgtk application.
 *
 */
#ifndef RESISTOR_BOX_H_
#define RESISTOR_BOX_H_

#include <gtk/gtk.h>

/**
 * @brief Constructor for resistor_box GUI part
 *
 * This GUI part contains three resistor input field.
 *
 * @return GtkWidget Contains the constructed GUI part.
 */
extern GtkWidget* resistor_box_new(void);

/**
 * @brief Updates the value_array with values from the GUI
 *
 * The Function assumes a gfloat array of size 3.
 *
 * @param resistor_box The GUI part to access the user input.
 * @value_array Float array of size 3 that contains the resistor values
 */
extern float* update_resistor_values(GtkWidget* resistor_box, float* value_array);

#endif /* RESISTOR_BOX_H_ */
