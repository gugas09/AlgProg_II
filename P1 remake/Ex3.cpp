#include <stdio.h>
#include <stdlib.h>

#define TAM 500

int main(){
    char text[TAM], *auxp, *auxi;


    FILE *arq, *impar, *par;

    impar = fopen("lotr_cap1_odd.txt", "r");
    if(impar == NULL){
        printf("Erro em abrir o arquivo");
        exit(1);
    }

    par = fopen("lotr_cap1_even.txt", "r");
    if(par == NULL){
        printf("Erro em abrir o arquivo");
        exit(1);
    }

    arq = fopen("lotr_cap1_recovered.txt", "w");
    if(arq == NULL){
        printf("Erro em abrir o arquivo");
        exit(1);
    }

    while(1){
        auxi = fgets(text, TAM, impar);
        if(auxi != NULL){
            fprintf(arq, "%s", text);
        }else{
            exit(1);
        }

        auxp = fgets(text, TAM, par);
        if(auxp != NULL){
            fprintf(arq, "%s", text);
        }else{
            exit(1);
        }
    }
    
    fclose(impar);
    fclose(par);
    fclose(arq);
    return 0;
}