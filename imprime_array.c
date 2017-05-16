#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void imprime_array(char *string) { //recebe ponteiro para primeiro elemento do array
  char *ptr, *endptr;
  int size;

  size = strlen(string);
  endptr = string + size;

  for (ptr=string; ptr<=endptr; ptr++) {
    printf("%c", *ptr);
  }
}
