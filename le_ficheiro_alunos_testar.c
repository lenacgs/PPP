#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
/*----------------------------------------------------------------*/

Next_aluno cria_lista_alunos() {
    Next_aluno aux;
    aux = (Next_aluno)malloc(sizeof(Node_aluno));
    if (aux != NULL) {
        aux->num_aluno = 0;
        aux->curso = NULL;
        aux->ano_mat = 0;
        aux->regime = NULL;
        aux->inscricoes = NULL;
        aux->next = NULL;
    }
    return aux;
}

void imprime_num_aluno(Next_aluno lista) {
  Next_aluno aux;
  aux = lista;
  int i=1;
  while(aux != NULL) {
    printf("%d. %d\n", i, aux->num_aluno);
    i++;
    aux = aux->next;
  }
}

void insere_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = aluno;
}



void le_ficheiro_alunos(Next_aluno lista_alunos) {
  FILE * fp;
  Next_aluno novoAluno;
  char line[100];
  fp = fopen("ficheiro_alunos.txt", "r");
  char num[20];

  while (fscanf(fp, "%[^,]", line) != EOF) {
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    fscanf(fp, "%[^,]", num);
    novoAluno->num_aluno = atoi(num);
    printf("num: %d", novoAluno->num_aluno);
    fseek(fp, 1, SEEK_CUR);

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->curso);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,]", &(novoAluno->ano_mat));
    fseek(fp, 1, SEEK_CUR);

    novoAluno->regime = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->regime);
    fseek(fp, 1, SEEK_CUR);

    insere_aluno(lista_alunos, novoAluno);

  }
  fclose(fp);
}

int main() {
  Next_aluno lista_alunos;
  lista_alunos = cria_lista_alunos();
  le_ficheiro_alunos(lista_alunos);
  imprime_num_aluno(lista_alunos);

}
