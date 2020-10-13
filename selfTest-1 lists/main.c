#include <stdio.h>

int main() {
    double sum=0;
    double max=0;
    double min=10;
    double tmp=0;
    for(int i=0; i<10;i++){
        scanf("%lf",&tmp);
        sum+=tmp;
        max=max>tmp?max:tmp;
        min=min>tmp?tmp:min;
    }
    sum-=max;
    sum-=min;
    printf("%.2lf\n",sum/8);
    return 0;
}