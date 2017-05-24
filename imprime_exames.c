void imprime_exames(Next_exame lista) {
  Next_exame l;

  l = lista->next;
  printf("LISTA DE EXAMES EXISTENTES:\n");
  while(l != NULL) {
    printf("\nID: %d", l->id);
    printf("\nnNOME: %s", l->disciplina->nome);
    printf("\nEPOCA: %s", l->epoca);
    l = l->next;
  }
}
