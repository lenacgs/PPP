void altera_dados_disciplina(List lista_disciplinas) {
  int opcao, novo_num, novo_ano, len;
  char c, *p_nome, *p_docente, string[50];
  Next_disciplina l, disciplina, ant, actual;

  l = lista_disciplinas;
  printf("Escolha a disciplina a qual quer alterar dados: \n");
  imprime_disciplinas(lista_disciplinas);
  scanf("%d", &num);
  for (i=0; i<num; i++) {
    ant = l;
    actual = l->next;
  }

  disciplina = actual;
  printf("Escolha o dado que deseja alterar:\n1. Nome da disciplina\n2. Nome do docente");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1:
      disciplina->nome = (*char)malloc(50*sizeof(char));
      p_nome = disciplina->nome;
      printf("Nova disciplina: ");
      scanf("%s", string);
      len = strlen(string);
      insere_array(string, p_nome, len);
      break;

    case 2:
      disciplina->docente = (*char)malloc(50*sizeof(char));
      p_docente = disciplina->docente;
      printf("Novo docente: ");
      scanf("%s", string);
      len = strlen(string);
      insere_array(string, p_docente, len);
      break;
  }
}
