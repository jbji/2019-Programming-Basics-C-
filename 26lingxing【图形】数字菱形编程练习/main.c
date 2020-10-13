#include <stdio.h>

int main() {
    int n=0;
    scanf("%i",&n);
    //认为正在输出的行序号为m
    for(int m=0;m<n;m++){
        //输出空格
        for(int j=1;j<n-m;j++){
            printf("  ");
        }
        //输出递减数字
        for(int j=n;j>n-m;j--){
            printf("%-2d",j);
        }
        //输出递增数字
        for(int j=n-m;j<=n;j++){
            printf("%-2d",j);
        }
        printf("\n");
    }
    for(int m=n-2;m>=0;m--){
        for(int j=1;j<n-m;j++){
            printf("  ");
        }
        for(int j=n;j>n-m;j--){
            printf("%-2d",j);
        }
        for(int j=n-m;j<=n;j++){
            printf("%-2d",j);
        }
        printf("\n");
    }
    return 0;
}