#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Next_disciplina cria_lista_disciplinas() {
    Next_disciplina aux;
    aux = (Next_disciplina)malloc(sizeof(Node_disciplina));
    if (aux != NULL) {
        aux->docente = NULL;
        aux->nome = NULL;
        aux->next = NULL;
    }
    return aux;
}

void insere_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = disciplina;
  disciplina->next = NULL;
}

void le_ficheiro_disciplinas (Next_disciplina lista_disciplinas) {
  FILE *fp;
  Next_disciplina novaDisciplina;
  fp = fopen("ficheiro_disciplinas.txt", "r");
  char nome[100];
  printf("leitura lista de disciplinas\n");
  while(fscanf(fp, "%[^,\n]", nome) != EOF) {
    fseek(fp, 1, SEEK_CUR);
    novaDisciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));

    novaDisciplina->nome = (char*)malloc(50*sizeof(char));
    strcpy(novaDisciplina->nome, nome);
    printf("nome: %s\n", novaDisciplina->nome);

    novaDisciplina->docente = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novaDisciplina->docente);
    printf("docente: %s\n", novaDisciplina->docente);
    fseek(fp, 1, SEEK_CUR);

    insere_disciplina(lista_disciplinas, novaDisciplina);
  }
  fclose(fp);
}

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

void le_ficheiro_alunos(Next_aluno lista_alunos) {
  FILE * fp;
  Next_aluno novoAluno;
  fp = fopen("ficheiro_alunos.txt", "r");
  char num[100];
  printf("Leitura da lista de alunos\n");

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

void insere_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = aluno;
  aluno->next = NULL;
}

void imprime_exames(Next_exame lista) {
  Next_exame l = lista->next;
  int i=1;

  while (l != NULL) {
    printf("%d. %s, %s\n", i, l->disciplina->nome, l->epoca);
    i++;
    l = l->next;
  }
}

Next_exame cria_lista_exames() {
  Next_exame aux = (Next_exame)malloc(sizeof(Node_exame));

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

void insere_exame(Next_exame lista_exames, Next_exame exame) {
  Next_exame aux = lista_exames;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = exame;
  exame->next = NULL;
}

Next_ptrs_aluno cria_lista_inscritos() {
  Next_ptrs_aluno aux = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  if (aux != NULL) {
    aux->aluno = NULL;
    aux->next = NULL;
  }
  return aux;
}

void le_ficheiro_exames(Next_exame lista_exames, Next_disciplina lista_disciplinas, Next_aluno lista_alunos) {
  FILE *fp;
  Next_exame novoExame;
  Next_disciplina l_disciplinas = lista_disciplinas;
  Next_aluno l_alunos = lista_alunos;
  Next_ptrs_aluno lista_inscritos, l_inscritos;
  fp = fopen("ficheiro_exames.txt", "r");
  char disciplina[100], c, string[100];
  int i, num, id;

  printf("leitura da lista de exames: \n");

  while(fscanf(fp, "%d[^,]", &id) != EOF) {
    printf("ola");
    novoExame = (Next_exame)malloc(sizeof(Node_exame));
    fseek (fp, 1, SEEK_CUR);
    novoExame->id = id;

    novoExame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    fscanf(fp, "%[^,]", disciplina);

    while (l_disciplinas != NULL) {
      if (strcmp(l_disciplinas->nome, disciplina) == 0) {
        novoExame->disciplina = l_disciplinas;
      }
      l_disciplinas = l_disciplinas->next;
    }
    printf("disciplina: %s\n", novoExame->disciplina->nome);
    fseek(fp, 1, SEEK_CUR);

    novoExame->epoca = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoExame->epoca);
    printf("epoca: %s\n", novoExame->epoca);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,\n]", &(novoExame->data.dia));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->data.mes));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->data.ano));
    fseek(fp, 1, SEEK_CUR);
    printf("data: %d.%d.%d\n", novoExame->data.dia, novoExame->data.mes, novoExame->data.ano);

    fscanf(fp, "%d[^,\n]", &(novoExame->duracao));
    fseek(fp, 1, SEEK_CUR);
    printf("duração: %d\n", novoExame->duracao);

    novoExame->sala = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoExame->sala);
    printf("sala: %s\n", novoExame->sala);
    fseek(fp, 1, SEEK_CUR);

    lista_inscritos = cria_lista_inscritos();
    l_inscritos = lista_inscritos;
    c = getc(fp);
    i=0;
    while (c != '\n') {
      if (c != ',') {
        string[i] = c;
        i++;
      }
      else  {
        num = atoi(string);
        while (l_alunos->next != NULL) {
          if  (l_alunos->num_aluno == num) {
            while (l_inscritos->next != NULL) {
              l_inscritos = l_inscritos->next;
            }
            l_inscritos->aluno = l_alunos;
            l_inscritos->next = NULL;
          }
        }
      }
    }
  }
  fclose(fp);
}

int main() {
  Next_exame lista_exames = cria_lista_exames();
  Next_disciplina lista_disciplinas = cria_lista_disciplinas();
  Next_aluno lista_alunos = cria_lista_alunos();

  le_ficheiro_disciplinas(lista_disciplinas);
  le_ficheiro_alunos(lista_alunos);
  le_ficheiro_exames(lista_exames, lista_disciplinas, lista_alunos);
  printf("impressao final: \n");
  imprime_exames(lista_exames);
  return 0;
}
