//funçao imprime disciplinas

void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista;
  int i=1;
  while (l != NULL) {
    printf("%d.", i);
    imprime_array(l->nome);
    i++;
    l = l->next;
  }
}
