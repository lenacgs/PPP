Next_sala cria_lista_salas() {
  Next_sala aux = (Next_sala)malloc(sizeof(Node_sala));
  if (aux != NULL) {
    aux->sala = NULL;
    aux->next = NULL;
  }
  return aux;
}
