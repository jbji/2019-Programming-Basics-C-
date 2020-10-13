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
    //我们不排序，另辟蹊径
    for(int i=0;i<strlen(sub);i++){
        mark[sub[i]]++;
    }
    for(int i=0;i<strlen(input);i++){
        mark[input[i]]++;
    }
    //这样就可以输出了
    for(int i=0;i<128;i++){
        for(int j=0;j<mark[i];j++){
            printf("%c",i);
        }
    }
    printf("\n");
    return 0;
}