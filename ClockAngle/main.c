#include <stdio.h>
void main(){
    int a,b;
//    scanf("%d%d", &a, &b);

    double p;
    for(int i=0;i<12;i++){
        for(int j=0;j<60;j++){
            a=i;
            b=j;
    p=5.5*b-30.0*a;
    printf("At %d:%02d the angle is %.1lf degrees.\n",a,b,((p>0?p:-p)>=180.0)?(360.0-(p>=0?p:-p)):(p>=0?p:-p));
}}}