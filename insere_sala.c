//quando queremos adicionar uma nova sala a um determinado exame, ou seja, escrever a sala no fim da linha que tem como id o id do exame em causa

void insere_sala(char *sala, Next_exame lista_exames, Next_exame exame) {
  Next_sala l_salas = exame->salas;

  while (l_salas->next != NULL) {
    l_salas = l_salas->next;
  }
  //l_salas->next = NULL
  l_salas->next = (Next_sala)malloc(sizeof(Node_sala));
  l_salas->next->sala = sala;
  printf("sala: %s\n", l_salas->next->sala);
  l_salas->next->next = NULL;

  update_ficheiro_salas(lista_exames);
}
