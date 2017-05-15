#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} Node_ptrs_exame;

typedef struct node_disciplina *Next_disciplina;
typedef struct node_disciplina{
    char *nome;
    char *docente;
    Next_disciplina next;
} Node_disciplina;

typedef struct node_aluno *Ptr_aluno;
typedef struct ptrs_aluno *Next_ptrs_aluno;
typedef struct ptrs_aluno {
    Ptr_aluno aluno;
    Next_ptrs_aluno next;
}Node_ptrs_aluno;

typedef struct node_aluno *Next_aluno;
typedef struct node_aluno {
    int num_aluno;
    char *curso;
    int ano_mat;
    char *regime;
    Next_ptrs_exame inscricoes;
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
    Next_ptrs_aluno inscritos;
    Next_exame next;
} Node_exame;


void inserir_aluno(Next_aluno lista_alunos, Next_aluno aluno) {
    Next_aluno aux = lista_alunos;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = aluno;
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

void ficheiro_alunos(Next_aluno *lista_alunos) {
    FILE *file;
    Next_aluno l, node;
    int j;
    char string[50], c, *aux;
    int i=0, len, count;

    file = fopen("ficheiro_alunos.txt", "r");

    /* while(!feof(file)) {
       node = (Next_aluno)malloc(sizeof(Node_aluno));
       fscanf(file, "%d[^,]", &(node->num_aluno));
       printf("numero %d", node->num_aluno);
       fseek(file, 1, SEEK_CUR);
       fscanf(file, "%[^,]*c", node->curso);
       fseek(file, 1, SEEK_CUR);
       fscanf(file, "%d[^,]", &(node->ano_mat));
       fseek(file, 1, SEEK_CUR);
       fscanf(file, "%[^,]*c", node->regime);
       fseek(file, 1, SEEK_CUR);*/
    c = getc(file);
    count = 0;
    while(c != EOF) {
        node = (Next_aluno)malloc(sizeof(Node_aluno));
        if (c != ',' && c != '\n') {
            string[i] = c;
            i++;
            getchar();
            printf("%s", string);
        }
        else if (c == '\n') {
            count = 0;
            string[i] = '\0';
            aux = node->inscricoes->exame->disciplina->nome;
            for(j = 0;j<strlen(string); j++){
                aux[j] = string[j];
            }
            node->inscricoes = node->inscricoes->next;
            if (*lista_alunos == NULL) {
                *lista_alunos = node;
            }
            else {
                l = *lista_alunos;
                while (l->next != NULL) {
                    l = l->next;
                }
                l->next = node;
            }
            i = 0;
        }
        else {
            count ++;
            string[i] = '\0';
            if (count==1) {
                node->num_aluno = atoi(string);
            }
            else if (count == 2) {
                printf("ola eu estou aqui\n");
                for(j = 0;j<strlen(string); j++){
                    printf("cheguei\n");
                    strcpy((node->curso),string);
                }
            }
            else if (count == 3) {
                node->ano_mat = atoi(string);
            }
            else if (count == 4) {
                for(j = 0;j<strlen(string); j++){
                    node->regime[j] = string[j];
                }
            }
            else if (count > 4) {
                aux = node->inscricoes->exame->disciplina->nome;
                for(j = 0;j<strlen(string); j++){
                    aux[j] = string[j];
                }
                node->inscricoes = node->inscricoes->next;
            }
            i = 0;
        }

        c = getc(file);
    }

    if (*lista_alunos == NULL) {
        *lista_alunos = node;
    }
    else {
        l = *lista_alunos;
        while (l->next != NULL) {
            l = l->next;
        }
        l->next = node;
    }
    fclose(file);
}



void imprime_num_aluno(Next_aluno lista) {
    Next_aluno aux;
    int i=1;
    aux = lista;
    while(aux != NULL) {
        printf("%d. %d\n", i, aux->num_aluno);
        i++;
        aux = aux->next;
    }
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

int main() {
    Next_aluno lista_alunos = cria_lista_alunos();

    ficheiro_alunos(&lista_alunos);
    imprime_num_aluno(lista_alunos);
}\
