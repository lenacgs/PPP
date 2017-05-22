//função 5 - listar exames. oq eu falta acabar?? diz unfinished

void imprimir_exames(Next_exame lista) {
  Next_exame l;
  int i=1, c;
  char *ptr, *disc, *ep, *doc;
  Next_ptrs_aluno inscritos;

  l = lista->next;
  printf("Lista de exames existentes:\n");
  while (l) { //lista os exames existentes na lista, juntamente com a epoca
    printf("%d. %s", i, l->disciplina->nome);
    i++;
    printf(", %s\n", l->epoca);
    l = l->next;
  }
  /*o exame devia ser identificado pelo id*/
  getchar();
  printf("\nEscolha o exame: ");
  scanf("%d", &c);

  l = lista;
  for (i=0; i<c; i++) {
    printf("ciclo:\n");
    printf("id: %d\n", l->id);
    l = l->next;
  }
  printf("Informacao desse exame:\n ");
  printf("\nDisciplina: ");
  printf("%s", l->disciplina->nome);

  printf("\nDocente: ");
  printf("%s", l->disciplina->docente);

  printf("\nÉpoca: ");
  printf("%s", l->epoca);

  printf("\nData: ");
  printf("%d - %d - %d", l->data.dia, l->data.mes, l->data.ano);

  printf("\nHora: ");
  printf("%dh%d", l->hora.horas, l->hora.mins);

  printf("\nSala: ");
  printf("%s", l->sala);

  printf("\nDuração: %d minutos", l->duracao);

  printf("\nAlunos inscritos: \n");
  /*este while nao funiona*/

  inscritos = lista->inscritos->next;
  while (inscritos != NULL) {
    printf("%d. %d\n ", i, inscritos->aluno->num_aluno);
    i++;
    inscritos = inscritos->next;
  }
}
