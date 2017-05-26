//TODINHA A FUNCIONAR, ESCREVE NO FICHEIRO
void update_ficheiro_alunos(Next_aluno lista_alunos) {
  Next_aluno l_alunos = lista_alunos->next;
  FILE *fp = fopen("ficheiro_alunos.txt", "w");
  while (l_alunos != NULL) {
    fprintf(fp, "%d,%s,%d,%s\n", l_alunos->num_aluno, l_alunos->curso, l_alunos->ano_mat, l_alunos->regime);
    l_alunos = l_alunos->next;
  }
  fclose(fp);
}
