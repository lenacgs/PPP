//função 3 - criar um novo exame
//falta a questao das salas

void insere_novo_exame(Node_exame lista_exames, Node_aluno lista_alunos, Node_disciplina lista_disciplinas) {
  char string[20];
  int res;
  int len;
  Node_disciplina l = lista_disciplinas, ant, ptr;
  Data data;
  Hora hora;
  Node_exame new_node;

  printf("Disciplina: ");
  scanf("%s", string);
  while (l != NULL) {
    if (strcmp(l->next->disciplina->nome, string) == 0) {

    }
  // **********atention
  }


  printf("Época: ");
  scanf("%s", string);
  len = strlen(string);
  insere_array(string, new_node->epoca, len);

  printf("Data: Dia: ");
  scanf("%d", new_node->data->dia);
  printf("Mês: ");
  scanf("%d", new_node->data->mes);
  printf("Ano: ");
  scanf("%d", new_node->data->ano);

  printf("Hora: Horas: ");
  scanf("%d", new_node->hora->horas);
  printf("Minutos: ")
  scanf("%d", new_node->hora->mins);

  printf("Duração (em minutos): ");
  scanf("%d", new_node->duracao);

  printf("Sala: ");
  scanf("%s", string);
  len = strlen(string);
  res = verifica_sala(string, lista_exames, new_node);
  if (res == 1)
    insere_array(string, new_node->sala, len);
  else printf("A sala não está disponível.");

  getchar();
  printf("Pressione:\nI: Inscrever aluno.\nS:Sair.");
  while ((c = getchar()) == 'I') {
    inscreve_aluno(new_node->inscritos, lista_alunos);
    new_node->inscritos = new_node->inscritos->next;
    printf("Pressione:\nI: Inscrever aluno.\nS:Sair.");
  }



}