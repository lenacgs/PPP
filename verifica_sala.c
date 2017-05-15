//função para verificar se uma sala esta ocupada

int verifica_sala(char *sala, Next_exame lista_exames, Next_exame new_node) {
  Next_exame l = lista_exames;
  while (l != NULL) {
    if ((strcmp(sala, l->sala)==0) && (l->data->dia == new_node->data->dia) && (l->data->mes == new_node->data->mes) && (l->data->ano == new_node->data->ano)) {
      int((l->duracao) / 60;)
    }
    else {
    }
  }
}
