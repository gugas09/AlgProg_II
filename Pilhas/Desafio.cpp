#include <stdio.h>
#include <string.h>

int main() {
    char s[2000];
    int caso = 1;

    while (1) {
        scanf("%s", s);

        if (s[0] == '-')   
            break;

        int pilha[2000];
        int topo = 0;
        int oper = 0;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '{') {
                pilha[topo++] = '{';
            } else { 
                if (topo > 0) {
                    topo--;  
                } else {
                    oper++;
                    pilha[topo++] = '{';
                }
            }
        }
        oper += topo / 2;

        printf("%d. %d\n", caso, oper);
        caso++;
    }

    return 0;
}
