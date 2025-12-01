#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000  

int main() {
    int T;
    scanf("%d", &T);

    int *fila = (int *) malloc(MAX * sizeof(int));
    int ini = 0, fim = 0; 

    for (int i = 0; i < T; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int n;
            scanf("%d", &n);
            fila[fim++] = n; 
        } 
        else if (op == 2) {
            if (ini < fim) ini++; 
        } 
        else if (op == 3) {
            if (ini < fim)
                printf("%d\n", fila[ini]); 
            else
                printf("Empty!\n");
        }
    }

    free(fila);
    return 0;
}
