/*
 * @file voltage_box.c
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief Header of GUI part to enter voltage
 * from electrotestgtk application.
 *
 */
#ifndef VOLTAGE_BOX_H_
#define VOLTAGE_BOX_H_

#include <gtk/gtk.h>

/**
 * @brief Constructor for voltage_box GUI element
 *
 * Constructs the voltage_box GUI element which contains
 * the entry field for setting the voltage.
 *
 * @return GtkWidget A voltage_box GUI Element
 */
extern GtkWidget* voltage_box_new(void);

/**
 * @brief Retrieve voltage value from GUI entry field
 *
 * Retrieves float value of the voltage input box. The
 * function needs a reference/pointer to the GUI element.
 *
 * @param voltage_box GtkWidget GUI element voltage_box
 * @return float value of the current set voltage value in the GUI
 *
 */
extern float get_voltage(GtkWidget* voltage_box);



#endif /* VOLTAGE_BOX_H_ */
