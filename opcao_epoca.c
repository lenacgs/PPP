 void opcao_epoca(Next_exame exame) { 
  int x;

  printf("Epocas possiveis:\n1.Epoca normal\n2.Epoca de recurso\n3.Epoca especial\nSeleccione a epoca pretendida: ");
  scanf("%d", &x);

  switch (x) {
    case 1:
      exame->epoca = "Normal";
      break;
    case 2:
      exame->epoca = "Recurso";
      break;
    case 3:
      exame->epoca = "Especial";
      break;
  }
}
