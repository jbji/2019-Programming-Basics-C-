#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++){
        printf("%3i",i);
        if(i%n==0){
            printf("\n");
        }
    }
    return 0;
}