void verificar_salas_suficientes(Next_exame lista_exames) {
  Next_exame l_exames;
  Next_ptrs_aluno l_inscritos;
  Next_sala l_salas;
  char nova_sala[50];
  int capac_max, num_alunos, num_salas, num_salas_neces, n, resto, id, x, i, res;

  capac_max = 2;
  printf("De qual dos exames e que quer saber se ha salas suficientes?\n");
  imprime_exames(lista_exames);
  printf("Id do exame que deseja: ");
  scanf("%d", &id);
  l_exames = lista_exames->next;
  while (l_exames->id != id) {
    l_exames = l_exames->next;
  }
  printf("Exame me que estamos: %d\n", l_exames->id);

  num_salas = 0;
  l_salas = l_exames->salas->next;
  while (l_salas != NULL) {
    l_salas = l_salas->next;
    num_salas ++;
  }
  printf("Num de salas: %d\n", num_salas);

  capac_max = num_salas * 30;
  printf("Capac_max: %d\n", capac_max);
  num_alunos =0;
  l_inscritos = l_exames->inscritos->next;
  while (l_inscritos != NULL) {
    l_inscritos = l_inscritos->next;
    num_alunos ++;
  }
  printf("Num de alunos: %d\n", num_alunos);

  n = 0; resto = 0;
  if (num_alunos <= capac_max)
    printf("Este exame tem reservadas salas suficientes.\n");
  else {
    n = num_alunos/capac_max;
    resto = num_alunos%capac_max;
    if (resto != 0)
      n++;
    num_salas_neces = n - num_salas;
    printf("Este exame não tem salas reservadas suficientes.\nSao necessarias mais %d salas:\n", num_salas_neces);
    for(i=1; i<=num_salas_neces; i++) {
      printf("Sala %d: ",  i);
      scanf("%s", nova_sala);
      x = verifica_sala(nova_sala, lista_exames, l_exames);
      while (x != 1) {
        getchar();
        printf("\nA sala nao esta disponivel. Escolha outra sala: ");
        scanf("%s", nova_sala);
        res = verifica_sala(nova_sala, lista_exames, l_exames);
      }
      insere_sala(nova_sala, lista_exames, l_exames);
    }
  }
}
