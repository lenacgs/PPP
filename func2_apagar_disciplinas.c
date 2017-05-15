//func2 apagar disciplina

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

void apagar_disciplinas(Next_disciplina lista_disciplinas) {
  char c;
  Next_disciplina l = lista_disciplinas;
  Next_disciplina ant;
  Next_disciplina actual;
  printf("Qual das disciplinas deseja apagar? ");
  imprime_disciplinas(lista_disciplinas);
  c = getchar();
  for (i=0; i<c; i++) {
    ant = l;
    actual = l->next;
  }

  ant->next = actual->next;
  free(actual);
  lista_disciplinas->info --;

}
