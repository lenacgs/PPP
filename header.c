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

//Lista de alunos
typedef struct node_aluno *Next_aluno;
typedef struct node_aluno {
  int num_aluno;
  char *curso;
  int ano_mat;
  char *regime;
  Next_ptrs_exame *inscricoes;
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
  Next_ptrs_aluno *inscritos;    //ponteiro para lista de ponteiros
  Next_exame next;
} Node_exame;

//Lista de disciplinas
typedef struct node_disciplina *Next_disciplina;
typedef struct node_disciplina{
  char *nome;
  char *docente;
  Next_disciplina next;
} Node_disciplina;


//Lista de ponteiros para exames
typedef struct node_exame *Ptr_exame;
typedef struct ptrs_exame *Next_ptrs_exame;
typedef struct ptrs_exame {
  Ptr_exame exame;
  Next_ptrs_exame next;
} Node_ptrs_exame;


//Lista de ponteiros para alunos
typedef struct node_aluno *Ptr_aluno;
typedef struct ptrs_aluno *Next_ptrs_aluno;
typedef struct ptrs_aluno {
  Ptr_aluno aluno;
  Next_ptrs_aluno next;
} Node_ptrs_aluno;

void imprime_num_aluno(Node_aluno lista);
void inscreve_aluno(Node_exame exame, /*lista de alunos em memoria (l)*/);
void insere_novo_exame(Node_exame lista_exames, Node_aluno lista_alunos, Node_disciplina lista_disciplinas); //unfinished
void insere_array(char *string, char *p_disciplina, int len);
void imprime_exames(Node_exame lista);
void imprime_array(char *string);
void listar_alunos(Node_exame lista_exames);
void menu();
