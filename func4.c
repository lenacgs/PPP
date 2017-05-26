//TODINHA CERTA, ESCREVE NO FICHEIRO
void apaga_exames(Next_exame lista_exames) {
  Data data_presente, data_exame;
  Next_exame l_exames, ant, actual;
  int res;

  printf("Qual é o dia de hoje?:\nDia: ");
  scanf("%d", &(data_presente.dia));
  printf("Mês: ");
  scanf("%d", &(data_presente.mes));
  printf("Ano: ");
  scanf("%d", &(data_presente.ano));

  l_exames = lista_exames;
  ant = l_exames;
  actual = ant->next;
  while(actual != NULL) {
    printf("Data do exame actual: %d-%d-%d\n", actual->data.dia, actual->data.mes, actual->data.ano);
    res = comparar_datas(data_presente, actual->data);
    printf("res: %d\n", res);
    if (res == 1) {
      ant->next = actual->next;
      free(actual);
      actual = ant->next;
    }
    else {
      actual = actual->next;
      ant = ant->next;
    }
  }
  update_ficheiro_exames(lista_exames);
}
