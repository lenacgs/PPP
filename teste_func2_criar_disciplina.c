//ainda não funciona. pede os dados na primiero disciplina mas depois de introduzir a info do docente crasha. não chega a entrar no segundo for

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

    void imprime_array(char *string) {
        char *ptr, *endptr;
        int size;

        size = strlen(string);
        endptr = string + size - 1;

        for (ptr=string; ptr<=endptr; ptr++) {
            printf("%c", *ptr);
        }
    }

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

    void inserir_disciplina(Next_disciplina lista_disciplinas, Next_disciplina disciplina) {
      Next_disciplina aux = lista_disciplinas;
      while (aux->next != NULL) {
        aux = aux->next;
      }
      aux->nome = disciplina->nome;
      aux->docente = disciplina->docente;
      aux->next = NULL;
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
            aux->next = NULL;
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

int main() {
    Next_disciplina lista_disciplinas;
    int n, i;

    lista_disciplinas = cria_lista_disciplinas();

    printf("Quantas disciplinas quer criar? ");
    scanf("%d", &n);

    for (i=1; i<=n; i++) {
        printf("Disciplina %d:\n", i);
        criar_disciplina(lista_disciplinas);
    }

    imprime_disciplinas(lista_disciplinas);
}
