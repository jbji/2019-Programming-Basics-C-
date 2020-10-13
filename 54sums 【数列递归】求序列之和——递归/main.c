#include <stdio.h>
#include <math.h>

int main() {
    int n=0;
    double f(int);
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
    }else{
        printf("%.6lf\n",f(n));
    }
    return 0;
}

double f(int n){
    if(n==1){
        return n;
    }else{
        return pow(-1,n)*(1/(double)n)+f(n-1);
    }
}