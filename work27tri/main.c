#include <stdio.h>

int main() {
    int n=0;
    scanf("%i",&n);
    //认为正在输出的行序号为m
    //输出一整行星号
    for(int j=2*n-1;j>0;j--){
        printf("*");
    }
    printf("\n");
    for(int m=1;m<n;m++){
        //输出空格
        for(int j=m;j>0;j--){
            printf(" ");
        }
        //输出左星号
        printf("*");
        //输出空格和右星号
        for(int j=2*n-2*m-3;j>0;j--){
            printf(" ");
            if(j==1){
                printf("*\n");
            }
        }
        if(2*n-2*m-3<=0){
           printf("\n");
        }
    }
\
    return 0;
}