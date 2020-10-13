#include <stdio.h>

int calc(int,int,char);

int main() {
    int a,b;
    char op;
    scanf("%d%c%d",&a,&op,&b);
    printf("%d\n",calc(a,b,op));
    return 0;
}

int calc(int a, int b, char op){
    int result=0;
    switch(op){
        case '+':
            result= a+b;
            break;
        case '-':
            result= a-b;
            break;
        case '*':
            result= a*b;
            break;
        case '/':
            result= a/b;
            break;
    }
    return result;
}