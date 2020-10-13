#include <stdio.h>

int main(){
    int result=0;
    int num;
    scanf("%d",&num);
    while(result>=10||result==0){
        result=0;
        while(num>0){
            result+=num%10;
            num/=10;
        }
        num=result;
    }
    printf("%d\n",result);
}