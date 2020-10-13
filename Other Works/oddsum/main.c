#include <stdio.h>

int main() {
    int n;
    int sum(int);

    scanf("%d",&n);
    printf("%d\n",sum(2*n-1));
    return 0;
}

int sum(int n){
    if(n==1||n==2){
        return n==1?1:2;
    }else{
        return n+sum(n-2);
    }
}