/**
 * @file libpower.h
 *
 * @author Lorenz Gerber
 * @date 31.10.2016
 * @brief dynamic library for calculating power from resistance or current.
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @brief function to calculate power from voltage and resistance     
 *
 * The function calculates power in watt according to the formula volt^2/resistance
 * @param volt float, Voltage in volt                                                                   
 * @param resistance float, Resistance in ohm                                                           
 * @return power float, Power in watt    
 */
float calc_power_r(float volt, float resistance);

/**
 *                                                                                
 * @brief function to calculate power from voltage and current                    
 *                                                                                
 * The function calculates power in watt according to the formula volt* current   
 *                                                                                
 * @param volt float, Voltage in volt                                              
 * @param current float, current in ampere                                      
 * @return power float, Power in watt                                              
 *                                                                                
 */
float calc_power_i(float volt, float current);
