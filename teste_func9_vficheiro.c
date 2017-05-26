//func9
void imprime_exames(Next_exame lista) {
  Next_exame l;

  l = lista->next;
  printf("LISTA DE EXAMES EXISTENTES:\n");
  while(l != NULL) {
    printf("\nID: %d", l->id);
    printf("\nnNOME: %s", l->disciplina->nome);
    printf("\nEPOCA: %s", l->epoca);
    l = l->next;
  }
}

void verificar_salas_suficientes(Next_exame lista_exames) {
  Next_exame l_exames = lista_exames->next;
  Next_ptrs_aluno l_inscritos;
  char nova_sala[50];
  int capac_max, num_alunos, id, x;

  printf("De qual dos exames e que quer saber se ha salas suficientes?\n");
  imprime_exame(lista_exames);
  printf("Id do exame que deseja: ");
  scanf("%d", &id)
  while (l_exames->id != id) {
    l_exames = l_exames->next;
  }

  l_inscritos = l_exames->inscritos;
  while (l_inscritos != NULL) {
    num_alunos ++;
  }

  if (num_alunos <= capac_max)
    printf("Este exame tem salas reservadas suficientes.\n")
  else {
    n = num_alunos/capac_max;
    resto = num_alunos%capac_max;
    if (resto != 0)
      n++;
    printf("Este exame não tem salas reservadas suficientes.\nSao necessarias mais %d salas:\n", n);
    for(i=0; i<n; i++) {
      printf("Sala %d: ",  i);
      scanf("%s", nova_sala);
      x = verifica_sala(sala, lista_exames, l_exames);
      while (x != 1) {
        getchar();
        printf("\nA sala nao esta disponivel. Escolha outra sala: ");
        scanf("%s", nova_sala);
        res = verifica_sala(string, lista_exames, l_exames);
      }
    }
  }
}
