// ainda nao foi testada. por primeiro a func2_criar_disciplina a funiconar

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

    void inserir_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
      Next_disciplina aux = lista_disciplinas;
      while (aux->next != NULL) {
        aux = aux->next;
      }
      aux->next = disciplina;
    }

    void criar_disciplina(Next_disciplina lista_disciplinas) {
        Next_disciplina novaDisciplina;
        int n, i;

        printf("Quantas disciplinas e que quer criar? ");
        scanf("%d", &n);
        for(i=1; i<=n;i++) {
          printf("Disciplina %d:\n", i);
          novaDisciplina = (Next_disciplina)malloc(sizeof(Node_disciplina));

          novaDisciplina->nome = (char*)malloc(50*sizeof(char));
          printf("Nome da disciplina: ");
          scanf("%s", novaDisciplina->nome);

          novaDisciplina->docente = (char*)malloc(50*sizeof(int));
          printf("Nome do docente: ");
          scanf("%s", novaDisciplina->docente);

          insere_disciplina(lista_disciplinas, novaDisciplina);
          escreve_ficheiro_disciplinas(lista_disciplinas, novaDisciplina);
        }
    }

    Next_disciplina cria_lista_disciplinas() {
        Next_disciplina aux;
        aux = (Next_disciplina)malloc(sizeof(Node_disciplina));
        if (aux != NULL) {
            aux->docente = NULL;
            aux->nome = NULL;
        }
        return aux;
    }

    void imprime_disciplinas(Next_disciplina lista) {
      Next_disciplina l = lista->next;
      int i=1;
      while (l != NULL) {
        printf("%d.", i);
        imprime_array(l->nome);
        i++;
        l = l->next;
      }
    }

    void alterar_dados_disciplina(Next_disciplina lista_disciplinas) {
      int opcao;
      char string[50];
      Next_disciplina l, novaDisciplina, ant, actual;

      l_disciplinas = lista_disciplinas;
      printf("Escolha a disciplina a qual quer alterar dados: \n");
      imprime_disciplinas(lista_disciplinas);
      scanf("%d", &num);
      for (i=0; i<num; i++) {
        ant = l_disciplinas;
        actual = l_disciplinas->next;
      }

      novaDisciplina = actual;
      printf("Escolha o dado que deseja alterar:\n1. Nome da disciplina\n2. Nome do docente");
      scanf("%d", &opcao);
      switch (opcao) {
        case 1:
          novaDisciplina->nome = (*char)malloc(50*sizeof(char));
          printf("Nova disciplina: ");
          scanf("%s", novaDisciplina->nome);
          break;

        case 2:
          disciplina->docente = (*char)malloc(50*sizeof(char));
          printf("Novo docente: ");
          scanf("%s", novaDisciplina->docente);
          break;
      }
    }


int main() {
    Next_disciplina lista_disciplinas;
    int n, i;

    lista_disciplinas = cria_lista_disciplinas();

    printf("Quantas disciplinas quer criar? ");
    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        printf("Disciplina %d:\n", i);
        criar_aluno(lista_disciplinas);
    }
    printf("Escolha a disciplina á qual quer alterar dados: ");
    imprime_disciplina(lista_disciplinas);
    c = getchar();
    for (i=0; i<c; i++) {
      ant = l;
      actual = l->next;
    }
    alterar_dados_disciplina(lista_disciplinas, actual);
}
