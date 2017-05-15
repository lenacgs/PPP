//função para inscrever um aluno no novo exame criado
//criar uma lista de ponteiros para struct node_aluno

void inscreve_aluno(Next_ptrs_aluno lista_ptrs, Next_aluno lista_alunos) {
  char c;
  Next_ptrs_aluno new_node;
  Next_aluno l = lista_alunos;
  getchar();
  printf("Seleccione o aluno que pretende inscrever no exame:\n");
  imprime_num_aluno(lista_alunos);
  c = getchar();
  for (i=0; i<c; i++) {
    l = l->next;
  }

  new_node = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  if (new_node != NULL) {
    new_node->next = NULL;
    new_node->aluno = l;
  }
}
