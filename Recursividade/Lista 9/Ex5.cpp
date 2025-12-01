#include <stdio.h>

float serie(int n);

int main(void){
    int n;
    float res;

    printf("Enter you number: ");
    scanf("%d", &n);

    res = serie(n);

    printf("\nThe %d number from the serie is %f", n, res);

    return 0;
}

float serie(int n){
    if(n == 1){
        return 1;
    }else if((n%2) == 0){
        return 1.0/n + serie(n-1);
    }else{
        return serie(n-1) - 1.0/n; 
    }
}