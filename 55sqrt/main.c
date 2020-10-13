#include <stdio.h>
#define abs(a) a<0?-a:a
int main() {
    double sqrt(double,double,double);
    double x,e;

    scanf("%lf %lf",&x,&e);
    printf("%.8lf\n",sqrt(x,x+1,e));
    return 0;
}

double sqrt(double x,double p,double e){
    if(abs(p*p-x)<e){
        return p;
    }else{
        return sqrt(x,(p+x/p)/2.0,e);
    }
}