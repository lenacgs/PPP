//versao 2 da Func4

void apagar_exames(Next_exame lista_exames) {
  Data data_presente, data_exame;
  Next_exame aux = lista_exames, ant;
  int res;

  printf("Qual é o dia de hoje?:\nDia: ");
  scanf("%d", data_presente->dia);
  printf("Mês: ");
  scanf("%d", data_presente->mes);
  printf("Ano: ");
  scanf("%d", data_presente->ano);


//isto nao vai funcionar porque nao temos o ponteiro ant para conseguirmos aceder ao atual
  ant = aux;
  while (aux != NULL) {
    res = comparar_datas(data_presente, aux->data);
    if (res == 1) {
      ant->next = aux->next;
      free(aux);
    }
    aux = aux->next;
    ant = aux;

  }
}
