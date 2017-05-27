//ja tem prot_num_aluno e opcao_regime

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
void imprime_listas_salas(Next_exame lista_exames) { //imprime todas as salas de todos os exames
  Next_sala lista_salas;
  Next_exame l_exames = lista_exames->next;

  while (l_exames != NULL) {
    printf("O exame com ID %d, da disciplina %s em época %s tem reservadas as seguintes salas:\n", l_exames->id, l_exames->disciplina->nome, l_exames->epoca);
    lista_salas = l_exames->salas->next;
    while (lista_salas != NULL) {
      printf("Sala: %s\n", lista_salas->sala);
      lista_salas = lista_salas->next;
    }
    l_exames = l_exames->next;
  }
}
void imprime_exames(Next_exame lista_exames) {
  Next_exame l_exames;

  l_exames = lista_exames->next;
  while(l_exames != NULL) {
    printf("Id: %d, %s, %s\n", l_exames->id, l_exames->disciplina->nome, l_exames->epoca);
    l_exames = l_exames->next;
  }
}
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

void insere_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
  Next_aluno aux = lista_alunos;
  while (aux->next != NULL) {
    aux = aux->next;
  }

  aux->next = aluno;
  aluno->next = NULL;
}
void imprime_disciplinas(Next_disciplina lista) {
  Next_disciplina l = lista->next;
  int i=1;

  while (l != NULL) {
    printf("%d. %s\n", i, l->nome);
    i++;
    l = l->next;
  }
}
void update_ficheiro_alunos(Next_aluno lista_alunos) {
  Next_aluno l_alunos = lista_alunos->next;
  Next_ptrs_exame l_inscricoes;
  FILE *fp = fopen("ficheiro_alunos.txt", "w");
  while (l_alunos != NULL) {
    fprintf(fp, "%d,%s,%d,%s", l_alunos->num_aluno, l_alunos->curso, l_alunos->ano_mat, l_alunos->regime);

    l_inscricoes = l_alunos->inscricoes->next;
    while (l_inscricoes != NULL) {
      fprintf(fp, ",%d", l_inscricoes->exame->id);
      l_inscricoes = l_inscricoes->next;
    }
    fprintf(fp, "\n");
    l_alunos = l_alunos->next;
  }

  fclose(fp);
}
void update_ficheiro_disciplinas(Next_disciplina lista_disciplinas) {
  Next_disciplina l_disciplinas = lista_disciplinas->next;
  FILE *fp = fopen("ficheiro_disciplinas.txt", "w");
  while (l_disciplinas != NULL) {
    fprintf(fp, "%s,%s\n", l_disciplinas->nome, l_disciplinas->docente);
    l_disciplinas = l_disciplinas->next;
  }
  fclose(fp);
}
void update_ficheiro_exames(Next_exame lista_exames) {
  Next_exame l_exames = lista_exames->next;
  Next_ptrs_aluno l_inscritos;
  FILE *fp = fopen("ficheiro_exames.txt", "w");
  while (l_exames != NULL) {
    printf("Estamos no exame: %d\n", l_exames->id);
    fprintf(fp, "%d,%s,%s,%d,%d,%d,%d,%d,%d", l_exames->id, l_exames->disciplina->nome,  l_exames->epoca,  l_exames->data.dia, l_exames->data.mes, l_exames->data.ano, l_exames->hora.horas, l_exames->hora.mins, l_exames->duracao);

    l_inscritos = l_exames->inscritos->next;
    while (l_inscritos != NULL) {
      printf("Aluno: %d\n", l_inscritos->aluno->num_aluno);
      fprintf(fp, ",%d", l_inscritos->aluno->num_aluno);
      l_inscritos = l_inscritos->next;
    }
    fprintf(fp, "\n");
    l_exames = l_exames->next;
  }
}
Next_ptrs_exame cria_lista_inscricoes() {
  Next_ptrs_exame aux = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
  if (aux != NULL) {
    aux->exame = NULL;
    aux->next = NULL;
  }
  return aux;
}
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
Next_aluno cria_lista_alunos() {
    Next_aluno aux;
    aux = (Next_aluno)malloc(sizeof(Node_aluno));
    if (aux != NULL) {
        aux->num_aluno = 0;
        aux->curso = NULL;
        aux->ano_mat = 0;
        aux->regime = NULL;
        aux->inscricoes = NULL;
        aux->next = NULL;
    }
    return aux;
}
Next_exame cria_lista_exames() {
    Next_exame aux;
    aux = (Next_exame)malloc(sizeof(Node_exame));
    if (aux != NULL) {
      aux->disciplina = NULL;
      aux->epoca = NULL;
      aux->data.dia = 0;
      aux->data.mes = 0;
      aux->data.ano = 0;
      aux->hora.horas = 0;
      aux->hora.mins = 0;
      aux->duracao = 0;
      aux->salas = NULL;
      aux->inscritos = NULL;
      aux->next = NULL;
    }
    return aux;
}
Next_ptrs_aluno cria_lista_inscritos() {
  Next_ptrs_aluno aux;
  aux = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
  if (aux != NULL) {
    aux->aluno = NULL;
    aux->next = NULL;
  }
  return aux;
}
Next_sala cria_lista_salas() {
  Next_sala aux = (Next_sala)malloc(sizeof(Node_sala));
  if (aux != NULL) {
    aux->sala = NULL;
    aux->next = NULL;
  }
  return aux;
}
void insere_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
  Next_disciplina aux = lista_disciplinas;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = disciplina;
  disciplina->next = NULL;
}
void insere_exame(Next_exame lista_exames, Next_exame exame) {
  Next_exame aux = lista_exames;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = exame;
  exame->next = NULL;
}
void insere_sala(char *sala, Next_exame lista_exames, Next_exame exame) {
  printf("Entrou na funcao insere_sala.\nVai inserir a sala %s no exame %d.\n", sala, exame->id);
  Next_sala l_salas = exame->salas;
  printf("ola\n");
  while (l_salas->next != NULL) {
    l_salas = l_salas->next;
  }
  printf("Ola2\n");
  //l_salas->next = NULL
  l_salas->next = (Next_sala)malloc(sizeof(Node_sala));
  printf("ola3\n");
  l_salas->next->sala = sala;
  printf("sala: %s\n", l_salas->next->sala);
  l_salas->next->next = NULL;

  update_ficheiro_salas(lista_exames);
}
void le_ficheiro_disciplinas (Next_disciplina lista_disciplinas) {
  FILE *fp;
  Next_disciplina novaDisciplina;
  fp = fopen("ficheiro_disciplinas.txt", "r");
  char nome[100];
  printf("LEITURA DA LISTA DE DISCIPLINAS:\n");
  while(fscanf(fp, " %[^,\n]", nome) != EOF) {
    fseek(fp, 1, SEEK_CUR);
    novaDisciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));

    novaDisciplina->nome = (char*)malloc(50*sizeof(char));
    strcpy(novaDisciplina->nome, nome);
    printf("NOME DA DISCIPLINA: %s\n", novaDisciplina->nome);

    novaDisciplina->docente = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novaDisciplina->docente);
    printf("DOCENTE DA DISCIPLINA: %s\n", novaDisciplina->docente);
    fseek(fp, 1, SEEK_CUR);

    insere_disciplina(lista_disciplinas, novaDisciplina);
  }
  fclose(fp);
}

