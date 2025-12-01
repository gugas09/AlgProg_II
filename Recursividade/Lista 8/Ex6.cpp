#include <stdio.h>

int mdc(int x, int y);

int main(void){
    int x, y, res;

    printf("Enter the 1st number: ");
    scanf("%d", &x);
    printf("Enter the 2nd number: ");
    scanf("%d", &y);

    res = mdc(x, y);
    
    printf("mdc(%d, %d) = %d", x, y, res);
}

int mdc(int x, int y){
    int aux = x;

    if(x < y){
        x = y;
        y = aux;
    }

    if(y == 0){
        return x;
    }

    if(y <= x && x%y == 0){
        return y;
    }else{
        return mdc(y, x%y);
    }
}