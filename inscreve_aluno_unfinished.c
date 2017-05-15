// função que inscreve um aluno num dado exame, o qual o utilizador tem que escolher de uma lista que vai ser apresentada

void inscreve_aluno(Node_exame exame, /*lista de alunos em memoria (l)*/){
  int i;
  char c;
  getchar();
  printf("Escolha os alunos a inscrever: ");
  imprime_num_aluno(//lista de alunos em memoria);
  c = getchar();
  for (i=0; i<c; i++) {
    l = l->next;
  }
  //inserir nova lista de ponteiros para alunos inscritos. o campo "alunos inscritos" da struct novo exame é um ponteiro para essa lista
}
