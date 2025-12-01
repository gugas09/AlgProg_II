#include <stdio.h>
#include <stdlib.h>

#define N 30


void empilhar(int p[], int &t, int y);
int desempilhar(int p[], int &t);


int main(void){
    int *p = (int *) malloc(sizeof(int) * N);
    int t = 0;

    empilhar(p, t, 3);

    return 0;
}


void empilhar(int p[], int &t, int y){
    if(t - 1 == N){
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
