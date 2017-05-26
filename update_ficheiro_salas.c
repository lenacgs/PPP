//sempre que uma nova sala é adicionada esta fucnao é puxada.
//volta a escrever o ficheiro toda de novo, mas desta vez com a info atualizada

void update_ficheiro_salas(Next_exame lista_exames) {
  Next_exame l_exames = lista_exames->next;
  Next_sala l_salas;
  FILE *fp = fopen("ficheiro_salas.txt", "w");
  //sempre que uma nova sala é adicionada a uma exame o ficcheiro das salas é todo re-escrito
  while(l_exames != NULL) {
    fprintf(fp, "%d", l_exames->id);
    l_salas = l_exames->salas->next;
    while (l_salas != NULL) {
      fprintf(fp, ",%s", l_salas->sala);
      l_salas = l_salas->next;
    }
    fprintf(fp, "\n");
    l_exames = l_exames->next;
  }
  fclose(fp);
}
