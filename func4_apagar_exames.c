//ja funcionar
void apagar_exames(Next_exame lista_exames) {
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
  actual = l_exames->next;
  while(actual != NULL) {
    printf("Data do exame actual: %d-%d-%d\n", actual->data.dia, actual->data.mes, actual->data.ano);
    res = comparar_datas(data_presente, actual->data);
    printf("res: %d\n", res);
    if (res == 1) {
      ant->next = actual->next;
      free(actual);
    }
    ant = ant->next;
    actual = actual->next;
  }
}
