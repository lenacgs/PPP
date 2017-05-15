//função 7
//Listar alunos inscritos num exame.

void listar_alunos(Next_exame lista_exames) {
  Next_exame l = lista_exames;
  char *ptr, c;
  int i=1;
  printf("Seleccione o exame: ");
  while (l) {
    ptr = (l->disciplina)->nome;
    printf("\n%d. ", i);
    i++;
    imprime_array(ptr);
    ptr = l->epoca;
    printf (", ");
    imprime_array(ptr);
    l = l->next;
  }

  l = lista->next;
  getchar();
  c = getchar();
  for (i=0; i<c; i++) {
    l = l->next;
  }
  // nao se devia usar aqui a função imprime_num_aluno?
  ptr = (l->aluno)->num_aluno;

}
