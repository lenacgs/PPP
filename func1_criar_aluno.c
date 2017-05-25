void criar_aluno(Next_aluno lista_alunos, Next_exame lista_exames) {
    char *p_curso, *p_regime, string [30];
    int len, i, opcao;
    Next_aluno novoAluno, l_alunos = lista_alunos;
    Next_ptrs_exame l_inscricoes;

    printf("Aluno %d:\n", i);
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    novoAluno->num_aluno = (int)malloc(30 * sizeof(int));
    printf("Numero: ");
    scanf("%d", &(novoAluno->num_aluno)); /*certo*/

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    printf("Curso: ");
    scanf("%s", novoAluno->curso);

    printf("Ano de matricula: ");
    scanf("%d", &(novoAluno->ano_mat));

    novoAluno->regime = (char*)malloc(50*sizeof(int));
    printf("Regime: ");
    scanf("%s", novoAluno->regime);

    novoAluno->inscricoes = cria_lista_inscricoes();
    l_inscricoes = novoAluno->inscricoes;

    printf("Em quantos exames quer inscrever o aluno? ");
    scanf("%d", &opcao);
    for(i=0; i<opcao; i++) {
      associa_exame(l_inscricoes, lista_exames);
    }
    //para ter a certeza que os exames ficaram bem associados
    l_inscricoes = novoAluno->inscricoes->next;
    printf("LISTA DE EXAMES INSCRITOS:\n");
    while (l_inscricoes != NULL) {
      printf("Id: %d\n", l_inscricoes->exame->id);
      l_inscricoes = l_inscricoes->next;
    }
    insere_aluno(lista_alunos, novoAluno);
    escreve_ficheiro_alunos(lista_alunos, novoAluno);

}
