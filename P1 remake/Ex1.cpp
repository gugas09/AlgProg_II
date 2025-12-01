#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int code;
    char desc[200];
    float price;
    int counter;
} products;

int main(){
    int n, i, aux = 1, rnum;
    float tprice = 0;
    products *order;

    printf("How many products? ");
    scanf("%d", &n);

    if(n>10){
        return 0;
    }

    order = (products *) malloc(sizeof(products) * n);

    for(i=0; i<n; i++){
        printf("\nEnter product's code: ");
        scanf("%d", &order[i].code);

        printf("Enter product's description: ");
        scanf("%s", &order[i].desc);

        printf("Enter  product's price: ");
        scanf("%f", &order[i].price);
        
        order[i].counter = 0;
    }

    while(aux != 0){
        printf("\nOrder's code: ");
        scanf("%d", &aux);

        if(aux == 0){
            break;
        }else{
            printf("Number of requests: ");
            scanf("%d", &rnum);

            for(i=0; i<n; i++){
                if(aux == order[i].code){
                    order[i].counter += rnum;

                    tprice = tprice + order[i].price * rnum;
                }
            }
        }
    }

    printf("\nORDER FINISHED\n");

    for(i=0; i<n; i++){
        if(order[i].counter > 0){
            printf("%d x %s\n", order[i].counter, order[i].desc);
        }
    }

    printf("TOTAL US$ %.2f\n", tprice);
	
	free(order);
	
    return 0;
}
