void update_ficheiro_disciplinas(Next_disciplina lista_disciplinas) {
  Next_disciplina l_disciplinas = lista_disciplinas->next;
  FILE *fp = fopen("ficheiro_disciplinas.txt", "w");
  while (l_disciplinas != NULL) {
    fprintf(fp, "%s,%s\n", l_disciplinas->nome, l_disciplinas->docente);
    l_disciplinas = l_disciplinas->next;
  }
  fclose(fp);
}
