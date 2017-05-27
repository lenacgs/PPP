void imprime_exames(Next_exame lista_exames) {
  Next_exame l_exames;

  l_exames = lista_exames->next;
  while(l_exames != NULL) {
    printf("Id: %d, %s, %s\n", l_exames->id, l_exames->disciplina->nome, l_exames->epoca);
    l_exames = l_exames->next;
  }
}
