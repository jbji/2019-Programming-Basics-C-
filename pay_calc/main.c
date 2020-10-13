#include <stdio.h>

int main() {
    int times;
    double sum=0;
    scanf("%d",times);
    for(int i=0;i<times;i++){
        sum+=1.0/((i+10)/10);
    }
    printf("%d\n",sum);
    return 0;
}