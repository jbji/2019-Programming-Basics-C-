#include <stdio.h>
#include <math.h>
void main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a!=0){
        int d=b*b-4*a*c;
        double rx=-b/(2.0*a),ix=sqrt((d>=0?d:-d))/(2.0*a);
        if (d==0){
            printf( "x1=x2=%.6lf\n", rx);
        }else if (d>0){
            printf("x1=%.6lf\nx2=%.6lf\n",rx+ix,rx-ix);
        }else if (d<0){
            if(rx!=0){
                printf("x1=%.6lf+%.6lfi\nx2=%.6lf%.6lfi\n",rx,ix,rx,-ix);
            }else{
                printf("x1=%.6lfi\nx2=%.6lfi\n",ix,-ix);}
        }
    }else if(b!=0){
        printf( "x=%.6lf\n",-c/(1.0*b));
    }else{
        printf("Input error!\n");
    }
}