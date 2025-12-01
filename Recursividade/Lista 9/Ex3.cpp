#include <stdio.h>

int digitos(int n);

int main(void){
    int n, res;

    printf("Enter you number: ");
    scanf("%d", &n);

    res = digitos(n);

    printf("\n%d has %d digits", n, res);

    return 0;
}

int digitos(int n){
    if(n/10 < 1){
        return 1;
    }else{
        return (1 + digitos(n/10));
    }
}