void le_ficheiro_alunos(Next_aluno lista_alunos) {
  FILE * fp;
  Next_aluno novoAluno;
  int i, id, num_exame;
  Next_ptrs_exame lista_inscricoes, l_inscricoes;
  fp = fopen("ficheiro_alunos.txt", "r");
  char num[100], c, string[200], s[2] = ",", *exame;

  printf("LEITURA DA LISTA DE ALUNOS:\n");
  while (fscanf(fp, " %[^,]", num) != EOF) {
    fseek(fp, 1, SEEK_CUR);
    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    novoAluno->num_aluno = atoi(num);
    printf("NUMERO DE ALUNO: %d\n", novoAluno->num_aluno);

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->curso);
    printf("CURSO: %s\n", novoAluno->curso);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,]", &(novoAluno->ano_mat));
    printf("ANO DE MATRICULA: %d\n", novoAluno->ano_mat);
    fseek(fp, 1, SEEK_CUR);

    novoAluno->regime = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoAluno->regime);
    printf("REGIME: %s\n", novoAluno->regime);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%[^\n]", string);

   insere_aluno(lista_alunos, novoAluno);
  }
  fclose(fp);
}

void le_ficheiro_exames(Next_exame lista_exames, Next_disciplina lista_disciplinas, Next_aluno lista_alunos) {
  FILE *fp;
  Next_exame novoExame;
  Next_disciplina l_disciplinas = lista_disciplinas->next;
  Next_aluno l_alunos = lista_alunos;
  Next_ptrs_aluno lista_inscritos, l_inscritos;
  fp = fopen("ficheiro_exames.txt", "r");
  char disciplina[100], c, string[100], id[100], s[2]= ",", *numero;
  int i, num, num_aluno;


  if (fp == NULL) {
    printf("Nao conseguiu abrir o ficheiro ->\"ficheiro_exames.txt\"<- \\\n");
    return;
  }

  printf("LEITURA DA LISTA DE EXAMES: \n");

  while(fscanf(fp, " %[^,]", id) != EOF) {
    l_disciplinas = lista_disciplinas->next;

    novoExame = (Next_exame)malloc(sizeof(Node_exame));
    fseek (fp, 1, SEEK_CUR);
    novoExame->id = atoi(id);
    printf("ID: %d\n", novoExame->id);

    novoExame->disciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));
    fscanf(fp, "%[^,]", disciplina);

    while (l_disciplinas != NULL) {

      if (strcmp(l_disciplinas->nome, disciplina) == 0) {
        novoExame->disciplina = l_disciplinas;
      }
      l_disciplinas = l_disciplinas->next;
    }
    printf("DISCIPLINA: %s\n", novoExame->disciplina->nome);
    fseek(fp, 1, SEEK_CUR);

    novoExame->epoca = (char*)malloc(50*sizeof(char));
    fscanf(fp, "%[^,\n]", novoExame->epoca);
    printf("EPOCA: %s\n", novoExame->epoca);
    fseek(fp, 1, SEEK_CUR);

    fscanf(fp, "%d[^,\n]", &(novoExame->data.dia));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->data.mes));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->data.ano));
    fseek(fp, 1, SEEK_CUR);
    printf("DATA: %d.%d.%d\n", novoExame->data.dia, novoExame->data.mes, novoExame->data.ano);

    fscanf(fp, "%d[^,\n]", &(novoExame->hora.horas));
    fseek(fp, 1, SEEK_CUR);
    fscanf(fp, "%d[^,\n]", &(novoExame->hora.mins));
    fseek(fp, 1, SEEK_CUR);
    printf("HORAS: %dh %dmin\n", novoExame->hora.horas, novoExame->hora.mins);

    fscanf(fp, "%d[^,\n]", &(novoExame->duracao));
    fseek(fp, 1, SEEK_CUR);
    printf("DURACAO: %d\n", novoExame->duracao);

    novoExame->inscritos = cria_lista_inscritos();
    l_inscritos = novoExame->inscritos;

    fscanf(fp, "%[^\n]", string);
    numero = strtok(string, s);
    num = atoi(numero);
    while(numero != NULL ) {
      num = atoi(numero);
      printf("aluno inscrito: %d\n", num);
      l_alunos = lista_alunos->next;
      while (l_alunos != NULL) {
        if  (l_alunos->num_aluno == num) {
          while (l_inscritos->next != NULL) {
            l_inscritos = l_inscritos->next;
          }
          l_inscritos->next = (Next_ptrs_aluno)malloc(sizeof(Node_ptrs_aluno));
          l_inscritos->next->aluno = l_alunos;
          l_inscritos->next->next = NULL;
        }
        l_alunos = l_alunos->next;
      }
      numero = strtok(NULL, s);
    }
    insere_exame(lista_exames, novoExame);
  }
  fclose(fp);
}

