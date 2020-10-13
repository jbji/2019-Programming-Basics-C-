#include <stdio.h>


int main() {
    char in[1000];
    char *p;
    gets(in);
    p=in;
    int flag=-1;
    while(*p!='\0'){
        if(flag==0){
            printf("\n");
            flag=-1;
        }
        if(*(p+1)-*p==1||*(p+1)-*p==-1){
            flag=1;
            printf("%c",*p);
            p++;
            continue;
        }
        if(flag==1){
            printf("%c",*p);
            flag=0;
        }
        p++;
    }
    if(flag==1){
        printf("\n");
    }
    return 0;
}