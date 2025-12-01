#include <stdio.h>

int main(){
    int vet[8] = {1, 3, 4, 5, 17, 18, 31, 33};
    int counter = 0, x = 0, n, low = 0, mid, high = 7;

    printf("[1, 3, 4, 5, 17, 18, 31, 33]\nWhich number? ");
    scanf("%d", &n);

    mid = (low + high)/2;      

    while(n != vet[mid]){
        mid = (low + high)/2;
        counter += 1;

        if(vet[mid] > n){
            high = mid - 1;
        }else if(vet[mid] < n){
            low = mid + 1;
        }else if(vet[mid] == n){
            break;
        }

        if(counter > 5){
            printf("\nNumber out of list!");
            return 0;
        }
    }

    printf("\n%d's position: %d", n, mid);

    return 0;
}