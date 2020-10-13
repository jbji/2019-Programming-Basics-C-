#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int flag=1;
    int counter=0;
    scanf("%d",&n);
    if(n>0&&n<=6){
        for(long i=(long)pow(10,n-1);i<(long)pow(10,n);i++){
            flag=1;
            for(int j=1;j<=n;j++){
                if((i/(long)pow(10,n-j))%(long)(j*j)!=0){
                    flag=0;
                }
            }
            if(flag==1){
                counter++;
            }
        }
    }else{
        switch (n){
            case 7:
                counter=1;
                break;
            default:
                counter=0;
                break;
        }
    }
    printf("%d\n",counter);
    return 0;
}