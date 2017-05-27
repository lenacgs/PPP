int verifica_sala(char *string, Next_exame lista_exames, Next_exame new_node) {
  int inicio, fim, inicio_nova, fim_nova;
  Next_exame l_exames = lista_exames->next;
  Next_sala l_salas;

  printf("Comecou a func verifica_sala\n");

  while (l_exames != NULL) {
    printf("Entrou dentro de um novo node_exame\n");
    l_salas = l_exames->salas->next;
    //calcular os inicios e fins em minutos
    inicio = (l_exames->hora.horas)* 60 + (l_exames->hora.mins);
    fim = inicio + l_exames->duracao;
    inicio_nova = (new_node->hora.horas)*60 + (new_node->hora.mins);
    fim_nova = inicio_nova + new_node->duracao;
    //a sala ser igual
    while (l_salas != NULL) {
      printf("A nova sala %s vai ser comparada com a sala %s do exame %d.\n", string, l_salas->sala, l_exames->id);
      if (strcmp(string, l_salas->sala) == 0) {
        //a data ser igual
        if ((l_exames->data.dia == new_node->data.dia) && (l_exames->data.mes == new_node->data.mes) && (l_exames->data.ano == new_node->data.ano)) {
          //a hora coincidir
          if ((inicio_nova>=inicio && inicio_nova<=fim) || (fim_nova>=inicio && fim_nova<=fim) || (inicio_nova<=inicio && fim_nova>=fim)) {
            return 0;
          }
        }
      }
      l_salas = l_salas->next;
    }
    l_exames = l_exames->next;
  }
  printf("A sala não está ocupada\n");
  return 1;
}
