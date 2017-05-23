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
