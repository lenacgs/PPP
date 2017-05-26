//func2 apagar disciplina
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista->next;
  int i=1;
  while (l != NULL) {
    printf("%d. %s\n", i, l->nome);
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

void insere_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = disciplina;
  disciplina->next = NULL;
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

void update_ficheiro_disciplinas(Next_disciplina lista_disciplinas) {
  Next_disciplina l_disciplinas = lista_disciplinas->next;
  FILE *fp = fopen("ficheiro_disciplinas.txt", "w");
  while (l_disciplinas != NULL) {
    fprintf(fp, "%s,%s\n", l_disciplinas->nome, l_disciplinas->docente);
    l_disciplinas = l_disciplinas->next;
  }
  fclose(fp);
}

void apagar_disciplinas(Next_disciplina lista_disciplinas) {
  Next_disciplina l_disciplinas, ant, actual, disciplina_apagar;
  int i, num;

  printf("Qual das disciplinas deseja apagar?\n");
  imprime_disciplinas(lista_disciplinas);
  printf("Opcao: ");
  scanf("%d", &num);
  l_disciplinas = lista_disciplinas;
  for(i=0; i<num; i++) {
    l_disciplinas = l_disciplinas->next;
  }
  disciplina_apagar = l_disciplinas;
  l_disciplinas = lista_disciplinas;
  ant = l_disciplinas;
  actual = ant->next;
  while(actual != NULL) {
   if (actual->nome == disciplina_apagar->nome) {
     ant->next = actual->next;
     free(actual);
     actual = ant->next;
   }
   else {
     actual = actual->next;
     ant = ant->next;
   }
  }
  update_ficheiro_disciplinas(lista_disciplinas);
}

int main() {
  Next_disciplina lista_disciplinas;
  lista_disciplinas = cria_lista_disciplinas();
  le_ficheiro_disciplinas(lista_disciplinas);

  apagar_disciplinas(lista_disciplinas);
  printf("Lista de disciplinas:\n");
  imprime_disciplinas(lista_disciplinas);
}
