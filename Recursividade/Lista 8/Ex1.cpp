#include <stdio.h>

int main(){
    int a, b, aux;

    printf("Enter the 1st number: ");
    scanf("%d", &a);
    printf("Enter the 2nd number: ");
    scanf("%d", &b);
    aux = a;

    if(b==0 || a==0){
        a = 0;
    } else{
        for(int i=1; i<b; i++){
            a += aux;
        }
    }

    printf("a*b = %d", a);

    return 0;
}