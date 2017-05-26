//TODINHA A FUNCIONAR, ESCREVE NO FICHEIRO
void update_ficheiro_alunos(Next_aluno lista_alunos) {
  Next_aluno l_alunos = lista_alunos->next;
  Next_ptrs_exame l_inscricoes;
  FILE *fp = fopen("ficheiro_alunos.txt", "w");
  while (l_alunos != NULL) {
    fprintf(fp, "%d,%s,%d,%s", l_alunos->num_aluno, l_alunos->curso, l_alunos->ano_mat, l_alunos->regime);

    l_inscricoes = l_alunos->inscricoes->next;
    while (l_inscricoes != NULL) {
      fprintf(fp, ",%d", l_inscricoes->exame->id);
      l_inscricoes = l_inscricoes->next;
    }
    fprintf(fp, "\n");
    l_alunos = l_alunos->next;
  }

  fclose(fp);
}
