//ESTA FUNCAO SO E PUXADA DEPOIS DE SER SABER QUE A EPOCA E ESPECIAL
int verifica_estatuto(Next_exame l_exames, Next_aluno l_alunos) {
  if (strcmp(l_alunos->regime, "Estudante") == 0) {
    if (l_alunos->ano_mat != 3)
      return -1;
    else
      return 1;
  }
  else
    return 1;
}
