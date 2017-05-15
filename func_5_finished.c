//função 5 - listar exames. oq eu falta acabar?? diz unfinished

void imprimir_exames(Next_exame lista) {
  Next_exame l;
  int i=1;
  char c, *ptr, *disc, *ep, *doc;
  Next_ptrs_aluno inscritos;
  l = lista->next;


  while (l) { //lista os exames existentes na lista, juntamente com a epoca
    ptr = (l->disciplina)->nome;
    printf("\n%d. ", i);
    i++;
    imprime_array(ptr);
    ptr = l->epoca;
    printf (", ");
    imprime_array(ptr);
    l = l->next;
  }
  getchar();
  printf("\nEscolha o exame.");
  l = lista->next;
  c = getchar();
  for (i=0; i<c; i++) {
    l = l->next;
  }
  //imprime a info do exame escolhido
  printf("\nDisciplina: ");
  disc = (l->disciplina)->nome;
  imprime_array(disc);

  printf("\nDocente: ");
  doc = (l->disciplina)->docente;
  imprime_array(doc);

  printf("\nÉpoca: ");
  ep = l->epoca;
  imprime_array(ep);

  printf("\nData: ");
  printf("%d - %d - %d", l->(data->dia), l->(data->mes), l->(data->ano));

  printf("\nHora: ");
  printf("%dh %d", l->(hora->horas), l->(hora->mins));

  printf("\nSala: ");
  sala = l->sala;
  imprime_array(sala);

  printf("\nDuração: %d minutos", l->duracao);

  printf("\nAlunos inscritos: ");
  inscritos = l->inscritos;
  while (l->inscritos->next != NULL) {
    printf("%d. %d\n ", i, l->inscritos->aluno->num_aluno); //imprime o numero de aluno de cada aluno inscrito
  }


    }

  }




}
