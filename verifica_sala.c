//função para verificar se uma sala esta ocupada


int verifica_sala(char *sala, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inico_nova, fim_nova;
  Next_exame l = lista_exames;
  while (l != NULL) {
    if ((strcmp(sala, l->sala)==0) && (l->data->dia == new_node->data->dia) && (l->data->mes == new_node->data->mes) && (l->data->ano == new_node->data->ano)) {
      inicio = (l->horas)* 60 + (l->minutos);
      fim = inicio + l->duracao;

      inicio_nova = (new_node->horas)*60 + (new_node->minutos);
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
}
