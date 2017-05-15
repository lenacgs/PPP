void inserir_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  // Assumir que list está em global
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = aluno;
}
