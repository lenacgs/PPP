
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Next_ptrs_exame cria_lista_inscricoes() {
  Next_ptrs_exame aux = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
  if (aux != NULL) {
    aux->exame = NULL;
    aux->next = NULL;
  }
  return aux;
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

Next_ptrs_aluno cria_lista_inscritos() {
  Next_ptrs_aluno aux;
  aux = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  if (aux != NULL) {
    aux->aluno = NULL;
    aux->next = NULL;
  }
  return aux;
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
      aux->salas = NULL;
      aux->inscritos = NULL;
      aux->next = NULL;
    }
    return aux;
}

void insere_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }

  aux->next = aluno;
  aluno->next = NULL;
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

void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista->next;
  int i=1;
  while (l != NULL) {
    printf("%d. %s\n", i, l->nome);
    i++;
    l = l->next;
  }
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

void imprime_id_exames(Next_exame lista) {
  Next_exame l;

  l = lista->next;
  while(l != NULL) {
    printf("id: %d\n", l->id);
    l = l->next;
  }
}

/*int verifica_sala(char *string, Next_exame lista_exames, Next_exame new_node) {
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
}*/

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
      //printf("aluno inscrito: %d\n", num);
      l_alunos = lista_alunos->next;
      while (l_alunos != NULL) {
        if  (l_alunos->num_aluno == num) {
          while (l_inscritos->next != NULL) {
            l_inscritos = l_inscritos->next;
          }
          l_inscritos->next = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
          l_inscritos->next->aluno = l_alunos;
          l_inscritos->next->next = NULL;
          printf("aluno inscrito: %d\n", l_inscritos->next->aluno->num_aluno);
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

void inscreve_desinscreve_aluno(Next_exame lista_exames, Next_aluno lista_alunos) {
  Next_exame l_exames = lista_exames;
  Next_aluno l_alunos, last_aluno;
  Next_ptrs_aluno l_inscritos, new_node, actual, ant;
  int n_exames, n_alunos, i, id_aluno, opcao, tag;

  printf("O que deseja?\n1. Inscrever aluno\n2. Desinscrever aluno\nOpcao: ");
  scanf("%d", &opcao);
  switch (opcao){
    case 1:
      printf("Seleccione o aluno que pretende inscrever: \n");
      imprime_num_aluno(lista_alunos);
      printf("Opcao: ");
      scanf("%d", &opcao);
      l_alunos = lista_alunos;
      for(i=0; i<opcao; i++) {
        l_alunos = l_alunos->next;
      }

      printf("Em quantos exames quer inscrever o aluno? ");
      scanf("%d", &n_exames);
      for (i=0; i<n_exames; i++) {
        printf("Seleccione o exame em que pretende inscrever o aluno: \n");
        imprime_id_exames(lista_exames);
        printf("Opcao: ");
        scanf("%d", &opcao);
        l_exames = lista_exames;
        for(i=0; i<opcao; i++) {
          l_exames = l_exames->next; //vai para o exame certo
        }

        //PROBLEMA: TEMOS QUE VERIFICAR PRIMEIRO SE O ALUNO QUE ELE QUER INSCREVER JÁ NÃO SE ENCONTRA NA LISTA DE INSCRITOS DESSE EXAME
        printf("Id do exame em q estamos: %d\n", l_exames->id);
        l_inscritos = l_exames->inscritos;
        tag = 0;
        while (l_inscritos->next != NULL) {
          if (l_inscritos->next->aluno->num_aluno == l_alunos->num_aluno)
            tag = 1;
          l_inscritos = l_inscritos->next;
        }

        if (tag == 0) {
          l_inscritos = l_exames->inscritos;
          while(l_inscritos->next != NULL) {
            l_inscritos = l_inscritos->next;
          }

          l_inscritos->next = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
          l_inscritos->next->aluno = l_alunos;
          l_inscritos->next->next = NULL;

          printf("Lista final inscritos:\n");
          l_inscritos = l_exames->inscritos;
          while(l_inscritos->next != NULL) {
            printf("Aluno inscrito: %d\n", l_inscritos->next->aluno->num_aluno);
            l_inscritos = l_inscritos->next;
          }
        }
        else {
          printf("Este aluno ja se encontra inscrito no exame de id: %d\n", l_exames->id);
        }
      }
      break;

    case 2:
      printf("Seleccione o aluno que pretende desinscrever: \n");
      imprime_num_aluno(lista_alunos);
      printf("Opcao: ");
      scanf("%d", &opcao);
      l_alunos = lista_alunos;
      for(i=0; i<opcao; i++) {
        l_alunos = l_alunos->next;
      }
      id_aluno = l_alunos->num_aluno;

      printf("De quantos exames quer desinscrever o aluno? ");
      scanf("%d", &n_exames);
      for (i=0; i<n_exames; i++) {
        printf("Seleccione o exame de que pretende desinscrever o aluno: \n");
        imprime_id_exames(lista_exames);
        printf("Opcao: ");
        scanf("%d", &opcao);
        l_exames = lista_exames;
        for(i=0; i<opcao; i++) {
          l_exames = l_exames->next;
        }
        printf("Id do exame em que estamos: %d\n", l_exames->id);

        tag = 0;
        l_inscritos = l_exames->inscritos;
        ant = l_inscritos;
        actual = ant->next;
        while(actual != NULL) {
          printf("Aluno com o qual estamos a comparar: %d\n", actual->aluno->num_aluno);
          if (actual->aluno->num_aluno == id_aluno) {
            tag = 1;
            printf("Aluno que tem o id igual: %d\n", actual->aluno->num_aluno);
            ant->next = actual->next;
            free(actual);
            actual = ant->next;
          }
          else {
            actual = actual->next;
            ant = ant->next;
          }
        }
        if (tag == 0)
          printf("Este aluno nao se encontra inscrito no exame de id %d\n.", l_exames->id);
    }
    tag = 0;
  }
}


  void listar_exames(Next_exame lista) {
    Next_exame l, ant, actual;
    int i=1, c;
    char *ptr, *disc, *ep, *doc;
    Next_ptrs_aluno inscritos;

    l = lista->next;
    printf("Lista de exames existentes:\n");
    while (l) { //lista os exames existentes na lista, juntamente com a epoca
      printf("%d. %s", i, l->disciplina->nome);
      i++;
      printf(", %s\n", l->epoca);
      l = l->next;
    }
    /*o exame devia ser identificado pelo id*/
    printf("\nEscolha o exame: ");
    scanf("%d", &c);

    l = lista;
    for (i=1; i<=c; i++) {
      l = l->next;
      printf("ciclo:\n");
      printf("id: %d\n", l->id);
    }

    printf("Informacao desse exame:\n ");
    printf("\nDisciplina: ");
    printf("%s", l->disciplina->nome);

    printf("\nDocente: ");
    printf("%s", l->disciplina->docente);

    printf("\nÉpoca: ");
    printf("%s", l->epoca);

    printf("\nData: ");
    printf("%d - %d - %d", l->data.dia, l->data.mes, l->data.ano);

    printf("\nHora: ");
    printf("%dh%d", l->hora.horas, l->hora.mins);

    /*printf("\nSala: ");
    printf("%s", l->sala);*/

    printf("\nDuração: %d minutos", l->duracao);

    printf("\nAlunos inscritos: \n");

    i=1;
    inscritos = l->inscritos->next;
    while (inscritos != NULL) {
      printf("%d. %d\n", i, inscritos->aluno->num_aluno);
      i++;
      inscritos = inscritos->next;
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
  printf("Lista disciplinas:\n");
  imprime_disciplinas(lista_disciplinas);

  /*criar lista de alunos*/
  lista_alunos = cria_lista_alunos();
  le_ficheiro_alunos(lista_alunos);
  printf("Lista alunos:\n");
  imprime_num_aluno(lista_alunos);

  lista_exames = cria_lista_exames();
  le_ficheiro_exames(lista_exames, lista_disciplinas, lista_alunos);
  le_ficheiro_inscricoes(lista_alunos, lista_exames);

  printf("Lista exames:\n");
  imprime_id_exames(lista_exames);

  inscreve_desinscreve_aluno(lista_exames, lista_alunos);

  printf("Toda a informacao relativa aos exames exitentes\n");
  listar_exames(lista_exames);
}
