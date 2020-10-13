#include <stdio.h>

int main() {
    int n;
    int sum(int);
    scanf("%d",&n);

    printf("%d\n",sum(n));
    return 0;
}

int sum(int m){
    return m%10+(m/10==0?0:sum(m/10));
}