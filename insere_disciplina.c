void insere_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->nome = disciplina->nome;
  aux->docente = disciplina->docente;
  aux->next = NULL;
}
