#include <stdio.h>

int main() {
    int UPC[13]={0};
    scanf("%d",&UPC[1]);
    getchar();
    for(int i=2;i<7;i++){
        UPC[i]=getchar()-'0';
    }
    getchar();
    for(int i=7;i<12;i++){
        UPC[i]=getchar()-'0';
    }
    getchar();
    int sum1;
    int sum2;
    int temp1;
    //完成输入获取
    sum1=UPC[1]+UPC[3]+UPC[5]+UPC[7]+UPC[9]+UPC[11];
    sum2=UPC[2]+UPC[4]+UPC[6]+UPC[8]+UPC[10];
    temp1=sum1*3+sum2-1;
    UPC[12]=9-temp1%10;

    printf("%d\n",UPC[12]);

    return 0;
}