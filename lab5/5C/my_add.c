#include <stdio.h>
#include <stdlib.h>

int add(void){

  
  int sum = 0;
  char *input;
  char line[11] = "0";

  
  while (line[0] != '\n'){
    input = fgets(line, 10, stdin);
    sum += atoi(input);
  }

  return sum;
}
