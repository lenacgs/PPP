// função que imprime os numeros dos alunos que estao num dada lista

void imprime_num_aluno(Next_aluno lista) {
  Next_aluno aux;
  aux = lista;
  int i=1;
  while(aux != NULL) {
    printf("%d. %d\n", i, aux->num_aluno);
    i++;
    aux = aux->next;
  }
}
