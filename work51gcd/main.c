#include <stdio.h>

int main() {
    int gcd(int,int);
    int n,m;
    scanf("%d,%d",&n,&m);

    printf("%d\n",gcd(m,n));
    return 0;
}

int gcd(int m,int n){
    if(n<m){
        return gcd(n,m);
    }else if(n%m==0){
        return m;
    }else{
        return gcd(m,n%m);
    }
}