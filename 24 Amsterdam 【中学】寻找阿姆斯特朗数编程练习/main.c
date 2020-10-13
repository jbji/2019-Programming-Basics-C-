#include <stdio.h>
#include <math.h>
int main() {
    int n;
    int stor[10];
    int counter=0;
    int sum=0;
    scanf("%i",&n);
    int limit=pow(10,n);
    //枚举各个数字
    for(int i=pow(10,n-1);i<=limit;i++){
        sum=0;
        //获得各位数字
        for(int j=1;j<=n;j++){
            stor[j-1]=(i%((int)pow(10,j)))/pow(10,j-1);
            sum+=pow(stor[j-1],n);
        }
        if(sum==i){
            printf("%i\n",i);
            counter++;
        }
    }
    if(counter==0){
        printf("No output.\n");
    }
    return 0;
}