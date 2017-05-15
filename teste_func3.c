/*teste func3, tem um problema na linha 286*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} Node_ptrs_exame;

typedef struct node_aluno *Ptr_aluno;
typedef struct ptrs_aluno *Next_ptrs_aluno;
typedef struct ptrs_aluno {
  Ptr_aluno aluno;
  Next_ptrs_aluno next;
}Node_ptrs_aluno;

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
  Next_disciplina *disciplina;
  char *epoca;
  Data data;
  Hora hora;
  int duracao;
  char *sala;
  Next_ptrs_aluno *inscritos;
  Next_exame next;
} Node_exame;

void imprime_num_aluno(Next_aluno lista) {
  Next_aluno aux;
  int i=1;

  aux = lista;
  while(aux != NULL) {
    printf("%d. %d\n", i, aux->num_aluno);
    i++;
    aux = aux->next;
  }
}

void inserir_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->nome = disciplina->nome;
  aux->docente = disciplina->docente;
  aux->next = NULL;


}
//função que lê strings: ou seja, quando um dos campos de uma struct é um ponteiro para char, esta é a função que lê o que está a seguir ao ponteiro

void imprime_array(char *string) { //recebe ponteiro para primeiro elemento do array
  char *ptr, *endptr;
  int size;

  size = strlen(string);
  endptr = string + size;

  for (ptr=string; ptr<=endptr; ptr++) {
    printf("%c", *ptr);
  }
}



void insere_array(char *string, char *p_inicial, int len) {
  char *aux, *end, *i;
  int j=0;
  end = p_inicial + len - 1;
  aux = p_inicial;
  for (i=aux; i<=end; i++) {
    *i = *(string+j);
    j++;
  }
}

int verifica_sala(char *sala, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inicio_nova, fim_nova;
  Next_exame l = lista_exames;
  printf("sdkjfkf");
  while (l->next != NULL) {
      printf("AJDfkadf");
    if ((strcmp(sala, l->sala)==0) && (l->data.dia == new_node->data.dia) && (l->data.mes == new_node->data.mes) && (l->data.ano == new_node->data.ano)) {
      inicio = (l->hora.horas)* 60 + (l->hora.mins);
      fim = inicio + l->duracao;
      printf("Ajdfkhs");

      inicio_nova = (new_node->hora.horas)*60 + (new_node->hora.mins);
      fim_nova = inicio_nova + new_node->duracao;

      if (inicio_nova>inicio && inicio_nova<fim) {
        return 0;
      }
      else if (fim_nova>inicio && fim_nova<fim) {
        return 0;
      }
      else if (inicio_nova<inicio && fim_nova>fim) {
        return 0;
      }
      else {
        return 1;
      }
  }
    else
        return 1;
}
  return 1;
}

void inserir_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = aluno;
}

void inscreve_aluno(Next_ptrs_aluno lista_ptrs, Next_aluno lista_alunos) {
  char c;
  int i;
  Next_ptrs_aluno new_node;
  Next_aluno l = lista_alunos;

  getchar();
  printf("Seleccione o aluno que pretende inscrever no exame:\n");
  imprime_num_aluno(lista_alunos);
  c = getchar();
  for (i=0; i<c; i++) {
    l = l->next;
  }

  new_node = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  if (new_node != NULL) {
    new_node->next = NULL;
    new_node->aluno = l;
  }
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

//funçao imprime disciplinas

void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista;
  int i=1;
  while (l->next != NULL) {
    printf("%d.", i);
    imprime_array(l->nome);
    i++;
    l = l->next;
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

void criar_disciplina(Next_disciplina lista_disciplinas) {
    char *p_nome, *p_docente, string[50];
    int len;
    Next_disciplina disciplina;
    disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));

    disciplina->nome = (char*)malloc(50*sizeof(char));
    p_nome = disciplina->nome;
    printf("Disciplina: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_nome, len);

    disciplina->docente = (char*)malloc(50*sizeof(char));
    p_docente = disciplina->docente;
    printf("Nome do docente: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_docente, len);
    printf("ola");

    inserir_disciplina(lista_disciplinas, disciplina);
}


Next_disciplina cria_lista_disciplinas() {
    Next_disciplina aux;
    aux = (Next_disciplina)malloc(sizeof(Node_disciplina));
    if (aux != NULL) {
        aux->docente = NULL;
        aux->nome = NULL;
    }
    return aux;
}




void criar_exame(Next_exame lista_exames, Next_aluno lista_alunos, Next_disciplina lista_disciplinas) {
    char *p_epoca, string [30], c;
    int len, res;
    int i, num;
    Next_disciplina l_disciplinas = lista_disciplinas, exame_disciplina;
    Next_exame exame;
    Next_ptrs_aluno exame_inscritos;
    exame = (Next_exame)malloc(sizeof(Node_exame));



    exame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    printf("Disciplina: ");
    scanf("%s", string);
    while (l_disciplinas != NULL) {
        printf("ola");
      if (strcmp(l_disciplinas->nome, string) == 0) {
        exame->disciplina = l_disciplinas;
      }
      l_disciplinas = l_disciplinas->next;
    }

    exame->epoca = (char*)malloc(50*sizeof(char));
    p_epoca = exame->epoca;
    printf("Epoca: ");
    scanf("%s", string);
    len = strlen(string);
    insere_array(string, p_epoca, len);

    printf("Data: Dia: ");
    scanf("%d", &(exame->data.dia));
    printf("Mes: ");
    scanf("%d", &(exame->data.mes));
    printf("Ano: ");
    scanf("%d", &(exame->data.ano));

    printf("Hora: Horas: ");
    scanf("%d", &(exame->hora.horas));
    printf("Minutos: ");
    scanf("%d", &(exame->hora.mins));

    printf("Duracao (em minutos): ");
    scanf("%d", &(exame->duracao));

    printf("Sala: ");
    scanf("%s", string);
    len = strlen(string);
    printf("len %d", len);
    res = verifica_sala(string, lista_exames, exame);
    printf("res %d", res);
    if (res == 1)
      insere_array(string, exame->sala, len);
    else
        printf("A sala nao esta disponivel.");

    getchar();
    printf("Quantos alunos quer inscrever?: ");
    scanf("%d", &num);
    for (i=1; i<=num; i++) {
        printf("\nAluno %d:", i);
        inscreve_aluno(lista_exames->inscritos, lista_alunos);
    }
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

int main() {
  Next_aluno lista_alunos;
  Next_disciplina lista_disciplinas;
  Next_exame lista_exames;
  int n, i;

  lista_alunos = cria_lista_alunos();
  printf("Quantos alunos quer criar? ");
  scanf("%d", &n);

  for (i=1; i<=n; i++) {
    printf("Aluno %d:\n", i);
    criar_aluno(lista_alunos);
  }

  lista_disciplinas = cria_lista_disciplinas();
  printf("Quantas disciplinas quer criar? ");
  scanf("%d", &n);

  for (i=1; i<=n; i++) {
    printf("Disciplina %d:\n", i);
    criar_disciplina(lista_disciplinas);
  }
  imprime_disciplinas(lista_disciplinas);
  lista_exames = cria_lista_exames();
  printf("Quantos exames deseja criar?");
  scanf("%d", &n);
  for (i=1; i<=n; i++) {
    printf("Exame:\n");
    criar_exame(lista_exames, lista_alunos, lista_disciplinas);
  }
}
