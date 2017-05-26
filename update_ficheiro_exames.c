void update_ficheiro_exames(Next_exame lista_exames) {
  Next_exame l_exames = lista_exames->next;
  Next_ptrs_aluno l_inscritos;
  FILE *fp = fopen("ficheiro_exames.txt", "w");
  while (l_exames != NULL) {
    printf("Estamos no exame: %d\n", l_exames->id);
    fprintf(fp, "%d,%s,%s,%d,%d,%d,%d,%d,%d", l_exames->id, l_exames->disciplina->nome,  l_exames->epoca,  l_exames->data.dia, l_exames->data.mes, l_exames->data.ano, l_exames->hora.horas, l_exames->hora.mins, l_exames->duracao);

    l_inscritos = l_exames->inscritos->next;
    while (l_inscritos != NULL) {
      printf("Aluno: %d\n", l_inscritos->aluno->num_aluno);
      fprintf(fp, ",%d", l_inscritos->aluno->num_aluno);
      l_inscritos = l_inscritos->next;
    }
    fprintf(fp, "\n");
    l_exames = l_exames->next;
  }
