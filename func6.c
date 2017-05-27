//TUDINHO A FUNCIONAR, ESCREVE NO FICHEIRO E ESCOLHE O EXME PELO ID

void inscreve_desinscreve_aluno(Next_exame lista_exames, Next_aluno lista_alunos) {
  Next_exame l_exames = lista_exames;
  Next_aluno l_alunos, last_aluno;
  Next_ptrs_aluno l_inscritos, new_node, actual, ant;
  int n_exames, n_alunos, i, id_aluno, id, opcao, tag;

  printf("O que deseja?\n1. Inscrever aluno\n2. Desinscrever aluno\nOpcao: ");
  scanf("%d", &opcao);
  switch (opcao){
    case 1:
      printf("Seleccione o aluno que pretende inscrever: \n");
      imprime_num_aluno(lista_alunos);
      printf("Opcao: ");
      scanf("%d", &opcao);
      l_alunos = lista_alunos;
      for(i=0; i<opcao; i++) {
        l_alunos = l_alunos->next;
      }

      printf("Em quantos exames quer inscrever o aluno? ");
      scanf("%d", &n_exames);
      for (i=0; i<n_exames; i++) {
        printf("Seleccione o exame em que pretende inscrever o aluno: \n");
        imprime_id_exames(lista_exames);
        printf("Id do exame que deseja: ");
        scanf("%d", &id);
        l_exames = lista_exames->next;
        while(l_exames->id != id) {
          l_exames = l_exames->next;
        }

        l_inscritos = l_exames->inscritos;
        tag = 0;
        while (l_inscritos->next != NULL) {
          if (l_inscritos->next->aluno->num_aluno == l_alunos->num_aluno)
            tag = 1;
          l_inscritos = l_inscritos->next;
        }

        if (tag == 0) {
          l_inscritos = l_exames->inscritos;
          while(l_inscritos->next != NULL) {
            l_inscritos = l_inscritos->next;
          }

          l_inscritos->next = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
          l_inscritos->next->aluno = l_alunos;
          l_inscritos->next->next = NULL;

          printf("Lista final inscritos:\n");
          l_inscritos = l_exames->inscritos;
          while(l_inscritos->next != NULL) {
            printf("Aluno inscrito: %d\n", l_inscritos->next->aluno->num_aluno);
            l_inscritos = l_inscritos->next;
          }
        }
        else {
          printf("Este aluno ja se encontra inscrito no exame de id: %d\n", l_exames->id);
        }
      }
      break;

    case 2:
      printf("Seleccione o aluno que pretende desinscrever: \n");
      imprime_num_aluno(lista_alunos);
      printf("Opcao: ");
      scanf("%d", &opcao);
      l_alunos = lista_alunos;
      for(i=0; i<opcao; i++) {
        l_alunos = l_alunos->next;
      }
      id_aluno = l_alunos->num_aluno;

      printf("De quantos exames quer desinscrever o aluno? ");
      scanf("%d", &n_exames);
      for (i=0; i<n_exames; i++) {
        printf("Seleccione o exame de que pretende desinscrever o aluno: \n");
        imprime_id_exames(lista_exames);
        printf("Id do exame que deseja: ");
        scanf("%d", &id);
        l_exames = lista_exames->next;
        while(l_exames->id != id) {
          l_exames = l_exames->next;
        }
        printf("Id do exame em que estamos: %d\n", l_exames->id);

        tag = 0;
        l_inscritos = l_exames->inscritos;
        ant = l_inscritos;
        actual = ant->next;
        while(actual != NULL) {
          printf("Aluno com o qual estamos a comparar: %d\n", actual->aluno->num_aluno);
          if (actual->aluno->num_aluno == id_aluno) {
            tag = 1;
            printf("Aluno que tem o id igual: %d\n", actual->aluno->num_aluno);
            ant->next = actual->next;
            free(actual);
            actual = ant->next;
          }
          else {
            actual = actual->next;
            ant = ant->next;
          }
        }
        if (tag == 0)
          printf("Este aluno nao se encontra inscrito no exame de id: %d.\n", l_exames->id);
    }
    tag = 0;
  }
  update_ficheiro_exames(lista_exames);
}
