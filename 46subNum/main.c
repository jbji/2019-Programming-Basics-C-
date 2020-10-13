#include <stdio.h>
int gSub;

int main() {
    int i,ada;
    int judge(int);
    scanf("%d",&gSub);
    ada=gSub%10==0?gSub:gSub%10;
    for(i = 10000;i%gSub!=0;i++);//寻找第一个能被整除的数
    for(;i<=30000;i+=ada){//开始遍历
        if((judge(i%1000))&&
                (judge((i/10)%1000))&&
                (judge((i/100)%1000))){
                printf("%d\n",i);
        }
    }
    return 0;
}

int judge(int a){
    if(a%gSub==0){
        return 1;
    }else return 0;
}