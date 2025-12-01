#include <stdio.h>
#include <stdlib.h>

struct cel{
	int conteudo; 
	struct cel *seg;
};
typedef struct cel celula;

void insira(int x, celula *p);
int printacel(celula *p);
void remova_seguinte(celula *p);
void busque_e_remova(int x, celula *p);

int main(void){
	celula c, *lst;
	
	c.conteudo = NULL;
	c.seg = NULL;
	lst = &c;
	
	return 0;
}

void insira(int x, celula *p){
	celula *nova;
	
	nova = (celula*) malloc(sizeof(celula));
	
	nova->seg = p->seg;
	nova->conteudo = x;
	p->seg = nova;
	
	
}

int printacel(celula *p){
	
	printf("CABECA:\n");
	while(1){
	
		printf("Conteudo: %d\n", p->conteudo);
		printf("Endereco: %p\n\n", p->seg);
		if(p->seg == NULL){
			return 0;
		}
		p = p->seg;
	}
}

void remova_seguinte(celula *p){
	celula *aux;
	
	aux = (celula *) malloc(sizeof(celula));
	
	aux = p->seg;
	p->seg = aux->seg; 
	free(aux);
}

void busque_e_remova(int x, celula *p){
	celula *aux;
	
	aux = (celula *) malloc(sizeof(celula));
	
	aux = p->seg;
	
	while(1){
		if(aux->conteudo == x){
			break;
		}else if(aux->conteudo != x && aux->seg == NULL){
			printf("\n\n\n%d nao encontrado!\n\n", x);
			return;
		}else{
			aux = aux->seg;
			p = p->seg;
		}
	}
	p->seg = aux->seg;
	free(aux);
}
