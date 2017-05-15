void inserir_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  // Assumir que list está em global
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = disciplina;
}
