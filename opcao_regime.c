void opcao_regime(Next_aluno aluno) {
  int x;

  printf("Regimes possíveis:\n1. Normal\n2.Trabalhador-estudante\n3.Atleta\n4.Dirigente associativo\n5.Aluno de Erasmus\n");
  printf("Seleccione o regime pretendido: ");
  scanf("%d", &x);

  switch (x) {
    case 1:
      aluno->regime = "Normal";
      break;
    case 2:
      aluno->regime = "Trabalhador-estudante";
      break;
    case 3:
      aluno->regime = "Atleta";
      break;
    case 4:
      aluno->regime = "Dirigente-associativo";
      break;
    case 5:
      aluno->regime = "Aluno-de-Erasmus";
      break;
  }
  return;
}
