//nova versao de teste da func3. a atribuição da sala não funciona. e a inscricao do aluno na lista de inscritos tao nao, da segmentation fault
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

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

void insere_exame(Next_exame lista_exames, Next_exame exame) {
  Next_exame aux = lista_exames;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = exame;
  exame->next = NULL;
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


int verifica_sala(char *string, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inicio_nova, fim_nova;
  Next_exame l = lista_exames->next;
  while (l != NULL) {
    printf("sala: %s\n", string);
    if ((strcmp(string, l->sala)==0) && (l->data.dia == new_node->data.dia) && (l->data.mes == new_node->data.mes) && (l->data.ano == new_node->data.ano)) {
      inicio = (l->hora.horas)* 60 + (l->hora.mins);
      fim = inicio + l->duracao;

      inicio_nova = (new_node->hora.horas)*60 + (new_node->hora.mins);
      fim_nova = inicio_nova + new_node->duracao;

      if (inicio_nova>inicio && inicio_nova<fim) {
        return 0;
      }
      if (fim_nova>inicio && fim_nova<fim) {
        return 0;
      }
      if (inicio_nova<inicio && fim_nova>fim) {
        return 0;
      }
      else {
        return 1;
      }
    }
  l = l->next;
  }
  return 1;
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

void le_ficheiro_exames(Next_exame lista_exames, Next_disciplina lista_disciplinas, Next_aluno lista_alunos) {
  FILE *fp;
  Next_exame novoExame;
  Next_disciplina l_disciplinas = lista_disciplinas->next;
  Next_aluno l_alunos = lista_alunos;
  Next_ptrs_aluno lista_inscritos, l_inscritos;
  fp = fopen("ficheiro_exames.txt", "r");
  char disciplina[100], c, string[100], id[100], s[2]= ",", *numero;
  int i, num, num_aluno;


  if (fp == NULL) {
    printf("Nao conseguiu abrir o ficheiro ->\"ficheiro_exames.txt\"<- \\\n");
    return;
  }

printf("Conseguiu abrir o ficheiro ->\"ficheiro_exames.txt\"<- \\\n");
  printf("leitura da lista de exames: \n");

  while(fscanf(fp, "%[^,]", id) != EOF) {
    printf("NOVO EXAME:\n");
    l_disciplinas = lista_disciplinas->next;

    novoExame = (Next_exame)malloc(sizeof(Node_exame));
    fseek (fp, 1, SEEK_CUR);
    novoExame->id = atoi(id);

    novoExame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    fscanf(fp, "%[^,]", disciplina);
    printf("Disciplina: %s\n", disciplina);

    while (l_disciplinas != NULL) {
      printf("Compara a disciplina com %s\n",l_disciplinas->nome );
      if (strcmp(l_disciplinas->nome, disciplina) == 0) {
        novoExame->disciplina = l_disciplinas;
      }
      l_disciplinas = l_disciplinas->next;
    }
    printf("Disciplina final: %s\n", novoExame->disciplina->nome);
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

    fscanf(fp, "%[^\n]", string);

    numero = strtok(string, s);
    num_aluno = atoi(numero);
    while( numero != NULL ) {
      num_aluno = atoi(numero);
      while (l_alunos->next != NULL) {
        if  (l_alunos->num_aluno == num_aluno) {
          while (l_inscritos->next != NULL) {
            l_inscritos = l_inscritos->next;
          }
          l_inscritos->next = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
          l_inscritos->next->aluno = l_alunos;
          printf("%d", l_inscritos->next->aluno->num_aluno);
          l_inscritos->next->next = NULL;
        }
        l_alunos = l_alunos->next;
      }
      printf( "aluno inscrito: %d\n", num_aluno);
      numero = strtok(NULL, s);
    }
    insere_exame(lista_exames, novoExame);
  }
  fclose(fp);
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
  return;
}

void cria_exame(Next_exame lista_exames, Next_aluno lista_alunos, Next_disciplina lista_disciplinas) {
    char *p_epoca, string[30];
    int len, res;
    int i, num;
    Next_ptrs_aluno l_inscritos;
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
    printf("sala: %s\n", string);

    res = verifica_sala(string, lista_exames, exame);
    printf("res %d", res);
    if (res == 1)
      strcpy(exame->sala, string);
    else
        printf("A sala nao esta disponivel.");

    getchar();
    printf("Quantos alunos quer inscrever?: ");
    scanf("%d", &num);
    lista_exames->inscritos = cria_lista_inscritos();
    for (i=1; i<=num; i++) {
      inscreve_aluno(lista_exames->inscritos, lista_alunos);

    }
    l_inscritos = lista_exames->inscritos->next;
    while (l_inscritos != NULL) {
      printf("%d\n", l_inscritos->aluno->num_aluno);
      l_inscritos = l_inscritos->next;
    }
    insere_exame(lista_exames, exame);

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



  /*criar lista de disciplinas*/
  lista_disciplinas = cria_lista_disciplinas();
  le_ficheiro_disciplinas(lista_disciplinas);
  printf("Lista disciplinas:\n");
  imprime_disciplinas(lista_disciplinas);

  lista_exames = cria_lista_exames();
  le_ficheiro_exames(lista_exames, lista_disciplinas, lista_alunos);

  /*criar lista de alunos*/
  lista_alunos = cria_lista_alunos();
  le_ficheiro_alunos(lista_alunos, lista_exames);
  printf("Lista alunos:\n");
  imprime_num_aluno(lista_alunos);
  
  printf("\nQuantos exames quer criar? ");
  scanf("%d", &n);

  for(i=1; i<=n; i++) {
    printf("Exame %d:\n", i);
    cria_exame(lista_exames, lista_alunos, lista_disciplinas);
  }
  imprime_exames(lista_exames);
}
