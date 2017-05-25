int verifica_sala(char *string, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inicio_nova, fim_nova, res;
  Next_exame l_exames = lista_exames->next;
  Next_sala l;;

  while (l_exames->next != NULL) {
    l = l_exames->salas;
    inicio = (l_exames->hora.horas)* 60 + (l_exames->hora.mins);
    fim = inicio + l_exames->duracao;
    inicio_nova = (new_node->hora.horas)*60 + (new_node->hora.mins);
    fim_nova = inicio_nova + new_node->duracao;
    //a sala ser igual
    while (l->next != NULL) {
      if (strcmp(string, l->sala) == 0) {
        //a data ser igual
        if ((l_exames->data.dia == new_node->data.dia) && (l_exames->data.mes == new_node->data.mes) && (l_exames->data.ano == new_node->data.ano)) {
          //a hora coincidir
          if ((inicio_nova>=inicio && inicio_nova<=fim) || (fim_nova>=inicio && fim_nova<=fim) || (inicio_nova<=inicio && fim_nova>=fim)) {
            return 0;
          }
        }
      }
    }
    l = l->next;
  }
  return 1;
}
