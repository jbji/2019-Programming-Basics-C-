#include <stdio.h>

int main() {
    int scores[3][4];
    int *psc=scores;
    int n=0,counter=0;
    for(int i=0;i<12;i++){
        scanf("%d",psc+i);
    }
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        printf("%d",scores[n-1][i]);
        if(i!=3) printf(" "); else printf("\n");
        counter+=scores[n-1][i];
    }
    if(counter%4==0){
        printf("%d\n",counter/4);
    }else{
        printf("%.2f\n",(float)counter/4);
    }

    return 0;
}