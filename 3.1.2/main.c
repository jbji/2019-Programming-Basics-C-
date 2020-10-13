#include <stdio.h>

int main() {
    int sells[100]={0};
    int n;
    int pro(int);

//    scanf("%d",&n);
    n=2;
    for(int i=6;i>=0;i--){
        sells[i]=pro(n)-n;
        n=pro(n);
    }
    printf("sum=%d\n",n);
    for(int i=0;i<=6;i++){
        printf("sell=%d,",sells[i]);
    }
    printf("\n");

    return 0;
}

int pro(int n){
    return 2*(n+1);
}