#include <stdio.h>
#include <stdlib.h>


struct c{
    int conteudo;
    struct c *ant;
    struct c *seg;
};
typedef struct c celula;

void enfileire(celula **lst, celula **t, int x);
int desenfileire(celula **lst, celula **t);


int main(void){
    celula cabeca, *lst, *t;
    cabeca.ant = &cabeca;
    cabeca.seg = &cabeca;
    lst = &cabeca;
    t = lst;

    return 0;
}



void enfileire(celula **lst, celula **t, int x){
    celula *nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = x;
    (*t)->seg = nova;
    (*lst)->ant = nova;
    nova->ant = *t;
    nova->seg = *lst;
    *t = nova;
}


int desenfileire(celula **lst, celula **t){
    if(*t == *lst){
        printf("UNDERFLOW!\n");
        return 0;
    }
    celula *aux1, *aux2;
    aux1 = (*lst)->seg;
    aux2 = aux1->seg;

    int x = aux1->conteudo;
    (*lst)->seg = aux2;
    aux2->ant = *lst;

    if(*t == aux1){
        *t = *lst;
    }

    free(aux1);
    return x;
}