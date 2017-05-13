#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  int numberOfValues = argc - 1;
  int sum = 0;
  
  while(numberOfValues > 0){
    sum += atoi(argv[numberOfValues]);
    numberOfValues--;
  }

  printf("%d\n", sum);
  return 0;
}
