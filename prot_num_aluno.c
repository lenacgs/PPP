int prot_num_aluno(int num, Next_aluno lista_alunos) {
  int res;
  Next_aluno l_alunos = lista_alunos->next;

  while (l_alunos != NULL) {
    if (l_alunos->num_aluno == num) {
      return -1;
    }
    l_alunos = l_alunos->next;
  }
  return 0;
}
