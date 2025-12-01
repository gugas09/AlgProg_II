#include <stdio.h>

//trivial case: b==0;
// Seq = a + (b - 1) + 1;

int succ(int a, int b);

int main(){
    int a, b;

    printf("Enter the 1st number: ");
    scanf("%d", &a);
    printf("Enter the 2nd number: ");
    scanf("%d", &b);

    a = succ(a, b);

    printf("a+b = %d", a);

    return 0;
}

int succ(int a, int b){
    if(b == 0){
        return a;
    }else{
        return succ(a+1, b-1);
    }
}