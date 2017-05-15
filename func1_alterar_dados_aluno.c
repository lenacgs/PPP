void alterar_dados_aluno(Next_aluno lista_alunos) {
  int opcao, novo_num, novo_ano, len, num, i;
  char *p_curso, *p_regime, string[50];
  Next_aluno aluno, l, ant, actual;

  l = lista_alunos;
  printf("Escolha o aluno a quem quer alterar dados: \n");
  imprime_num_aluno(lista_alunos);
  scanf("%d", &num);
  for (i=0; i<num; i++) {
    ant = l;
    actual = l->next;
  }

  aluno = actual;
  printf("Escolha o dado que deseja alterar:\n1. Numero\n2. Curso\n3. Ano de matricula\n4. Regime\n");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1: {
      printf("Novo numero: ");
      scanf("%d", &novo_num);
      (aluno->num_aluno) = novo_num;
      break;
    }
    case 2: {
      p_curso = (char*)malloc(50*sizeof(char));
      p_curso = aluno->curso;
      printf("Novo curso: ");
      scanf("%s", string);
      len = strlen(string);
      insere_array(string, p_curso, len);
      break;
    }
    case 3: {
      printf("Novo ano: ");
      scanf("%d", &novo_ano);
      (aluno->ano_mat) = novo_ano;
      break;
    }
    case 4: {
      p_regime = (char*)malloc(50*sizeof(char));
      p_regime = aluno->regime;
      printf("Novo regime: ");
      scanf("%s", string);
      len = strlen(string);
      insere_array(string, p_regime, len);
      break;
    }
  }
}
