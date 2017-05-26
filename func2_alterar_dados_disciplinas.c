//TODINHA A FUNCIONAR, EXCREVE NO FICHEIRO
void alterar_dados_disciplina(Next_disciplina lista_disciplinas) {
  int opcao, i, num;
  Next_disciplina l_disciplinas, disciplina;

  l_disciplinas = lista_disciplinas;
  printf("Escolha a disciplina a qual quer alterar dados: \n");
  imprime_disciplinas(lista_disciplinas);
  printf("Opcao: ");
  scanf("%d", &num);
  for (i=0; i<num; i++) {
    l_disciplinas = l_disciplinas->next;
  }
  printf("Disicplina que escolhemos: %s\n", l_disciplinas->nome);
  printf("Escolha o dado que deseja alterar:\n1. Nome da l_disciplinas\n2. Nome do docente\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1:
      l_disciplinas->nome = (char*)malloc(50*sizeof(char));
      printf("Nova disciplina: ");
      scanf("%s", l_disciplinas->nome);
      break;

    case 2:
      l_disciplinas->docente = (char*)malloc(50*sizeof(char));
      printf("Novo docente: ");
      scanf("%s", l_disciplinas->docente);
      break;
  }
  update_ficheiro_disciplinas(lista_disciplinas);
}
