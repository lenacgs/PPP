//funçao para testar func1_alterar_dados_aluno, a funcionar

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

    typedef struct {
      int dia;
      int mes;
      int ano;
    } Data;

    typedef struct {
      int horas;
      int mins;
    } Hora;


    typedef struct node_exame *Ptr_exame;
    typedef struct ptrs_exame *Next_ptrs_exame;
    typedef struct ptrs_exame {
      Ptr_exame exame;
      Next_ptrs_exame next;
    } Ptrs_exame;

    typedef struct node_aluno *Ptr_aluno;
    typedef struct ptrs_aluno *Next_ptrs_aluno;
    typedef struct ptrs_aluno {
      Ptr_aluno aluno;
      Next_ptrs_aluno next;
    }Ptrs_aluno;

    typedef struct node_disciplina *Next_disciplina;
    typedef struct node_disciplina{
      char *nome;
      char *docente;
      Next_disciplina next;
    } Node_disciplina;

    typedef struct node_aluno *Next_aluno;
    typedef struct node_aluno {
      int num_aluno;
      char *curso;
      int ano_mat;
      char *regime;
      Next_ptrs_exame *inscricoes;
      Next_aluno next;
    } Node_aluno;

    typedef struct node_exame *Next_exame;
    typedef struct node_exame{
      Node_disciplina *disciplina;
      char *epoca;
      Data data;
      Hora hora;
      int duracao;
      char *sala;
      Next_ptrs_aluno *inscritos;
      Next_exame next;
    } Node_exame;


    void insere_array(char *string, char *p_inicial, int len) {
      char *aux, *end, *i;
      int j=0;
      end = p_inicial + len - 1;
      aux = p_inicial;
      for (i=aux; i<end; i++) {
        *i = *(string+j);
        j++;
      }
    }

    void inserir_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
      Next_aluno aux = lista_alunos;
      while (aux->next != NULL) {
        aux = aux->next;
      }
      aux->next = aluno;
    }

    void criar_aluno(Next_aluno lista_alunos) {
        char *p_curso, *p_regime, string [30];
        int len;
        Next_aluno aluno;
        aluno = (Next_aluno)malloc(sizeof(Node_aluno));

        aluno->num_aluno = (int)malloc(30 * sizeof(int));
        printf("Numero: ");
        scanf("%d", &(aluno->num_aluno)); /*certo*/

        aluno->curso = (char*)malloc(50*sizeof(char));
        p_curso = aluno->curso;
        printf("Curso: ");
        scanf("%s", string);
        len = strlen(string);
        insere_array(string, p_curso, len);

        printf("Ano de matricula: ");
        scanf("%d", &(aluno->ano_mat));

        printf("Regime: ");
        aluno->regime = (char*)malloc(50*sizeof(int));
        p_regime = aluno->regime;
        scanf("%s", string);
        len = strlen(string);
        insere_array(string, p_regime, len);

        inserir_aluno(lista_alunos, aluno);
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


    void imprime_num_aluno(Next_aluno lista) {
        Next_aluno aux;
        int i;
        aux = lista->next; /*para saltar o no cabecalho*/
        i = 1;
        while(aux != NULL) {
            printf("%d. %d\n", i, aux->num_aluno);
            i++;
            aux = aux->next;
        }
    }

    void alterar_dados_aluno(Next_aluno lista_alunos) {
      int opcao, num, i;
      char string[50];
      Next_aluno aluno, l, ant, actual;

      l = lista_alunos;
      printf("Escolha o aluno a quem quer alterar dados: \n");
      imprime_num_aluno(lista_alunos);
      scanf("%d", &num);
      for (i=0; i<num; i++) {
        ant = l;
        actual = l->next;
      }

      aluno = actual;
      printf("Escolha o dado que deseja alterar:\n1. Numero\n2. Curso\n3. Ano de matricula\n4. Regime\n");
      scanf("%d", &opcao);
      switch (opcao) {
        case 1: {
          printf("Novo numero: ");
          scanf("%d", &(aluno->num_aluno));
          break;
        }
        case 2: {
          aluno->curso = (char*)malloc(50*sizeof(char));
          printf("Novo curso: ");
          scanf("%s", aluno->curso);
          break;
        }
        case 3: {
          printf("Novo ano: ");
          scanf("%d", &(aluno->ano_mat));
          break;
        }
        case 4: {
          aluno->regime = (char*)malloc(50*sizeof(char));
          printf("Novo regime: ");
          scanf("%s", aluno->regime);
          break;
        }
      }
}



int main() {
    Next_aluno lista_alunos;
    int n, i;

    lista_alunos = cria_lista_alunos();

    printf("Quantos alunos quer criar? ");
    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        printf("Aluno %d:\n", i);
        criar_aluno(lista_alunos);
    }
    printf("Escolha o aluno a quem quer alterar dados: ");
    imprime_num_aluno(lista_alunos);
    c = getchar();
    for (i=0; i<c; i++) {
      ant = l;
      actual = l->next;
    }
    alterar_dados_aluno(lista_alunos, actual);
}
