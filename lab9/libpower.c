/**
 * @file libpower.c
 *
 * @author Lorenz Gerber
 * @date 31.10.2016
 * @brief dynamic library for calculating power from resistance or current.
 *
 */

#include "libpower.h"


/**
 * 
 * @brief function to calculate power from voltage and resistance
 *
 * The function calculates power in watt according to the formula volt^2/resistance
 *
 * @param volt float, Voltage in volt
 * @param resistance float, Resistance in ohm
 * @return power float, Power in watt
 *
 */
float calc_power_r(float volt, float resistance)
{
  if(volt == 0 || resistance == 0){
    fprintf(stderr, "Please enter non-negative values for volt and resistance");
    exit(EXIT_FAILURE);
  }
  
  float power;
  power = (volt * volt) / resistance;
  return power;
}

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
float calc_power_i(float volt, float current)
{
  if(volt == 0 | current == 0){
    fprintf(stderr, "Please enter non-negative values for volt and current");
    exit(EXIT_FAILURE);
  }
  
  float power;
  power = volt * current;
  return power;

}
