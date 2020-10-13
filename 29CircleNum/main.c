#include <stdio.h>

int n;
int sum;    //矩阵数字总个数
int flag = 1;


void printPattern(int layer,int pattern[n][n]) {

    // 上：赋值
    for (int i = layer; i < n - layer - 1; i++) {
        pattern[layer][i] = flag++;
        if (flag > sum)
            return;
    }
    // 右：赋值
    for (int i = layer; i < n - layer - 1; i++) {
        pattern[i][n - layer - 1] = flag++;
        if (flag > sum)
            return;
    }
    // 下：赋值
    for (int i = n - layer - 1; i > layer; i--) {
        pattern[n - layer - 1][i] = flag++;
        if (flag > sum)
            return;
    }
    // 左：赋值
    for (int i = n - layer - 1; i > layer; i--) {
        pattern[i][layer] = flag++;
        if (flag > sum)
            return;
    }

    printPattern(++layer);
}

int main() {
    scanf("%i",&n);
    int pattern[n][n];
    //预处理奇偶数不同
    if(n%2==0)
        sum=n*n;
    else{
        sum=n*n-1;
        pattern[(n-1)/2][(n-1)/2]=n*n;
    }

    printPattern(0,pattern[n][n]);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            printf("%i\t",pattern[i][j]);
        }
        printf("\n");
    }


    printf("Hello, World!\n");
    return 0;
}