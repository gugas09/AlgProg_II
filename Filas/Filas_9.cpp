#include <stdio.h>
#include <stdlib.h>


struct c{
    int conteudo;
    struct c *seg;
};
typedef struct c celula;

void enfileire(celula **lst, celula **t, int x);
int desenfileire(celula **lst, celula **t);


int main(void){
    celula cabeca, *lst, *t;

    cabeca.seg = NULL;
    lst = &cabeca;
    t = lst;

    return 0;
}



void enfileire(celula **lst, celula **t, int x){
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = x;
    nova->seg = NULL;
    (*t)->seg = nova;
    *t = nova;
}


int desenfileire(celula **lst, celula **t){
    if(*lst == *t){
        printf("UNDERFLOW!\n");
        return 0;
    }

    celula *aux = (*lst)->seg;
    
    if(*t == aux){
        *t = *lst;
    }

    int x = aux->conteudo;
    (*lst)->seg = aux->seg;
    free(aux);
    return x;
}
