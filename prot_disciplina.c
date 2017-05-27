//verifica se a disciplina que se quer colocar no novo exame existe, ou se precisa de ser criada.

void prot_disciplina(char *string, Next_disciplina lista_disciplinas) {
  Next_disciplina l_disciplinas = lista_disciplinas->next;
  int x, res=0;

  printf("%s, %s\n", l_disciplinas->next->next->next->nome, l_disciplinas->next->next->next->docente);

  while (l_disciplinas != NULL) {
    if (strcmp(l_disciplinas->nome, string) == 0) {
      res = 0;
      break;
    }
    else {
      res = -1;
      l_disciplinas = l_disciplinas->next;
    }
  }

  while (res == -1) {
    printf("A disciplina que introduziu ainda nao existe na lista de disciplinas.\nQuer:\n1.Criar disciplina com o nome inserido\n2.Escolher outra disciplina\n");
    scanf("%d", &x);

    switch(x) {
      case 1:
        cria_disciplina(lista_disciplinas);
        res = 0;
        break;
      case 2:
        printf("Disciplina: ");
        scanf("%s", string);
        return prot_disciplina(string, lista_disciplinas);
        break;
    }
  }
}
