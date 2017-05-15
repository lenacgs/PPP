//8 - Listar exames em que um aluno está inscrito

void imprime_ponteiros(Next_ptrs_exame lista) {
  while (lista != NULL) {
    imprime_array(lista->exame->disciplina->nome);
  }
}

void listar_inscricoes_alunos (Node_aluno lista_alunos) {
  char c;
  int i;
  Node_aluno l = lista_alunos;
  getchar();
  printf("Seleccione o aluno: ");
  imprime_num_aluno(lista_alunos);
  c = getchar();
  //seleccionar o nó pretendido
  for (i=0; i<c; i++) {
    l = l->next;
  }
  //aceder à lista de ponteiros que está dentro da secção "inscritos" na struct Node_aluno
  //l->inscricoes->exame->disciplina->nome
  imprime_ponteiros(l->inscricoes);
}
