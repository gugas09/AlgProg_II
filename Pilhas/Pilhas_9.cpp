#include <stdio.h>
#include <stdlib.h>


struct c{
    int conteudo;
    struct c *seg;
};
typedef struct c celula;

void empilhar(celula **t, int x);
int desempilhar(celula **t);


int main(void){
    celula *t = NULL;

    return 0;
}



void empilhar(celula **t, int x){
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->conteudo = x;

    if(*t == NULL){
        nova->seg = NULL;
        *t = nova;
        return;
    }

    nova->seg = *t;
    *t = nova;
}


int desempilhar(celula **t){
    if(*t == NULL){
        printf("UNDERFLOW!\n");
        return 0;
    }else if((*t)->seg == NULL){
        int x = (*t)->conteudo;
        free(*t);
        *t = NULL;
        return x;
    }

    celula *aux = *t;
    *t = aux->seg;
    int x = aux->conteudo;
    free(aux);
    return x;
}