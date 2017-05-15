#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//falta definir as structs de exames inscritos e alunos inscritos

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  int horas;
  int mins;
} Hora;

//Lista de ponteiros para exames
typedef struct node_exame *Ptr_exame;
typedef struct ptrs_exame *Next_ptrs_exame;
typedef struct ptrs_exame {
  Ptr_exame exame;
  Next_ptrs_exame next;
} Node_ptrs_exame;

//Lista de disciplinas
typedef struct node_disciplina *Next_disciplina;
typedef struct node_disciplina{
  char *nome;
  char *docente;
  Next_disciplina next;
} Node_disciplina;


//Lista de ponteiros para alunos
typedef struct node_aluno *Ptr_aluno;
typedef struct ptrs_aluno *Next_ptrs_aluno;
typedef struct ptrs_aluno {
  Ptr_aluno aluno;
  Next_ptrs_aluno next;
}Node_ptrs_aluno;

//Lista de alunos
typedef struct node_aluno *Next_aluno;
typedef struct node_aluno {
  int num_aluno;
  char *curso;
  int ano_mat;
  char *regime;
  Next_ptrs_exame inscricoes;
  Next_aluno next;
} Node_aluno;

//Lista de exames
typedef struct node_exame *Next_exame;
typedef struct node_exame{
  Node_disciplina *disciplina;
  char *epoca;
  Data data;
  Hora hora;
  int duracao;
  char *sala;
  Next_ptrs_aluno inscritos;    //ponteiro para lista de ponteiros
  Next_exame next;
} Node_exame;


void insere_aluno_ficheiro(Next_aluno lista_alunos, Next_aluno new) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (Next_aluno)malloc(sizeof(Node_aluno));
  aux = aux->next;
  aux->num_aluno = new->num_aluno;
  aux->curso = new->curso;
  aux->ano_mat = new->ano_mat;
  aux->regime = new->regime;
  aux->inscricoes = new->inscricoes;
  aux->next = NULL;
}

Next_ptrs_exame cria_lista_inscricoes() {
  Next_ptrs_exame novaLista = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
  if (novaLista != NULL) {
    novaLista->exame = NULL;
    novaLista->next = NULL;
  }
  return novaLista;
}

void ficheiro_alunos(Next_aluno lista_alunos) {
  FILE *file = fopen("ficheiro_alunos.txt", "r");
  Next_aluno novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));
  int num_aluno = (int)malloc(30*sizeof(int));
  char * curso = (char*)malloc(50*sizeof(char));
  int ano_mat = (int)malloc(30*sizeof(int));
  char * regime = (char*)malloc(50*sizeof(char));
  Next_ptrs_aluno inscricoes = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));

  while (fscanf(file, "%d", &num_aluno) != EOF) {
    fscanf(file, "%d", &num_aluno);
    novoAluno->num_aluno = num_aluno;

    fseek(file, 1, SEEK_CUR);

    fscanf(file, "%[^,\n]", curso);
    novoAluno->curso = (char*)malloc(50*sizeof(char));
    strcpy(novoAluno->curso, curso);

    fseek(file, 1, SEEK_CUR);

    fscanf(file, "%d", &ano_mat);
    novoAluno->ano_mat = ano_mat;

    fseek(file, 1, SEEK_CUR);

    fscanf(file, "%[^,\n]", regime);
    novoAluno->regime = (char*)malloc(50*sizeof(char));
    strcpy(novoAluno->regime, regime);

    //falta pensar na solução para a questão das inscrições dos alunos
    //obrigar o utilizador a inscrever alunos logo no início do programa

    novoAluno->inscricoes = cria_lista_inscricoes();
    insere_aluno_ficheiro(lista_alunos, novoAluno);
  }
  fclose(file);
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

int main() {
    Next_aluno lista_alunos = cria_lista_alunos();

    ficheiro_alunos(lista_alunos);
    imprime_num_aluno(lista_alunos);
}