void le_ficheiro_inscricoes(Next_aluno lista_alunos, Next_exame lista_exames) {
  FILE *fp;
  fp = fopen("ficheiro_alunos.txt", "r");
  char lixo[100], *exame, string[100], s[2]= ",";
  int num_exame, i;
  Next_exame l_exames = lista_exames->next;
  Next_aluno l_alunos = lista_alunos->next;
  Next_ptrs_exame l_inscricoes;


  while (fscanf(fp, " %[^,]", lixo) != EOF) {
    //ciclo para ler os 4 primeiros parâmetros de uma linha (não interessam para as inscrições)
    for (i=0; i<4; i++) {
      fscanf(fp, "%[^,]", lixo);
      fseek(fp, 1, SEEK_CUR);
    }

    l_alunos->inscricoes = cria_lista_inscricoes();
    l_inscricoes = l_alunos->inscricoes;
    fscanf(fp, "%[^\n]", string); //le o que sobra da linha no ficheiro, passando-a para dentro de string

    exame = strtok(string, s); //separa o primeiro id de exame para dentro de exame
    num_exame = atoi(exame); //converte char para int
    while (exame != NULL) {
      num_exame = atoi(exame);
      l_exames = lista_exames->next;

      while (l_exames != NULL) {
        if  (l_exames->id == num_exame) {
          while (l_inscricoes->next != NULL) {
            l_inscricoes = l_inscricoes->next;
          }
          l_inscricoes->next = (Next_ptrs_exame)malloc(sizeof(Node_ptrs_exame));
          l_inscricoes->next->exame = l_exames;
          l_inscricoes->next->next = NULL;
        }
        l_exames = l_exames->next;
      }
      exame = strtok(NULL, s);
   }
   l_inscricoes = l_alunos->inscricoes->next;
   printf("LISTA DE EXAMES EM QUE O ALUNO %d ESTA INSCRITO:\n", l_alunos->num_aluno);
   while (l_inscricoes != NULL) {
     printf("EXAME: %d\n", l_inscricoes->exame->id);
     l_inscricoes = l_inscricoes->next;
   }
   l_alunos = l_alunos->next;
  }
  fclose(fp);
}

