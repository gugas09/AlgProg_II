#include <stdio.h>
#include <stdlib.h>

#define N 30


void empilhar(int p[], int &t, int y, int tam);
int desempilhar(int p[], int &t);
int* inverte_vetor(int p[], int tam);

int main(void){
    int p[5] = {1, 2, 3, 4, 5};
    int tam = sizeof(p) / sizeof(int);
    int t = tam;

    for(int i=0; i<5; i++){
        printf("%d  ", p[i]);
    }
    printf("\n\n");

    int *invertido = inverte_vetor(p, tam);

    for(int i=0; i<5; i++){
        printf("%d  ", invertido[i]);
    }

    return 0;
}


void empilhar(int p[], int &t, int y, int tam){
    if(t == tam){
        printf("\n\nOVERFLOW!");
        return;
    }

    p[t] = y;
    t = t + 1;
}

int desempilhar(int p[], int &t){
    if(t == 0){
        printf("\n\nUNDERFLOW!");
        return 0;
    }

    int y = p[t-1];
    p[t-1] = 0;
    t = t -1;
    return y;
}

int* inverte_vetor(int p[], int tam){
    int t1 = 0, t2 = tam;
    int *novo_vetor = (int *) malloc(sizeof(int) * tam);

    for(int i=0; i<tam; i++){
        empilhar(novo_vetor, t1, desempilhar(p, t2), tam);
    }
    return novo_vetor;
}