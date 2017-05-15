// Func4 - Apagar exames que já tenham sido realizados;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void apagar_exames(Next_exame lista_exames, Next_aluno lista_alunos) {
  Data data_presente, data_exame;
  int num;
  Next_aluno l = lista_alunos, aluno;

  printf("De que aluno é que quer apagar os exames? ");
  imprime_alunos(lista_alunos);
  scanf("%d", num);
  for (i=0; i<num; i++) {
    l = l->next;
  }

  aluno = l;
  printf("Diga a data de hoje.");
  printf("\nDia: ");
  scanf("%d", &data_presente->dia);
  printf("\nMes: ");
  scanf("%d", &data_presente->mes);
  printf("\nAno: ");
  scanf("%d", &data_presente->ano);

  while (aluno->inscricoes->exame != NULL) {
    data_exame = aluno->incricoes->exame->data;

    Next_exame ant = aluno->inscricoes->exame;
    Next_exame actual = aluno->inscricoes->exame->next;
    if (comparar_datas(data_presente, data_exame) == 1) { //caso a data do exame seja menor que a data presente
      ant->next = actual->next;
      free (actual);
    }
    
    l->inscricoes->exame = l->inscricoes->exame->next;
  }

}
