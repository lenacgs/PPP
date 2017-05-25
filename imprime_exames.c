void imprime_exames(Next_exame lista_exames) {
  Next_exame l_exames;
  int i =1;
  
  l_exames = lista->next;
  while(l_exames != NULL) {
    printf("%d. Id: %d, %s, %s\n", l->id, l->disciplina->nome, l->epoca);
    l_exames = l_exames->next;
    i++;
  }
}
