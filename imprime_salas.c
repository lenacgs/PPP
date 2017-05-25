void imprime_listas_salas(Next_exame lista_exames) { //imprime todas as salas de todos os exames
  Next_sala lista_salas;
  Next_exame l_exames = lista_exames->next;

  while (l_exames->next != NULL) {
    printf("O exame com ID %d, da disciplina %s em época %s tem reservadas as seguintes salas:\n", l_exames->id, l_exames->disciplina->nome, l_exames->epoca);
    lista_salas = l_exames->salas->next;
    while (lista_salas != NULL) {
      printf("Sala: %s\n", lista_salas->sala);
      lista_salas = lista_salas->next;
    }
    l_exames = l_exames->next;
  }
}

void imprime_salas(Next_exame exame) { //imprime as salas reservadas para um determinado exame
  Next_sala lista_salas = exame->salas->next;

  printf("O exame %d, %s, %s tem reservadas as seguintes salas:\n", exame->id, exame->disciplina->nome, exame->epoca);
  while (lista_salas != NULL) {
    printf("Sala %s\n", lista_salas->sala);
    lista_salas = lista_salas->next;
  }
}
