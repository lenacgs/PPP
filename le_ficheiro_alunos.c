#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void le_ficheiro_alunos(Next_aluno lista_alunos) {
  FILE * fp;
  Next_aluno novoAluno;
  fp = fopen("ficheiro_alunos.txt", "r");
  char num[100];

  while (fscanf(fp, "%[^,]", num) != EOF) {
    fseek(fp, 1, SEEK_CUR);
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));
    
    printf("%s\n", num);
    novoAluno->num_aluno = atoi(num);
    printf("num: %d\n", novoAluno->num_aluno);

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->curso);
    printf("%s\n", novoAluno->curso);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,]", &(novoAluno->ano_mat));
    printf("%d\n", novoAluno->ano_mat);
    fseek(fp, 1, SEEK_CUR);

    novoAluno->regime = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->regime);
    printf("%s\n", novoAluno->regime);
    fseek(fp, 1, SEEK_CUR);

    insere_aluno(lista_alunos, novoAluno);

  }
  fclose(fp);
}
