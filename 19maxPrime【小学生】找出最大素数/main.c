#include <stdio.h>

int main() {
    int maxLevel=0;
    int count=0;//用于记录能整除的数量
    scanf("%i",&maxLevel);
    for(int i=maxLevel;i>0;i--){
        count=0;
        //清空整除计数器，用于进行整除
        for(int j=2;j<=i;j++){
            if(i%j==0){
                count++;
            }
        }
        //这是素数成立的条件
        if(count==1){
            printf("The max prime number is %i.\n",i);
            break;
        }
    }
    return 0;
}