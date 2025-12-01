#include <stdio.h>
#include <stdlib.h>

int *novo_vetor(int *vet, int cont);

int main(){
    int *vetor, n, aux, cont = 0;

    vetor = (int*) malloc(sizeof(int) * 5);

    while(1){
        n = sizeof(vetor) / sizeof(int);

        if(cont == n){
            vetor = novo_vetor(vetor, cont);
        }

        if(cont == 0){
            printf("\n[-1 to end program]\nEnter the %dst number: ", cont + 1);
        } else if(cont == 1){
             printf("\n[-1 to end program]\nEnter the %dnd number: ", cont + 1);
        } else{
            printf("\n[-1 to end program]\nEnter the %dth number: ", cont + 1);
        }
        scanf("%d", &aux);
        vetor[cont] = aux;

        if(vetor[cont] == -1){
            break;
        }

        cont++;
    }
    printf("\n\n");

    for(int i=0; i<cont; i++){
        printf("%d  ", vetor[i]);
    }
    printf("\n\n");

    free(vetor);

    return 0;
}

int *novo_vetor(int *vet, int cont){
    int *nvet;

    nvet = (int*) malloc(sizeof(int) * cont*2);
    if(nvet == NULL){
        free(vet);
        return NULL;
    }
    for(int i=0; i<cont; i++){
        nvet[i] = vet[i];
    }

    return nvet;
}