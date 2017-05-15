// * -> * -> *

void criar_aluno(Next_aluno lista_alunos) {
    char *p_curso, *p_regime, string [50];
    int len;
    Next_aluno aluno;
    aluno = (Next_aluno)malloc(sizeof(Node_aluno));

    aluno->num_aluno = (int)malloc(30 * sizeof(int));
    printf("Numero: ");
    scanf("%d", &(aluno->num_aluno)); /*certo*/

    aluno->curso = (char*)malloc(50*sizeof(char));
    p_curso = aluno->curso;
    printf("Curso: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_curso, len);

    printf("Ano de matricula: ");
    scanf("%d", &(aluno->ano_mat));

    printf("Regime: ");
    aluno->regime = (char*)malloc(50*sizeof(int));
    p_regime = aluno->regime;
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_regime, len);

    inserir_aluno(lista_alunos, aluno);
}
