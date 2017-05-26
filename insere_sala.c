void insere_sala(char *sala, Next_exame lista_exames, Next_exame exame) {
  printf("Entrou na funcao insere_sala.\nVai inserir a sala %s no exame %d.\n", sala, exame->id);
  Next_sala l_salas = exame->salas;
  printf("ola\n");
  while (l_salas->next != NULL) {
    l_salas = l_salas->next;
  }
  printf("Ola2\n");
  //l_salas->next = NULL
  l_salas->next = (Next_sala)malloc(sizeof(Node_sala));
  printf("ola3\n");
  l_salas->next->sala = sala;
  printf("sala: %s\n", l_salas->next->sala);
  l_salas->next->next = NULL;

  update_ficheiro_salas(lista_exames);
}
