#include <stdio.h>

int main() {
    int a,b,counter=0;
    int isSquare(int);
    scanf("%d,%d",&a,&b);
    while(a<=b){
        if(isSquare(a++)){
            counter++;
        }
    }
    printf("%d\n",counter);
    return 0;
}

int isSquare(int a){
    for(int i=0;i*i<=a;i++){
        if(i*i==a){
            return 1;
        }
    }
    return 0;
}