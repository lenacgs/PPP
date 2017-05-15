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

void imprime_array(char *string) { //recebe ponteiro para primeiro elemento do array
  char *ptr, *endptr;
  int size;

  size = strlen(string);
  endptr = string + size - 1;

  for (ptr=string; ptr<=endptr; ptr++) {
    printf("%c", *ptr);
  }
}

void insere_disciplina_ficheiro(Next_disciplina lista_disciplinas, Next_disciplina new) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (Next_disciplina)malloc(sizeof(Node_disciplina));
  aux = aux->next;
  aux->nome = new->nome;
  aux->docente = new->docente;
  aux->next = NULL;
}


void ficheiro_disciplinas(Next_disciplina lista_disciplinas) {
  FILE *file = fopen("ficheiro_disciplinas.txt", "r");
  Next_disciplina novaDisc = (Next_disciplina)malloc(sizeof(Node_disciplina));
  char *nome = (char*)malloc(50*sizeof(char));
  char *docente = (char*)malloc(50*sizeof(char));

  while (fscanf(file, "%[^,\n]", nome) != EOF) {
    fscanf(file, "%[^,\n]", nome);
    novaDisc->nome = (char*)malloc(50*sizeof(char));
    strcpy(novaDisc->nome, nome);

    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", docente);
    novaDisc->docente = (char*)malloc(50*sizeof(char));
    strcpy(novaDisc->docente, docente);

    insere_disciplina_ficheiro(lista_disciplinas, novaDisc);
  }
  fclose(file);
}

void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista;
  int i=1;
  while (l != NULL) {
    printf("%d.", i);
    imprime_array(l->nome);
    i++;
    l = l->next;
  }
}

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


int main() {
    Next_disciplina lista_disciplinas = cria_lista_disciplinas();

    ficheiro_disciplinas(lista_disciplinas);

    imprime_disciplinas(lista_disciplinas);
    return 0;
}
