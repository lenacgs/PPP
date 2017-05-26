//TODINHA A FUNCIONAR, ESCREVE NO FICHEIRO
void apagar_disciplinas(Next_disciplina lista_disciplinas) {
  Next_disciplina l_disciplinas, ant, actual, disciplina_apagar;
  int i, num;

  printf("Qual das disciplinas deseja apagar?\n");
  imprime_disciplinas(lista_disciplinas);
  printf("Opcao: ");
  scanf("%d", &num);
  l_disciplinas = lista_disciplinas;
  for(i=0; i<num; i++) {
    l_disciplinas = l_disciplinas->next;
  }
  disciplina_apagar = l_disciplinas;
  l_disciplinas = lista_disciplinas;
  ant = l_disciplinas;
  actual = ant->next;
  while(actual != NULL) {
   if (actual->nome == disciplina_apagar->nome) {
     ant->next = actual->next;
     free(actual);
     actual = ant->next;
   }
   else {
     actual = actual->next;
     ant = ant->next;
   }
  }
  update_ficheiro_disciplinas(lista_disciplinas);
}
