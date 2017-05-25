//funçao para testar a func1_apagar_alunos. a funcionar
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  int horas;
  int mins;
} Hora;


typedef struct node_exame *Ptr_exame;
typedef struct ptrs_exame *Next_ptrs_exame;
typedef struct ptrs_exame {
  Ptr_exame exame;
  Next_ptrs_exame next;
} Ptrs_exame;

typedef struct node_aluno *Ptr_aluno;
typedef struct ptrs_aluno *Next_ptrs_aluno;
typedef struct ptrs_aluno {
  Ptr_aluno aluno;
  Next_ptrs_aluno next;
}Ptrs_aluno;

typedef struct node_disciplina *Next_disciplina;
typedef struct node_disciplina{
  char *nome;
  char *docente;
  Next_disciplina next;
} Node_disciplina;

typedef struct node_aluno *Next_aluno;
typedef struct node_aluno {
  int num_aluno;
  char *curso;
  int ano_mat;
  char *regime;
  Next_ptrs_exame *inscricoes;
  Next_aluno next;
} Node_aluno;

typedef struct node_exame *Next_exame;
typedef struct node_exame{
  Node_disciplina *disciplina;
  char *epoca;
  Data data;
  Hora hora;
  int duracao;
  char *sala;
  Next_ptrs_aluno *inscritos;
  Next_exame next;
} Node_exame;


void insere_array(char *string, char *p_inicial, int len) {
  char *aux, *end, *i;
  int j=0;
  end = p_inicial + len - 1;
  aux = p_inicial;
  for (i=aux; i<end; i++) {
    *i = *(string+j);
    j++;
  }
}

void inserir_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = aluno;
}

void criar_aluno(Next_aluno lista_alunos, Next_exame lista_exames) {
    char *p_curso, *p_regime, string [30];
    int len, i, opcao;
    Next_aluno novoAluno, l_alunos = lista_alunos;
    Next_ptrs_exame l_inscricoes;

    printf("Aluno %d:\n", i);
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    novoAluno->num_aluno = (int)malloc(30 * sizeof(int));
    printf("Numero: ");
    scanf("%d", &(novoAluno->num_aluno)); /*certo*/

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    printf("Curso: ");
    scanf("%s", novoAluno->curso);

    printf("Ano de matricula: ");
    scanf("%d", &(novoAluno->ano_mat));

    novoAluno->regime = (char*)malloc(50*sizeof(int));
    printf("Regime: ");
    scanf("%s", novoAluno->regime);

    novoAluno->inscricoes = cria_lista_inscricoes();
    l_inscricoes = novoAluno->inscricoes;

    printf("Em quantos exames quer inscrever o aluno? ");
    scanf("%d", &opcao);
    for(i=0; i<opcao; i++) {
      associa_exame(l_inscricoes, lista_exames);
    }
    //para ter a certeza que os exames ficaram bem associados
    l_inscricoes = novoAluno->inscricoes->next;
    printf("LISTA DE EXAMES INSCRITOS:\n");
    while (l_inscricoes != NULL) {
      printf("Id: %d\n", l_inscricoes->exame->id);
      l_inscricoes = l_inscricoes->next;
    }
    insere_aluno(lista_alunos, novoAluno);
    escreve_ficheiro_alunos(lista_alunos, novoAluno);

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


void imprime_num_aluno(Next_aluno lista) {
    Next_aluno aux;
    int i;
    aux = lista->next; /*para saltar o no cabecalho*/
    i = 1;
    while(aux != NULL) {
        printf("%d. %d\n", i, aux->num_aluno);
        i++;
        aux = aux->next;
    }
}

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

int main() {
    Next_aluno lista_alunos, l, ant, actual;
    int n, i, num;
    lista_alunos = cria_lista_alunos();

    printf("Quantos alunos quer criar? ");
    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        printf("\nAluno %d:\n", i);
        criar_aluno(lista_alunos);
    }
    apagar_aluno(lista_alunos);

}
