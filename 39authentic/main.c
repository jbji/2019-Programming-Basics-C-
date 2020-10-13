#include <stdio.h>
#include <string.h>
int main() {
    char input[200]={'1','\0'};
    char sub[200]={'\0'};
    int mark[128]={0};
    int i=1;
    //以支持空输入的方式获得字符串
    do{
        input[i-1]=getchar();
        i++;
    }while(input[i-2]!='\n');
    input[i-2]='\0';
    i=1;
    do{
        sub[i-1]=getchar();
        i++;
    }while(sub[i-2]!='\n');
    sub[i-2]='\0';
    //进行标记并运算
    for(int i=0;i<strlen(sub);i++){
        mark[sub[i]]++;
    }
    for(int i=0;i<strlen(input);i++){
        if(mark[input[i]]==0){
            printf("%c",input[i]);
        }
    }
    printf("\n");

}