#include<stdio.h>
#include<stdlib.h>

typedef struct node *List;
typedef struct node {
  int info;
  List next;
} List_node;

List cria_lista() {
  List node;
  node = (List)malloc(sizeof(List_node));

  if (node != NULL) {
    node->info = 0;
    node->next = NULL;
  }
  return node;
}

void insere_lista(int elem, List lista) {
  List node, ant;
  node = (List)malloc(sizeof(List_node));
  if (node != NULL) {
    node->info = elem;

    node->next = ant->next;
  }
}

int main () {
  List lista;
  int n, i, elem;

  printf("Quantos elementos tem a lista?: ");
  scanf("%d", &n);

  lista = cria_lista();

  for (i=1; i<=n; i++) {
    printf("Elemento %d: ", i);
    scanf("%d", &elem);
    insere_lista(elem, lista);
  }
}
