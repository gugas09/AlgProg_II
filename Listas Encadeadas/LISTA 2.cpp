#include <stdio.h>
#include <stdlib.h>

struct cel{
	int conteudo;
	struct cel *seg;
};
typedef struct cel celula;

void insira(int x, celula *p);
void imprima(celula *p);
void remova_tudo(celula *p);
void remova_tudoR(celula *p);
int conte_celulas(celula *p);
void funde_listas(celula *p, celula *q);

int main(void){
	celula c, c2, *lst, *lst2;
	
	c2.seg = NULL;
	lst2 = &c2;
	
	c.seg = NULL;
	lst = &c;
	
	return 0;
}

void insira(int x, celula *p){
	celula *nova;
	
	nova = (celula *) malloc(sizeof(celula));
	
	nova->conteudo = x;
	nova->seg = p->seg;
	p->seg = nova; 
}

void imprima(celula *p){
	printf("CABECA:\n");
	while(1){
		printf("VALOR: %d\n", p->conteudo);
		printf("ENDERECO SEGUINTE: %p\n\n", p->seg);
		if(p->seg == NULL){
			break;
		}
		p = p->seg;
	}
	printf("\n\n");
}

void remova_tudo(celula *p){
	celula *aux;
	
	aux = (celula *) malloc(sizeof(celula));
	
	while(p->seg != NULL){
		aux = p->seg;
		p->seg = aux->seg;
		free(aux);
	}
}

void remova_tudoR(celula *p){
	celula *aux;
	
	aux = (celula *) malloc(sizeof(celula));
	
	if(p->seg == NULL){
		free(aux);
		return;
	}else{
		aux = p->seg;
		p->seg = aux->seg;
		free(aux);
		remova_tudo(p);
	}
}

int conte_celulas(celula *p){
	int cont = 0;
	while(p->seg != NULL){
		cont += 1;
		p = p->seg;
	}
	return cont;
}

void funde_listas(celula *p, celula *q){
	while(p->seg != NULL){
		p = p->seg;
	}
	p->seg = q->seg;
}



