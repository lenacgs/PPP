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

Next_exame cria_lista_exames() {
    Next_exame aux;
    aux = (Next_exame)malloc(sizeof(Node_exame));
    if (aux != NULL) {
      aux->disciplina = NULL;
      aux->epoca = NULL;
      aux->data.dia = 0;
      aux->data.mes = 0;
      aux->data.ano = 0;
      aux->hora.horas = 0;
      aux->hora.mins = 0;
      aux->duracao = 0;
      aux->sala = NULL;
      aux->inscritos = NULL;
      aux->next = NULL;
    }
    return aux;
}

void imprime_num_aluno(Next_aluno lista) {
  Next_aluno aux = lista->next;
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
  aluno->next = NULL;
}

Next_ptrs_exame cria_lista_inscricoes() {
  Next_ptrs_exame aux = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
  if (aux != NULL) {
    aux->exame = NULL;
    aux->next = NULL;
  }
  return aux;
}

void le_ficheiro_alunos(Next_aluno lista_alunos, Next_exame lista_exames) {
  FILE * fp;
  Next_aluno novoAluno;
  Next_exame l_exames;
  int i, id, num_exame;
  Next_ptrs_exame lista_inscricoes, l_inscricoes;
  fp = fopen("ficheiro_alunos.txt", "r");
  char num[100], c, string[200], s[2] = ",", *exame;

  while (fscanf(fp, "%[^,]", num) != EOF) {
    printf("NOVO ALUNO:\n");
    fseek(fp, 1, SEEK_CUR);
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    /*printf("%s\n", num);*/
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

    //solucao do sscanf

    l_exames = lista_exames;
    lista_inscricoes = cria_lista_inscricoes();
    l_inscricoes = lista_inscricoes;

    fscanf(fp, "%[^\n]", string);

    exame = strtok(string, s);
    num_exame = atoi(exame);
    while( exame != NULL ) {
      num_exame = atoi(exame);
      while (l_exames->next != NULL) {
        if  (l_exames->id == num_exame) {
          while (l_inscricoes->next != NULL) {
            l_inscricoes = l_inscricoes->next;
          }
          l_inscricoes->next = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
          l_inscricoes->next->exame = l_exames;
          printf("%d", l_inscricoes->next->exame->id);
          l_inscricoes->next->next = NULL;
        }
        l_exames = l_exames->next;
      }
      printf( "exame %s\n", exame);
      exame = strtok(NULL, s);
   }
   insere_aluno(lista_alunos, novoAluno);
  }
  fclose(fp);
}

int main() {
  Next_aluno lista_alunos;
  Next_exame lista_exames;
  lista_exames = cria_lista_exames();
  lista_alunos = cria_lista_alunos();

  le_ficheiro_alunos(lista_alunos, lista_exames);
  printf("LISTA DE ALUNOS:\n");
  imprime_num_aluno(lista_alunos);

}
