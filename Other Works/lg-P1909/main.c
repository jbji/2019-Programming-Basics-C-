#include <stdio.h>

int main() {
    int amount;
    int quantity;
    int price;
    int tmp;
    int cost=0;
    scanf("%d",&amount);
    for(int i=0;i<3;i++){
        scanf("%d %d",&quantity,&price);
        if(amount%quantity==0){
            tmp=price*(amount/quantity);
        }else{
            tmp=price*(amount/quantity+1);
        }
        if(cost==0){
            cost=tmp;
        }
        if(cost>=tmp){
            cost=tmp;
        }
    }
    printf("%d\n",cost);
    return 0;
}