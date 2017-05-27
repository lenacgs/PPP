void imprime_exames(Next_exame lista_exames) {
  Next_exame l_exames;
  
  l_exames = lista->next;
  while(l_exames != NULL) {
    printf("Id: %d, %s, %s\n", l->id, l->disciplina->nome, l->epoca);
    l_exames = l_exames->next;
  }
}
