//nova versao de teste da func3. a atribuição da sala não funciona. e a inscricao do aluno na lista de inscritos tao nao, da segmentation fault
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


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

void insere_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = disciplina;
  disciplina->next = NULL;
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

Next_ptrs_aluno cria_lista_inscritos() {
  Next_ptrs_aluno aux;
  aux = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  if (aux != NULL) {
    aux->aluno = NULL;
    aux->next = NULL;
  }
  return aux;
}

int verifica_sala(char *sala, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inicio_nova, fim_nova;
  Next_exame l = lista_exames->next;

  while (l->next != NULL) {
    if ((strcmp(sala, l->sala)==0) && (l->data.dia == new_node->data.dia) && (l->data.mes == new_node->data.mes) && (l->data.ano == new_node->data.ano)) {
      inicio = (l->hora.horas)* 60 + (l->hora.mins);
      fim = inicio + l->duracao;
        printf("inicio fim %d %d\n", inicio, fim);

      inicio_nova = (new_node->hora.horas)*60 + (new_node->hora.mins);
      fim_nova = inicio_nova + new_node->duracao;
      printf("inicionova fimnova %d %d\n", inicio_nova, fim_nova);


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

    insere_disciplina(lista_disciplinas, disciplina);
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


void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista->next;
  int i=1;
  while (l != NULL) {
    printf("%d. %s\n", i, l->nome);
    i++;
    l = l->next;
  }
}

void insere_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = aluno;
  /* alternativa para o aux->next = aluno:
  aux->num_aluno = aluno->num_aluno;
  aux->curso = aluno->curso;
  aux->ano_mat = aluno->ano_mat;
  aux->regime = aluno->regime*/;
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

    insere_aluno(lista_alunos, aluno);
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

void imprime_exames(Next_exame lista) {
  Next_exame l;

  l = lista->next;
  while(l != NULL) {
    printf("\nnome: %s", l->disciplina->nome);
    printf("\nepoca: %s", l->epoca);
    l = l->next;
  }
}

void inscreve_aluno(Next_ptrs_aluno lista_ptrs, Next_aluno lista_alunos) {
  int i, num;
  Next_ptrs_aluno new_node, l_inscritos = lista_ptrs;
  Next_aluno l_alunos = lista_alunos->next;

  getchar();
  printf("Seleccione o aluno que pretende inscrever no exame:\n");
  imprime_num_aluno(lista_alunos);
  printf("Opcao: ");
  scanf("%d", &num);
  for (i=1; i<num; i++) {
    l_alunos = l_alunos->next;
  }

printf ("\nVai inscrever o aluno ->%d<-\n",l_alunos->num_aluno);

  while(l_inscritos->next != NULL) {
    l_inscritos = l_inscritos->next;
  }

  new_node = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  l_inscritos->next = new_node;
  new_node->aluno = l_alunos;
  new_node->next = NULL;

  printf ("\nInscreveu ->%d<-\n",new_node->aluno->num_aluno);

}

void criar_exame(Next_exame lista_exames, Next_aluno lista_alunos, Next_disciplina lista_disciplinas) {
    char *p_epoca, string[30];
    int len, res;
    int i, num;
    Next_disciplina l_disciplinas = lista_disciplinas->next; /*este next e super importante*/
    Next_exame exame;
    exame = (Next_exame)malloc(sizeof(Node_exame));

    exame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    printf("Disciplina: ");
    scanf("%s", string);

    while (l_disciplinas != NULL) {
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

    printf("Data: \nDia: ");
    scanf("%d", &(exame->data.dia));
    printf("Mes: ");
    scanf("%d", &(exame->data.mes));
    printf("Ano: ");
    scanf("%d", &(exame->data.ano));

    printf("Hora: \nHoras: ");
    scanf("%d", &(exame->hora.horas));
    printf("Minutos: ");
    scanf("%d", &(exame->hora.mins));

    printf("Duracao (em minutos): ");
    scanf("%d", &(exame->duracao));

    printf("Sala: ");
    scanf("%s", string);
    printf("string: %s\n", string);

    /*res = verifica_sala(string, lista_exames, exame);
    printf("res %d", res);
    if (res == 1)
      insere_array(string, exame->sala, len);
    else
        printf("A sala nao esta disponivel.");
*/
    getchar();
    printf("Quantos alunos quer inscrever?: ");
    scanf("%d", &num);
    lista_exames->inscritos = cria_lista_inscritos();
    for (i=1; i<=num; i++) {
      inscreve_aluno(lista_exames->inscritos, lista_alunos);
      printf("Ola");
    }

    imprime_num_aluno(lista_exames->inscritos->aluno);
    //while (lista_exames->inscritos != NULL) {
    //  printf("%d", lista_exames->inscritos->aluno->num_aluno);
    //}
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
  Next_disciplina lista_disciplinas;
  Next_aluno lista_alunos;
  Next_exame lista_exames;
  int n, i;

  /*criar lista de alunos*/
  lista_alunos = cria_lista_alunos();
  printf("Quantos alunos quer criar? ");
  scanf("%d", &n);

  for (i=1; i<=n; i++) {
      printf("Aluno %d:\n", i);
      criar_aluno(lista_alunos);
  }
  printf("Lista alunos:\n");
  imprime_num_aluno(lista_alunos);

  /*criar lista de disciplinas*/
  lista_disciplinas = cria_lista_disciplinas();
  printf("Quantas disciplinas quer criar? ");
  scanf("%d", &n);

  for (i=1; i<=n; i++) {
      printf("Disciplina %d:\n", i);
      criar_disciplina(lista_disciplinas);
  }
  printf("Lista disciplinas:\n");
  imprime_disciplinas(lista_disciplinas);

  lista_exames = cria_lista_exames();
  printf("\nQuantos exames quer criar? ");
  scanf("%d", &n);

  for(i=1; i<=n; i++) {
    printf("Exame %d:\n", i);
    criar_exame(lista_exames, lista_alunos, lista_disciplinas);
  }
  imprime_exames(lista_exames);
}
