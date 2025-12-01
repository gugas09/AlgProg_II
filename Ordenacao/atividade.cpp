#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *ant;
    struct cel *seg;
};
typedef struct cel celula;

void printa_lista(celula *lst);
void adiciona_celula(celula *lst, int n);
void adiciona_19(celula *lst);
void bubble_sort(celula *lst);
void selection_sort(celula *lst);

int main(){
    celula cabeca, *lst;
    cabeca.conteudo = -99; // -99 marca a cabeça
    cabeca.ant = NULL;
    cabeca.seg = NULL;
    lst = &cabeca;
    
    adiciona_19(lst);
    printa_lista(lst);
    
    printf("Bubble Sort:\n");
    bubble_sort(lst);
    printa_lista(lst);

    printf("Selection Sort:\n");
    adiciona_19(lst = &cabeca); 
    selection_sort(lst);
    printa_lista(lst);
    
    return 0;
}

void printa_lista(celula *lst){
    while(1){
        if(lst->conteudo == -99)
            printf("CABECA");
        else
            printf("%d", lst->conteudo);
        
        if(lst->seg != NULL)
            printf("->");
        else{
            printf("->NULL\n\n");
            return;
        }
        lst = lst->seg;
    }
}

void adiciona_celula(celula *lst, int n){
    celula *nova = (celula*) malloc(sizeof(celula));
    
    nova->conteudo = n;
    nova->seg = lst->seg;
    nova->ant = lst;

    if(lst->seg != NULL)
        lst->seg->ant = nova;

    lst->seg = nova;
}

void adiciona_19(celula *lst){
    celula *aux = lst->seg, *tmp;
    while(aux != NULL){
        tmp = aux->seg;
        free(aux);
        aux = tmp;
    }
    lst->seg = NULL;

    // adiciona valores desordenados para testar
    adiciona_celula(lst, 4);
    adiciona_celula(lst, 1);
    adiciona_celula(lst, 9);
    adiciona_celula(lst, 5);
    adiciona_celula(lst, 8);
    adiciona_celula(lst, 3);
    adiciona_celula(lst, 7);
    adiciona_celula(lst, 2);
    adiciona_celula(lst, 6);
}

void bubble_sort(celula *lst){
    if(lst->seg == NULL) return;

    int trocou = 1;
    celula *atual;

    while(trocou){
        trocou = 0;
        atual = lst->seg;

        while(atual->seg != NULL){
            if(atual->conteudo > atual->seg->conteudo){
                int temp = atual->conteudo;
                atual->conteudo = atual->seg->conteudo;
                atual->seg->conteudo = temp;
                trocou = 1;
            }
            atual = atual->seg;
        }
    }
}

void selection_sort(celula *lst){
    if(lst->seg == NULL) return;

    celula *i = lst->seg;

    while(i != NULL){
        celula *menor = i;
        celula *j = i->seg;

        while(j != NULL){
            if(j->conteudo < menor->conteudo)
                menor = j;
            j = j->seg;
        }

        int temp = i->conteudo;
        i->conteudo = menor->conteudo;
        menor->conteudo = temp;

        i = i->seg;
    }
}
