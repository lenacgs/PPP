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

void criar_aluno(Next_aluno lista_alunos) {
    char *p_curso, *p_regime, string [30];
    int len;
    Next_aluno aluno;
    aluno = (Next_aluno)malloc(sizeof(Node_aluno));

    aluno->num_aluno = (int)malloc(30 * sizeof(int));
    printf("Numero: ");
    scanf("%d", &(aluno->num_aluno)); /*certo*/

    aluno->curso = (char*)malloc(50*sizeof(char));
    p_curso = aluno->curso;
    printf("Curso: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_curso, len);

    printf("Ano de matricula: ");
    scanf("%d", &(aluno->ano_mat));

    printf("Regime: ");
    aluno->regime = (char*)malloc(50*sizeof(int));
    p_regime = aluno->regime;
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_regime, len);

    inserir_aluno(lista_alunos, aluno);
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

    /*l = lista_alunos;
    printf("Escolha o aluno que quer apagar: \n");
    imprime_num_aluno(lista_alunos);
    scanf("%d", &num);
    for (i=0; i<num; i++) {
      ant = l;
      actual = l->next;
    }*/

    apagar_aluno(lista_alunos);

}
