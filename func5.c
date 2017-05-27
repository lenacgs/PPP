//TODINHA A FUNCIONAR, A ESCOLHA DO EXAME JA E FEITA PELO ID
void listar_exames(Next_exame lista_exames) {
  Next_exame l_exames;
  int i=1, id;
  Next_ptrs_aluno l_inscritos;
  Next_sala l_salas;

  l_exames = lista_exames->next;
  printf("Lista de exames existentes:\n");
  imprime_exames(lista_exames);

  /*o exame devia ser identificado pelo id*/
  printf("\nEscolha o id do exame: ");
  scanf("%d", &id);

  l_exames = lista_exames->next;
  while (l_exames->id != id) {
    l_exames = l_exames->next;
  }

  printf("Informacao desse exame:\n");
  printf("Disciplina: ");
  printf("%s\n", l_exames->disciplina->nome);

  printf("Docente: ");
  printf("%s\n", l_exames->disciplina->docente);

  printf("Época: ");
  printf("%s\n", l_exames->epoca);

  printf("Data: ");
  printf("%d-%d-%d\n", l_exames->data.dia, l_exames->data.mes, l_exames->data.ano);

  printf("Hora: ");
  printf("%dh%d\n", l_exames->hora.horas, l_exames->hora.mins);

  printf("Salas: \n");
  l_salas = l_exames->salas->next;
  while (l_salas != NULL) {
    printf("Sala %d: %s\n", i, l_salas->sala); //imprime null
    i++;
    l_salas = l_salas->next;
  }

  printf("Duração: %d minutos\n", l_exames->duracao);

  printf("Alunos inscritos: \n");

  i=1;
  l_inscritos = l_exames->inscritos->next;
  while (l_inscritos != NULL) {
    printf("%d. %d\n", i, l_inscritos->aluno->num_aluno);
    i++;
    l_inscritos = l_inscritos->next;
  }
}

