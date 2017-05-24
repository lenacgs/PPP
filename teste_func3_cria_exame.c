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



int verifica_sala(char *string, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inicio_nova, fim_nova, res;
  Next_exame l = lista_exames->next;

  while (l->next != NULL) {
    inicio = (l->hora.horas)* 60 + (l->hora.mins);
    fim = inicio + l->duracao;
    inicio_nova = (new_node->hora.horas)*60 + (new_node->hora.mins);
    fim_nova = inicio_nova + new_node->duracao;
    //a sala ser igual
    if (strcmp(string, l->sala)==0) {
      //a data ser igual
      if ((l->data.dia == new_node->data.dia) && (l->data.mes == new_node->data.mes) && (l->data.ano == new_node->data.ano)) {
        //a hora coincidir
        if ((inicio_nova>=inicio && inicio_nova<=fim) || (fim_nova>=inicio && fim_nova<=fim) || (inicio_nova<=inicio && fim_nova>=fim)) {
          return 0;
        }
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
  printf("LISTA DE EXAMES EXISTENTES:\n");
  while(l != NULL) {
    printf("\nID: %d", l->id);
    printf("\nnNOME: %s", l->disciplina->nome);
    printf("\nEPOCA: %s", l->epoca);
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

  while(l_inscritos->next != NULL) {
    l_inscritos = l_inscritos->next;
  }

  new_node = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  l_inscritos->next = new_node;
  new_node->aluno = l_alunos;
  new_node->next = NULL;

  return;
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

void cria_exame(Next_exame lista_exames, Next_aluno lista_alunos, Next_disciplina lista_disciplinas) {
    char *p_epoca, string[30];
    int len, res, i, num;
    Next_ptrs_aluno l_inscritos;
    Next_disciplina l_disciplinas = lista_disciplinas->next; /*este next e super importante*/
    Next_exame exame, l_exames = lista_exames->next;
    exame = (Next_exame)malloc(sizeof(Node_exame));

    printf("ID: ");
    scanf("%d", &(exame->id));

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
    printf("Epoca: ");
    scanf("%s", exame->epoca);

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
    exame->sala = (char*)malloc(100*sizeof(char));

    res = verifica_sala(string, lista_exames, exame);
    while (res != 1) {
      getchar();
      printf("\nA sala nao esta disponivel. Escolha outra sala: ");
      scanf("%s", string);
      res = verifica_sala(string, lista_exames, exame);
    }
    strcpy(exame->sala, string);

    getchar();
    exame->inscritos = cria_lista_inscritos();
    printf("Quantos alunos quer inscrever?: ");
    scanf("%d", &num);

    for (i=1; i<=num; i++) {
      inscreve_aluno(exame->inscritos, lista_alunos);
    }
    l_inscritos = exame->inscritos->next;
    printf("LISTA DE ALUNOS INSCRITOS:\n");
    while (l_inscritos != NULL) {
      printf("%d\n", l_inscritos->aluno->num_aluno);
      l_inscritos = l_inscritos->next;
    }
    insere_exame(lista_exames, exame);
}
void le_ficheiro_disciplinas (Next_disciplina lista_disciplinas) {
  FILE *fp;
  Next_disciplina novaDisciplina;
  fp = fopen("ficheiro_disciplinas.txt", "r");
  char nome[100];
  printf("LEITURA DA LISTA DE DISCIPLINAS:\n");
  while(fscanf(fp, " %[^,\n]", nome) != EOF) {
    fseek(fp, 1, SEEK_CUR);
    novaDisciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));

    novaDisciplina->nome = (char*)malloc(50*sizeof(char));
    strcpy(novaDisciplina->nome, nome);
    printf("NOME DA DISCIPLINA: %s\n", novaDisciplina->nome);

    novaDisciplina->docente = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novaDisciplina->docente);
    printf("DOCENTE DA DISCIPLINA: %s\n", novaDisciplina->docente);
    fseek(fp, 1, SEEK_CUR);

    insere_disciplina(lista_disciplinas, novaDisciplina);
  }
  fclose(fp);
}

 void le_ficheiro_alunos(Next_aluno lista_alunos) {
  FILE * fp;
  Next_aluno novoAluno;
  int i, id, num_exame;
  Next_ptrs_exame lista_inscricoes, l_inscricoes;
  fp = fopen("ficheiro_alunos.txt", "r");
  char num[100], c, string[200], s[2] = ",", *exame;

  printf("LEITURA DA LISTA DE ALUNOS:\n");
  while (fscanf(fp, " %[^,]", num) != EOF) {
    fseek(fp, 1, SEEK_CUR);
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    novoAluno->num_aluno = atoi(num);
    printf("NUMERO DE ALUNO: %d\n", novoAluno->num_aluno);

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->curso);
    printf("CURSO: %s\n", novoAluno->curso);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,]", &(novoAluno->ano_mat));
    printf("ANO DE MATRICULA: %d\n", novoAluno->ano_mat);
    fseek(fp, 1, SEEK_CUR);

    novoAluno->regime = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->regime);
    printf("REGIME: %s\n", novoAluno->regime);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%[^\n]", string);

   insere_aluno(lista_alunos, novoAluno);
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

  printf("LEITURA DA LISTA DE EXAMES: \n");

  while(fscanf(fp, " %[^,]", id) != EOF) {
    l_disciplinas = lista_disciplinas->next;

    novoExame = (Next_exame)malloc(sizeof(Node_exame));
    fseek (fp, 1, SEEK_CUR);
    novoExame->id = atoi(id);
    printf("ID: %d\n", novoExame->id);

    novoExame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    fscanf(fp, "%[^,]", disciplina);

    while (l_disciplinas != NULL) {

      if (strcmp(l_disciplinas->nome, disciplina) == 0) {
        novoExame->disciplina = l_disciplinas;
      }
      l_disciplinas = l_disciplinas->next;
    }
    printf("DISCIPLINA: %s\n", novoExame->disciplina->nome);
    fseek(fp, 1, SEEK_CUR);

    novoExame->epoca = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoExame->epoca);
    printf("EPOCA: %s\n", novoExame->epoca);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,\n]", &(novoExame->data.dia));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->data.mes));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->data.ano));
    fseek(fp, 1, SEEK_CUR);
    printf("DATA: %d.%d.%d\n", novoExame->data.dia, novoExame->data.mes, novoExame->data.ano);

    fscanf(fp, "%d[^,\n]", &(novoExame->hora.horas));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->hora.mins));
    fseek(fp, 1, SEEK_CUR);
    printf("HORAS: %dh %dmin\n", novoExame->hora.horas, novoExame->hora.mins);

    fscanf(fp, "%d[^,\n]", &(novoExame->duracao));
    fseek(fp, 1, SEEK_CUR);
    printf("DURACAO: %d\n", novoExame->duracao);

    /*novoExame->sala = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", id);
    fscanf(fp, "%[^,\n]", novoExame->sala);
    printf("SALA: %s\n", novoExame->sala);
    fseek(fp, 1, SEEK_CUR);*/

    novoExame->inscritos = cria_lista_inscritos();
    l_inscritos = novoExame->inscritos;

    fscanf(fp, "%[^\n]", string);


    numero = strtok(string, s);
    num = atoi(numero);
    while(numero != NULL ) {
      num = atoi(numero);
      printf("aluno inscrito: %d\n", num);
      l_alunos = lista_alunos->next;
      while (l_alunos != NULL) {
        if  (l_alunos->num_aluno == num) {
          while (l_inscritos->next != NULL) {
            l_inscritos = l_inscritos->next;
          }
          l_inscritos->next = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
          l_inscritos->next->aluno = l_alunos;
          l_inscritos->next->next = NULL;
        }
        l_alunos = l_alunos->next;
      }
      numero = strtok(NULL, s);
    }
    insere_exame(lista_exames, novoExame);
  }
  fclose(fp);
}

