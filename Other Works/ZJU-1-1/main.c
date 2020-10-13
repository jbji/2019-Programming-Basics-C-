#include <stdio.h>
#include <string.h>


int main() {
    char in1[1000]={0};
    char in2[10000]={0};
    gets(in1);
    gets(in2);
    char *p2=in2;
    int times=0;
    while(p2-in2<=strlen(in2)){
        if(strstr(p2,in1)){
            printf("%d ",strstr(p2,in1)-in2);
            times++;
        }
        p2=strstr(p2,in1)+1;
    }
    if(times==0){
        printf("%d",-1);
    }
    return 0;
}