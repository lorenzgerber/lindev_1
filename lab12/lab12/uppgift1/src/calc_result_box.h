/*
 * @file calc_result_box.h
 *
 * @author Lorenz Gerber
 * @date 06.08.2017
 * @brief Header for lower GUI part of electrotestgtk application.
 *
 */
#ifndef CALC_RESULT_BOX_H_
#define CALC_RESULT_BOX_H_

#include <gtk/gtk.h>
#include "electrotestgtk.h"

/**
 * @brief Constructor of the lower GUI part.
 *
 * This part of the GUI contains the calculation button and
 * the result boxes.
 *
 * @param gui A struct that contains pointers to all gui parts and to the
 * array which contains the resistor values.
 * @return calc_result_box The constructed and wired GUI part
 *
 */
extern GtkWidget* calc_result_box_new(struct gui_comp* gui);

#endif /* CALC_RESULT_BOX_H_ */