void le_ficheiro_inscricoes(Next_aluno lista_alunos, Next_exame lista_exames) {
  FILE *fp;
  fp = fopen("ficheiro_alunos.txt", "r");
  char lixo[100], *exame, string[100], s[2]= ",";
  int num_exame, i;
  Next_exame l_exames = lista_exames->next;
  Next_aluno l_alunos = lista_alunos->next;
  Next_ptrs_exame l_inscricoes;


  while (fscanf(fp, " %[^,]", lixo) != EOF) {
    //ciclo para ler os 4 primeiros parâmetros de uma linha (não interessam para as inscrições)
    for (i=0; i<4; i++) {
      fscanf(fp, "%[^,]", lixo);
      fseek(fp, 1, SEEK_CUR);
    }

    l_alunos->inscricoes = cria_lista_inscricoes();
    l_inscricoes = l_alunos->inscricoes;
    fscanf(fp, "%[^\n]", string); //le o que sobra da linha no ficheiro, passando-a para dentro de string

    exame = strtok(string, s); //separa o primeiro id de exame para dentro de exame
    num_exame = atoi(exame); //converte char para int
    while (exame != NULL) {
      num_exame = atoi(exame);
      l_exames = lista_exames->next;

      while (l_exames != NULL) {
        if  (l_exames->id == num_exame) {
          while (l_inscricoes->next != NULL) {
            l_inscricoes = l_inscricoes->next;
          }
          l_inscricoes->next = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
          l_inscricoes->next->exame = l_exames;
          l_inscricoes->next->next = NULL;
        }
        l_exames = l_exames->next;
      }
      exame = strtok(NULL, s);
   }
   l_inscricoes = l_alunos->inscricoes->next;
   printf("LISTA DE EXAMES EM QUE O ALUNO %d ESTA INSCRITO:\n", l_alunos->num_aluno);
   while (l_inscricoes != NULL) {
     printf("EXAME: %d\n", l_inscricoes->exame->id);
     l_inscricoes = l_inscricoes->next;
   }
   l_alunos = l_alunos->next;
  }
}


int main() {
  Next_disciplina lista_disciplinas;
  Next_aluno lista_alunos;
  Next_exame lista_exames;
  int n, i;

  /*criar lista de disciplinas*/
  lista_disciplinas = cria_lista_disciplinas();
  le_ficheiro_disciplinas(lista_disciplinas);
  printf("LEITURA DA LISTA DE DISCIPLINAS:\n");
  imprime_disciplinas(lista_disciplinas);

  /*criar lista de alunos*/
  lista_alunos = cria_lista_alunos();
  le_ficheiro_alunos(lista_alunos, lista_exames);
  printf("LEITURA DA LISTA DE ALUNOS:\n");
  imprime_num_aluno(lista_alunos);

  lista_exames = cria_lista_exames();
  le_ficheiro_exames(lista_exames, lista_disciplinas, lista_alunos);

  le_ficheiro_inscricoes(lista_alunos, lista_exames);

  printf("\nQuantos exames quer criar? ");
  scanf("%d", &n);

  for(i=1; i<=n; i++) {
    printf("Exame %d:\n", i);
    cria_exame(lista_exames, lista_alunos, lista_disciplinas);
  }
  imprime_exames(lista_exames);
}
