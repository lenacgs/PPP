//TUDINHO A FUNCIONAR, ESCOLHE O EXAME PELO ID
void listar_alunos(Next_exame lista_exames) {
  Next_exame l_exames; //por causa do cabeçalho
  Next_ptrs_aluno l_inscritos;
  char *ptr, c;
  int i=1, id;
  printf("Seleccione o exame do qual quer listar os alunos: \n");
  imprime_exames(lista_exames);

  l_exames = lista_exames->next;
  printf("Id do exame que deseja: ");
  scanf("%d", &id);
  while(l_exames->id != id) {
    l_exames = l_exames->next;
  }

  printf("Id do exame me que estamos: %d\n", l_exames->id);
  printf("Alunos inscritos no exame:\n");
  l_inscritos = l_exames->inscritos->next;
  while (l_inscritos != NULL) {
    printf("%d. %d\n", i, l_inscritos->aluno->num_aluno);
    i++;
    l_inscritos = l_inscritos->next;
  }
}
