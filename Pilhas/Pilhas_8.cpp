#include <stdio.h>
#include <stdlib.h>


struct c{
    int conteudo;
    struct c *seg;
};
typedef struct c celula;

void empilhar(celula **lst, celula **t, int x);
int desempilhar(celula **lst, celula **t);


int main(void){
    celula cabeca, *lst, *t;

    cabeca.seg = NULL;
    lst = &cabeca;
    t = lst;

    return 0;
}



void empilhar(celula **lst, celula **t, int x){
    celula *nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = x;
    nova->seg = NULL;
    (*t)->seg = nova;
    *t = nova; 
}


int desempilhar(celula **lst, celula **t){
    if(*t == *lst){
        printf("UNDERFLOW!\n");
        return 0;
    }
    
    celula *aux;
    aux = *lst;
    while(aux->seg->seg != NULL){
        aux = aux->seg;
    }
    *t = aux;
    aux = aux->seg;
    (*t)->seg = NULL;
    int x = aux->conteudo;
    free(aux);
    return x;
}