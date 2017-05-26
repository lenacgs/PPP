//TODINHA A FUNCIONAR, ESCREVE NO FICHEIRO
void alterar_dados_aluno(Next_aluno lista_alunos) {
  int opcao, num, i;
  char string[50];
  Next_aluno l_alunos;

  printf("Escolha o aluno a quem quer alterar dados: \n");
  imprime_num_aluno(lista_alunos);
  printf("Opcao: ");
  scanf("%d", &num);
  l_alunos = lista_alunos;
  for (i=0; i<num; i++) {
    l_alunos = l_alunos->next;
  }

  printf("Escolha o dado que deseja alterar:\n1. Numero\n2. Curso\n3. Ano de matricula\n4. Regime\nOpcao: ");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1: {
      printf("Novo numero: ");
      scanf("%d", &(l_alunos->num_aluno));
      break;
    }
    case 2: {
      l_alunos->curso = (char*)malloc(50*sizeof(char));
      printf("Novo curso: ");
      scanf("%s", l_alunos->curso);
      break;
    }
    case 3: {
      printf("Novo ano: ");
      scanf("%d", &(l_alunos->ano_mat));
      break;
    }
    case 4: {
      l_alunos->regime = (char*)malloc(50*sizeof(char));
      printf("Novo regime: ");
      scanf("%s", l_alunos->regime);
      break;
    }
  }
  update_ficheiro_alunos(lista_alunos);
}
