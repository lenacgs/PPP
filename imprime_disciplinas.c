void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista->next;
  int i=1;
  
  while (l != NULL) {
    printf("%d. %s\n", i, l->nome);
    i++;
    l = l->next;
  }
}
