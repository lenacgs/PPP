//função que lê strings: ou seja, quando um dos campos de uma struct é um ponteiro para char, esta é a função que lê o que está a seguir ao ponteiro

void imprime_array(char *string) { //recebe ponteiro para primeiro elemento do array
  char *ptr, *endptr;
  int size;

  size = strlen(string);
  endptr = string + size - 1;

  for (ptr=string; ptr<=endptr; ptr++) {
    printf("%c", *ptr);
  }
}
