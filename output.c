#include <stdio.h>
#include <stdlib.h>

void printout(struct entry a, int x){
  switch(x){

  case 0:
    printf("+ %s\n", a.filename);
    break;

  case 1:
    printf("* %s\n", a.filename);
    break;

  case 2:
    printf("- %s\n", a.filename);
    break;

  case 3:
    printf("d %s\n", a.filename);
    break;

  case 4:
    printf("d- %s\n", a.filename);
    break;

  default:
    printf("Somethings broken!\n");

  }
}
  
