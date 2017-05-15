
void criar_disciplina(List lista_disciplinas) {
    char c, *p_nome, *p_docente, string[50];
    int len;
    Next_disciplina disciplina;
    disciplina = (Next_adisciplina)malloc(size_of(Node_disciplina));

    p_nome = (char*)malloc(50*sizeof(char));
    p_nome = disciplina->nome;
    printf("Disciplina: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_nome, len);

    p_docente = (char*)malloc(50*sizeof(int));
    p_docente = disciplina->docente;
    printf("Nome do docente: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_docente, len);

    inserir_disciplina(lista_disciplinas, disciplina);
}
