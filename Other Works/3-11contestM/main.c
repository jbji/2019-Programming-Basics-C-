#include <stdio.h>
int calc(int *out,int times);
int main() {
    int a,b,c,d;
    int out;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    out=c;
    calc(&out,c-1);
    if(a==b){
        out=c;
    }
    if(d!=a&&d!=b){
        out=0;
    }
    printf("%i\n",out);
    return 0;
}

int calc(int *out,int times){
    for(int i=0;i<times;i++){
        if(*out>=1000000007){
            *out-=1000000007;
        }
        *out*=2;
    }
    if(*out>=1000000007){
        *out-=1000000007;
    }
    return *out;
}