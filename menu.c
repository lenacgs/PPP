void menu() {
    char c;
    printf("MENU\n");
    printf("1.Criar, alterar e apagar dados de alunos\n");
    printf("2.Criar, alterar e apagar dados de disciplinas\n");
    printf("3.Criar exames e configurar salas\n");
    printf("4.Apagar exames já realizados\n");
    printf("5.Listar informações de exames\n");
    printf("6.Inscrições em exames\n");
    printf("7.Listar alunos inscritos num exame\n");
    printf("8.Listar exames em que um aluno está inscrito\n");
    printf("9.Salas reservadas para exames\n");


    do {
        printf("Escolha uma opção: ");
        getchar();
        c = getchar();
        switch (c) {
            case 1: func1();
            case 2: func2();
            case 3: func3();
            case 4: func4();
            case 5: func5();
            case 6: func6();
            case 7: func7();
            case 8: func8();
            case 9: func9();
            default: continue;
        }} while ((c!='1')&&(c!='2')&&(c!='3')&&(c!='4')&&(c!='5')&&(c!='6')&&(c!='7')&&(c!='8')&&(c!='9'));
    }
