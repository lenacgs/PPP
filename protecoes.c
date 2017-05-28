//PROTECOES
#define TAM 200

int prot_ano() {
    int ano_certo;
    char ano[TAM];
    while (scanf(" %[^\n]", ano) ) {
        int i = 0;
        int len = strlen(ano);
        while (i < len) {
            if (ano[i] < '0' || ano[i] > '9') {
                printf("Não pode introduzir letras ou símbolos.\nInsira outro ano:\n");
                return prot_ano();
            }
            i++;
        }
        if (i == len) {
            if (atoi(ano) <= 0) {
                printf("Ano inválido.\n");
                i = 0;
            }
            else {
                ano_certo = atoi(ano);
                return ano_certo;
            }
        }
     }
    return 0;
}

int prot_mes() {
    int mes_certo;
    char mes[TAM];
    while (scanf(" %[^\n]", mes) ) {
        int i = 0;
        int len = strlen(mes);
        while (i < len) {
            if (mes[i] < '0' || mes[i] > '9') {
                printf("Não pode introduzir letras ou simbolos\nInsira outro mes:");
                return prot_mes();
            }
            i++;
        }
        if (i == len) {
            if (atoi(mes) < 1 || atoi(mes) > 12) {
                printf("Mês inválido \n");
                i = 0;
            }
            else {
                mes_certo = atoi(mes);
                return mes_certo;
            }
        }
     }
    return 0;
}

int prot_dia(int ano, int mes) {
    int dia_certo;
    char dia[TAM];
    while (scanf(" %[^\n]", dia) ) {
        int i = 0;
        int len = strlen(dia);
        while (i < len) {
            if (dia[i] < '0' || dia[i] > '9') {
                printf("Não pode introduzir letras ou simbolos.\nInsira outro dia:");
                return prot_dia();
            }
            i++;
        }
        if (dia <= 0 || dia > 31 || (dia == 31 && mes == 2) || (dia == 31 && mes == 4) || (dia == 31 && mes == 6)||(dia == 31 && mes == 9)||(dia == 31 && mes == 11)||(dia == 30 && mes == 2)) {
            printf("Dia invalido.\nInsira outra dia:");
            return prot_dia();
        }
        if (i == len) {
          dia_certo = atoi(dia);
          return dia_certo;
        }
     }
    return 0;
}

int prot_hora() {
    int hora_certa;
    char hora[TAM];
    while (scanf(" %[^\n]", hora) ) {
        int i = 0;
        int len = strlen(hora);
        while (i < len) {
            if (hora[i] < '0' || hora[i] > '9') {
                printf("Não pode introduzir letras ou simbolos.\nInsira outra hora:");
                return prot_hora();
            }
            i++;
        }
        if (i == len) {
            if (atoi(hora) < 0 || atoi(hora) > 23) {
                printf("Hora inválida.\nInsira outra hora:");
            }
            else {
                hora_certa = atoi(hora);
                return hora_certa;
            }
        }
     }
    return 0;
}

int prot_mins() {
    int mins_certos;
    char mins[TAM];
    while (scanf(" %[^\n]", mins) ) {
        int i = 0;
        int len = strlen(mins);
        while (i < len) {
            if (mins[i] < '0' || mins[i] > '9') {
                printf("Não pode introduzir letras ou simbolos.\nInsira outros minutos:");
                return prot_mins();
            }
            i++;
        }
        if (i == len) {
            if (atoi(mins) < 0 || atoi(mins) > 59) {
                printf("Minutos inválidos.\nInsira outros minutos:");
                return prot_mins();
            }
            else {
                mins_certos = atoi(mins);
                return mins_certos;
            }
        }
     }
    return 0;
}

int prot_int() {
  int inteiro_certo;
  char inteiro[TAM];
  while (scanf(" %[^\n]", inteiro) ) {
    int i = 0;
    int len = strlen(inteiro);
    while (i < len) {
      if (inteiro[i] < '0' || inteiro[i] > '9') {
        printf("Nao pode introduzir letras ou simbolos.\nInsira novamente:");
        return prot_int();
      }
      i++;
    }
    if (i == len) {
      inteiro_certo = atoi(inteiro);
      return inteiro_certo;
    }
  }
  return 0;
}

int prot_menu() {
  int opcao_certa;
  char opcao[MAX];
  while (scanf(" %[^\n]", opcao) ) {
    int i = 0;
    int len = strlen(opcao);
    while (i < len) {
      if (opcao[i] < '0' || opcao[i] > '9' || i > 0) {
        printf("Tem que escolher um numero de 1 a 9.\nOpcao:");
        return prot_menu();
      }
      i++;
    }
    if (i == len) {
      opcao_certa = atoi(opcao);
      return opcao_certa;
    }
  }
  return atoi(str);
}

char *prot_string() {
  char str[TAM];
  while (scanf(" %[^\n]", str) ) {
    int i = 0;
    int len = strlen(str);
    while (i < len) {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != 32) {
        printf("Nao pode introduzir numeros ou simbolos.\nInsira novamente:");
        return prot_string();
      }
      i++;
    }
    if (i == len) {
      return string;
    }
  }
  return 0;
}
