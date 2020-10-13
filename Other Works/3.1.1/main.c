#include <stdio.h>

int main() {
    int ope(int);
    void process(int);
    int n;

    scanf("%d",&n);
    process(n);

    return 0;
}
void process(int m){
    int ope(int);
    void output(int);
    int times=0;

    printf("%d",m);
    times++;
    while(ope(m)!=1){
        output(m=ope(m));
        times++;
    }
    if(m!=1){
        output(1);
        times++;
    }
    printf("\nstep=%d\n",times);
}

int ope(int n){
    return n%2==0?n/2:3*n+1;
}

void output(int m){
    printf(",%d",m);
}