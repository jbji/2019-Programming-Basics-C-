#include <stdio.h>

int main() {
    //important!:"operator" is not valid in devc
    int n1,dn1,n2,dn2;
    char operator;
    int out,dOut;
    int maxDiv(int n1,int n2);
    int maxMul(int n1,int n2);
    scanf("%i/%i %c %i/%i",&n1,&dn1,&operator,&n2,&dn2);
    switch(operator){
        case '+':
            dOut=maxMul(dn1,dn2);
            out=n1*maxMul(dn1,dn2)/dn1+n2*maxMul(dn1,dn2)/dn2;
            break;
        case '-':
            dOut=maxMul(dn1,dn2);
            out=n1*maxMul(dn1,dn2)/dn1-n2*maxMul(dn1,dn2)/dn2;
            break;
        case '*':
            dOut=dn1*dn2/maxDiv(dn1*dn2,n2*n1);
            out=n1*n2/maxDiv(dn1*dn2,n2*n1);
            break;
        case '/':
            dOut=dn1*n2/maxDiv(dn1*n2,dn2*n1);
            out=n1*dn2/maxDiv(dn1*n2,dn2*n1);
            break;
    }
    if(out%dOut==0){
        printf("%i/%i %c %i/%i = %i\n",n1,dn1,operator,n2,dn2,out/dOut);
    }else{
        printf("%i/%i %c %i/%i = %i/%i\n",n1,dn1,operator,n2,dn2,out,dOut);
    }

    return 0;
}
int maxDiv(int n1,int n2){
    int n;
    do{
        if(n1<n2){
            n=n1,n2=n,n1=n2;
        }
        n1=n1-n2;
    }while(n2!=2*n1&&n1!=1&&n1!=0);
    return (n1==0?n2:n1);
}
int maxMul(int n1,int n2){
    return n1*n2/maxDiv(n1,n2);
}