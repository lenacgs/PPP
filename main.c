#include<stdio.h>
#include<stdlib.h>

int main() {
    char c;
    printf("Clique M para aceder ao menu\n");
    printf("Clique T para terminar o programa\n");
    if ((c=getchar()) == 'M')
        menu();
    if ((c=getchar()) == 'T')
        return 0;
}
