//8 - Listar exames em que um aluno está inscrito

void listar_inscricoes_alunos (Next_aluno lista_alunos) {
  int i, opcao;
  Next_aluno l_alunos = lista_alunos;
  Next_ptrs_exame l_inscricoes;

  printf("Seleccione o aluno do qual quer listar os exames: \n");
  imprime_num_aluno(lista_alunos);
  printf("Opcao: ");
  scanf("%d", &opcao);
  //seleccionar o nó pretendido
  for (i=0; i<opcao; i++) {
    l_alunos = l_alunos->next;
  }
  printf("O aluno está inscrito nos exames:\n");
  l_inscricoes = l_alunos->inscricoes->next;
  while (l_inscricoes != NULL) {
    printf("Id: %d, %s, %s\n", l_inscricoes->exame->id, l_inscricoes->exame->disciplina->nome, l_inscricoes->exame->epoca);
    l_inscricoes = l_inscricoes->next;
  }
}
