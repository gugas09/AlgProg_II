#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA 5


void enfileire(int f[], int s, int *t, int x);
int desenfileire(int f[], int *s, int t);


int main(void){
    int *fila = (int *) malloc(sizeof(int) * TAMANHO_FILA);
    int s = 2, t = s;

    return 0;
}



void enfileire(int f[], int s, int *t, int x){
    if(*t + 1 == s){
        printf("OVERFLOW!");
        return;
    }else if(*t == TAMANHO_FILA-1 && s == 0){
        printf("OVERFLOW!");
        return;        
    }
    
    f[*t] = x;

    if(*t == TAMANHO_FILA-1){
        *t = 0;
    }else{
        *t = *t + 1;
    }
}


int desenfileire(int f[], int *s, int t){
    if(*s == t){
        printf("UNDERFLOW!");
        return 0;
    }

    int x = f[*s];
    if(*s == TAMANHO_FILA-1){
        *s = 0;
    }else{
        *s = *s + 1;
    }
    return x;
}