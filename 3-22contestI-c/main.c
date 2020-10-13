#include <stdio.h>
#include <math.h>
double calc(int x1,int y1,int x2, int y2);
int main() {
    int n;
    double result=100000000,tmp=0;
    scanf("%d",&n);
    int p[2*n];
    for(int i=0;i<2*n;i+=2){
        scanf("%d %d",&p[i],&p[i+1]);
    }
    for(int i=0;i<2*n;i+=2){
        for(int j=i+2;j<2*n;j+=2){
            tmp=calc(p[i],p[i+1],p[j],p[j+1]);
            if(result>tmp){
                result=tmp;
            }
        }
    }
    printf("%.6f\n",result);
    return 0;
}
double calc(int x1,int y1,int x2, int y2){
    return sqrt(x1*x1+y1*y1)+sqrt(x2*x2+y2*y2)+sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}