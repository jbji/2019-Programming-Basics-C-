#include <stdio.h>

int main() {
    int gcd(int,int);
    int lcm(int,int);
    int a,b;
    scanf("%d,%d",&a,&b);
    printf("最大公约数：%d\n",gcd(a,b));
    printf("最小公倍数：%d\n",lcm(a,b));
    return 0;
}
int gcd(int a,int b){
    int temp;
    while(b>0){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}