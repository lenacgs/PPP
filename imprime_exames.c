void imprime_exames(Next_exame lista) {
  Next_exame l;

  l = lista->next;
  while(l != NULL) {
    printf("\nnome: %d", l->id);
    printf("\nnome: %s", l->disciplina->nome);
    printf("\nepoca: %s", l->epoca);
    l = l->next;
  }
}
