/*
 * @file coupling_box.h
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief Header GUI part to choose type of Resistor coupling
 * from electrotestgtk application.
 *
 */
#ifndef COUPLING_BOX_H_
#define COUPLING_BOX_H_

#include <gtk/gtk.h>

/**
 * @brief Constructor for the Resistor Coupling Gui part
 *
 * The Resistor coupling GUI part allows to choose between serial/parallel
 * coupling of the resistors.
 *
 * @return GtkWidget* pointer to the new created Gui part.
 *
 */
extern GtkWidget* coupling_box_new(void);

/**
 * @brief Getter for mode of resistor coupling
 *
 * Function that queries the selected resitor coupling mode
 * in the gui and returns 1 for serial and 0 for parallel.
 *
 * @return 1 = serial, 0 = parallel
 */
extern int get_coupling(GtkWidget* coupling_box);

#endif /* COUPLING_BOX_H_ */
