//func 1. apagar aluno


void apagar_aluno (Next_aluno lista_alunos) {
    Next_aluno l = lista_alunos;
    Next_aluno ant;
    Next_aluno actual;
    printf("Qual dos alunos é que deseja apagar? ");
    imprime_num_aluno(lista_alunos);
    c = getchar();
    for (i=0; i<c; i++) {
      ant = l;
      actual = l->next;
    }

    ant->next = actual->next;
    free(actual);
    /*lista_alunos->info --;*/
}
