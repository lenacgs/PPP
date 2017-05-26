//TODINHA A FUNCIONAR, ESCREVE NO FICHEIRO
void criar_disciplina(Next_disciplina lista_disciplinas) {
    Next_disciplina novaDisciplina;
    int n, i;

    printf("Quantas disciplinas e que quer criar? ");
    scanf("%d", &n);
    for(i=1; i<=n;i++) {
      printf("Disciplina %d:\n", i);
      novaDisciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));

      novaDisciplina->nome = (char*)malloc(50*sizeof(char));
      printf("Nome da disciplina: ");
      scanf("%s", novaDisciplina->nome);

      novaDisciplina->docente = (char*)malloc(50*sizeof(int));
      printf("Nome do docente: ");
      scanf("%s", novaDisciplina->docente);

      insere_disciplina(lista_disciplinas, novaDisciplina);
      escreve_ficheiro_disciplinas(lista_disciplinas, novaDisciplina);
    }
}
