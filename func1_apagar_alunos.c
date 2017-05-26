//TODINHA A FUNCIONAR, ESCREVE NO FICHEIRO
void apagar_aluno(Next_aluno lista_alunos) {
  Next_aluno l_alunos, ant, actual, aluno_apagar;
  int i, num;

  printf("Qual dos alunos deseja apagar?\n");
  imprime_num_aluno(lista_alunos);
  printf("Opcao: ");
  scanf("%d", &num);
  l_alunos = lista_alunos;
  for(i=0; i<num; i++) {
    l_alunos = l_alunos->next;
  }
  aluno_apagar = l_alunos;

  l_alunos = lista_alunos;
  ant = l_alunos;
  actual = ant->next;
  while(actual != NULL) {
   if (actual->num_aluno == aluno_apagar->num_aluno) {
     ant->next = actual->next;
     free(actual);
     actual = ant->next;
   }
   else {
     actual = actual->next;
     ant = ant->next;
   }
  }
  update_ficheiro_alunos(lista_alunos);
}