void le_ficheiro_salas(Next_exame lista_exames) {
  FILE *fp = fopen("ficheiro_salas.txt", "r");
  char id[100], *sala, string[100], s[2] = ",";
  int id_exame;
  Next_exame l_exames = lista_exames->next;
  Next_sala novaSala, l_salas;

  printf("LEITURA DA LISTA DE SALAS:\n");
  while (fscanf(fp, " %[^,]", id) != EOF) { //enquanto existirem linhas no ficheiro_salas, guarda o id de 1 linha para a variavel "id"
    id_exame = atoi(id);
    fseek(fp, 1, SEEK_CUR); //sala uma virgula
    while (l_exames->id != id_exame) {
      l_exames = l_exames->next;
    }
    //l_exames é um ponteiro para o node_exame que tem o id que procuramos

    l_exames->salas = cria_lista_salas();
    l_salas = l_exames->salas;
    fscanf(fp, " %[^\n]", string);

    sala = (char*)malloc(100*sizeof(char));

    sala = strtok(string, s); //retorna NULL quando já não é possivel tokenizar mais string
    while (sala != NULL) {
      while(l_salas->next != NULL) {
        l_salas = l_salas->next;
      }
      l_salas->next = (Next_sala)malloc(sizeof(Node_sala));
      l_salas->next->sala = (char*)malloc(100*sizeof(char));
      strcpy(l_salas->next->sala, sala);
      l_salas->next->next = NULL;
      sala = strtok(NULL, s);
    }
  }
  fclose(fp);
  printf("Leitura da lista de salas concluída.\n");
}



