#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_FILA 30


void enfileire(int f[], int s, int *t, int x);
int desenfileire(int f[], int *s, int t);


int main(void){
    int *fila = (int *) malloc(sizeof(int) * TAMANHO_FILA);
    int s = 0, t = s;

    return 0;
}



void enfileire(int f[], int s, int *t, int x){
    if(*t == 30){
        printf("\n\nOVERFLOW!");
        return;
    }
    
    f[*t] = x;
    *t = *t + 1;
}


int desenfileire(int f[], int *s, int t){
    if(*s == t){
        printf("\n\nUNDERFLOW!");
        return;
    }

    int x = f[*s];
    *s = *s + 1;

    return x;
}