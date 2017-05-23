//ja acabada so falta mudar a escolha do exame. devia ser por id e não por numero pelo qual é listado

void listar_alunos(Next_exame lista_exames) {
  Next_exame l_exames = lista_exames->next; //por causa do cabeçalho
  Next_ptrs_aluno inscritos;
  char *ptr, c;
  int i=1, num;
  printf("Seleccione o exame do qual quer listar os alunos: \n");
  while (l_exames) {
    printf("%d. Id: %d, ", i, l_exames->id);
    printf("%s ", l_exames->disciplina->nome);
    printf("%s\n", l_exames->epoca);
    l_exames = l_exames->next;
    i++;
  }

  l_exames = lista_exames;
  printf("\nOpcao: ");
  scanf("%d", &num);
  for (i=0; i<num; i++) {
    l_exames = l_exames->next;
  }
  printf("Exame me que estamos: %d\n", l_exames->id);

  printf("Alunos inscritos no exame:\n");
  inscritos = l_exames->inscritos->next;
  while (inscritos != NULL) {
    printf("%d. %d\n", i, inscritos->aluno->num_aluno);
    i++;
    inscritos = inscritos->next;
  }
}
