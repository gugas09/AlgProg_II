#include <stdio.h>

int gfib(int f0, int f1, int n);

int main(){
    int f0 = 0, f1 = 1, n, res;

    printf("Which number of fibonacci sequence? ");
    scanf("%d", &n);

    res = gfib(f0, f1, n);

    printf("The %d number of the sequence: %d", n, res);

    return 0;
}

int gfib(int f0, int f1, int n){
    if(n == 0){
        return f0;
    }else if(n == 1){
        return f1;
    }else{
        return (gfib(f0, f1, n-1) + gfib(f0, f1, n-2));
    }
}