#include <stdio.h>
#include <stdlib.h>

int main(void){
  int sum = 0;
  char *input;
  int status = 0;
  char line[11] = "0";

  
  while (line[0] != '\n'){
    input = fgets(line, 10, stdin);
    sum += atoi(input);
  }

  printf("%d\n", sum);

  return 0;
}
