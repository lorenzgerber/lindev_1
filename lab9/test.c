/**
 * @file test.c
 *
 * @author Lorenz Gerber
 * @date 31.10.2016
 * @brief Test program for the libpower library.
 *
 */

#include <stdio.h>
#include "libpower.h"

/**
 * @fn main 
 * this function is used to test the libpower library
 * 
 * This function does not take any command line argument.
 * @return int, the function returns zero on succes
 *
 */
int main(void){

  char userInput[10];
  float result;
  float volt; 
  float resistance;
  float current;

  do {

    printf("Make a choice:\n");
    printf("'I' - calculate P = U * I\n");
    printf("'R' - calculate P = U^2 / R\n\n");
    printf("'q' - quit\n");

    if(fgets(userInput, sizeof(userInput), stdin)==NULL){
      perror("fgets");
    }

    if(userInput[0] == 82){
      printf("Please enter voltage V\n");
      if(fgets(userInput, sizeof(userInput), stdin)==NULL){
	perror("fgets");
      }
      volt = atof(userInput);
      printf("Please enter resistance (Ohm):\n");

      if(fgets(userInput, sizeof(userInput), stdin)==NULL){
	perror("fgets");
      }
      resistance = atof(userInput);
      result = calc_power_r(volt, resistance);
      printf("\nResult:\n%4.2f^2 / %4.2f = %4.2f \n\n\n", volt, resistance, result);
    }

    if(userInput[0] == 73){

      printf("Please enter voltage V\n");

      if(fgets(userInput, sizeof(userInput), stdin)==NULL){
	perror("fgets");
      }
      volt = atof(userInput);
      printf("Please enter current (Ampere):\n");
      if(fgets(userInput, sizeof(userInput), stdin)==NULL){
	perror("fgets");
      }
      current = atof(userInput);
      result = calc_power_i(volt, current);
      printf("\nResult\n%4.2f / 2 / %4.2f = %4.2f \n\n\n", volt, resistance, result);
    }
  } while (userInput[0] != 113);
  
    

  return 0;
}
