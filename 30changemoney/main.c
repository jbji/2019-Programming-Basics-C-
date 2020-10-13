#include <stdio.h>

int main() {
    int n,j=0;
    int k1=0,k2=0,k3=0;
    scanf ("%d",&n);

    for(int i=9;0.1*k1+0.5*k2+1.0*k3<10*n;i+=9){
        k3=i;
        k2=4*k3/3;
        k1=10*k3/9;
        if((int)(0.1*k1+0.5*k2+1.0*k3)==10*n){
            printf("%d,%d,%d\n",k1,k2,k3);
            j=1;
        }
    }
    if (j==0){
        printf("No change.\n");
    }
    return 0;
}