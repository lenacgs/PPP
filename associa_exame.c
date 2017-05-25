void associa_exame(Next_ptrs_exame lista_ptrs, Next_exame lista_exames) {
  Next_ptrs_exame new_node, l_inscricoes = lista_ptrs;
  Next_exame l_exames = lista_exames->next;
  int num, i;

  printf("Selecione o exame em que pretende inscrever o aluno:\n");
  imprime_exames(lista_exames);
  printf("Opcao: ");
  scanf("%d", &num);
  for (i=1; i<num; i++) {
    l_exames = l_exames->next;
  }

  while(l_inscricoes->next != NULL) {
    l_inscricoes = l_inscricoes->next;
  }

  new_node = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
  l_inscricoes->next = new_node;
  new_node->exame = l_exames;
  new_node->next = NULL;
  return;
}