Next_disciplina cria_lista_disciplinas() {
    Next_disciplina aux;
    aux = (Next_disciplina)malloc(sizeof(Node_disciplina));
    if (aux != NULL) {
        aux->docente = NULL;
        aux->nome = NULL;
        aux->next = NULL;
    }
    return aux;
}
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
void escreve_ficheiro_alunos(Next_aluno lista_alunos, Next_aluno novoAluno) {
  Next_ptrs_exame l_inscricoes;
  Next_aluno l_alunos = lista_alunos;
  FILE *fp = fopen("ficheiro_alunos.txt", "a");
  char *string;

  fprintf(fp, "%d,%s,%d,%s", novoAluno->num_aluno, novoAluno->curso, novoAluno->ano_mat, novoAluno->regime);

  l_inscricoes = novoAluno->inscricoes;
  while(l_inscricoes->next != NULL) {
    printf("Exame em q esta inscrito: %d\n", l_inscricoes->next->exame->id);
    fprintf(fp, ",%d", l_inscricoes->next->exame->id);
    l_inscricoes = l_inscricoes->next;
  }
  fprintf(fp, "\n");
  fclose(fp);
}
int prot_num_aluno(int num, Next_aluno lista_alunos) {
  int res;
  Next_aluno l_alunos = lista_alunos->next;

  while (l_alunos != NULL) {
    if (l_alunos->num_aluno == num) {
      return -1;
    }
    l_alunos = l_alunos->next;
  }
  return 0;
}
void cria_aluno(Next_aluno lista_alunos, Next_exame lista_exames) {
    char *p_curso, *p_regime, string [30];
    int len, i, opcao, num_aluno, res;
    Next_aluno novoAluno, l_alunos = lista_alunos->next;
    Next_ptrs_exame l_inscricoes;

    novoAluno = (Next_aluno)malloc(sizeof(Node_aluno));

    novoAluno->num_aluno = (int)malloc(30 * sizeof(int));
    printf("Numero: ");
    scanf("%d", &num_aluno); /*certo*/

    res = prot_num_aluno(num_aluno, lista_alunos);
    while (res == -1) {
      printf("O numero de aluno que introduziu ja existe. Por favor insira outro numero: ");
      scanf("%d", &num_aluno);
      res = prot_num_aluno(num_aluno, lista_alunos);
    }
    novoAluno->num_aluno = num_aluno;

    novoAluno->curso = (char*)malloc(50*sizeof(char));
    printf("Curso: ");
    scanf("%s", novoAluno->curso);

    printf("Ano de matricula: ");
    scanf("%d", &(novoAluno->ano_mat));

    novoAluno->regime = (char*)malloc(50*sizeof(int));
    printf("Regime: ");
    opcao_regime(novoAluno);

    novoAluno->inscricoes = cria_lista_inscricoes();
    l_inscricoes = novoAluno->inscricoes;

    printf("Em quantos exames quer inscrever o aluno? ");
    scanf("%d", &opcao);
    for(i=0; i<opcao; i++) {
      associa_exame(l_inscricoes, lista_exames);
    }
    //para ter a certeza que os exames ficaram bem associados
    l_inscricoes = novoAluno->inscricoes->next;
    printf("LISTA DE EXAMES INSCRITOS:\n");
    while (l_inscricoes != NULL) {
      printf("Id: %d\n", l_inscricoes->exame->id);
      l_inscricoes = l_inscricoes->next;
    }
    insere_aluno(lista_alunos, novoAluno);
    escreve_ficheiro_alunos(lista_alunos, novoAluno);
}
void imprime_num_aluno(Next_aluno lista) {
  Next_aluno aux = lista->next;
  int i=1;

  while(aux != NULL) {
    printf("%d. %d\n", i, aux->num_aluno);
    i++;
    aux = aux->next;
  }
}
int main() {
  int i, n;
  Next_aluno lista_alunos = cria_lista_alunos();
  Next_disciplina lista_disciplinas = cria_lista_disciplinas();
  Next_exame lista_exames = cria_lista_exames();

  /*criar lista de disciplinas*/
  lista_disciplinas = cria_lista_disciplinas();
  le_ficheiro_disciplinas(lista_disciplinas);
  printf("LEITURA DA LISTA DE DISCIPLINAS:\n");
  imprime_disciplinas(lista_disciplinas);

  /*criar lista de alunos*/
  lista_alunos = cria_lista_alunos();
  le_ficheiro_alunos(lista_alunos);
  printf("LEITURA DA LISTA DE ALUNOS:\n");
  imprime_num_aluno(lista_alunos);

  lista_exames = cria_lista_exames();
  le_ficheiro_exames(lista_exames, lista_disciplinas, lista_alunos);

  le_ficheiro_inscricoes(lista_alunos, lista_exames);
  le_ficheiro_salas(lista_exames);
  imprime_listas_salas(lista_exames);

  printf("Quantos alunos quer criar?: ");
  scanf("%d", &n);

  for (i=1; i<=n; i++) {
    printf("Aluno %d\n", i);
    cria_aluno(lista_alunos, lista_exames);
  }
  imprime_num_aluno(lista_alunos);
  return 0;
}
