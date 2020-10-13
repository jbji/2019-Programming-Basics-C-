#include <stdio.h>
#include <string.h>
int isPrime(int in){
    int flag=1;
    for(int i=2;i<in;i++){
        if(in%i==0){
            flag=0;
        }
    }
    return flag;
}
int main(){
    char num[80]={'\0'};
    int out[80]={0};
    scanf("%s",num);
    for(int i=0;i<strlen(num)-1;i++){
        out[i]=isPrime(10*(num[i]-'0')+num[i+1]-'0');
    }
    for(int i=0;i<strlen(num)-1;i++){
        if(out[i]==0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}