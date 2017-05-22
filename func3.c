void cria_exame(Next_exame lista_exames, Next_aluno lista_alunos, Next_disciplina lista_disciplinas) {
    char *p_epoca, string[30];
    int len, res, i, num;
    Next_ptrs_aluno l_inscritos;
    Next_disciplina l_disciplinas = lista_disciplinas->next; /*este next e super importante*/
    Next_exame exame, l_exames = lista_exames->next;
    exame = (Next_exame)malloc(sizeof(Node_exame));

    printf("ID: ");
    scanf("%d", &(exame->id));

    exame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    printf("Disciplina: ");
    scanf("%s", string);

    while (l_disciplinas != NULL) {
      if (strcmp(l_disciplinas->nome, string) == 0) {
        exame->disciplina = l_disciplinas;
      }
      l_disciplinas = l_disciplinas->next;
    }

    exame->epoca = (char*)malloc(50*sizeof(char));
    p_epoca = exame->epoca;
    printf("Epoca: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_epoca, len);

    printf("Data: \nDia: ");
    scanf("%d", &(exame->data.dia));
    printf("Mes: ");
    scanf("%d", &(exame->data.mes));
    printf("Ano: ");
    scanf("%d", &(exame->data.ano));

    printf("Hora: \nHoras: ");
    scanf("%d", &(exame->hora.horas));
    printf("Minutos: ");
    scanf("%d", &(exame->hora.mins));

    printf("Duracao (em minutos): ");
    scanf("%d", &(exame->duracao));

    printf("Sala: ");
    scanf("%s", string);
    exame->sala = (char*)malloc(100*sizeof(char));
    printf("string: -%s-\n", string);

    res = verifica_sala(string, lista_exames, exame);
    while (res != 1) {
      getchar();
      printf("\nA sala nao esta disponivel. Escolha outra sala: ");
      scanf("%s", string);
      res = verifica_sala(string, lista_exames, exame);
    }
    strcpy(exame->sala, string);

    getchar();
    printf("Quantos alunos quer inscrever?: ");
    scanf("%d", &num);
    lista_exames->inscritos = cria_lista_inscritos();
    for (i=1; i<=num; i++) {
      inscreve_aluno(lista_exames->inscritos, lista_alunos);

    }
    l_inscritos = lista_exames->inscritos->next;
    while (l_inscritos != NULL) {
      printf("%d\n", l_inscritos->aluno->num_aluno);
      l_inscritos = l_inscritos->next;
    }
    insere_exame(lista_exames, exame);

}
