#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    double area(const int*p1,const int*p2,const int*p3);

    int t=0;
    scanf("%d",&t);
    for(;t>0;t--){
        int n=0;
        scanf("%d",&n);

        int *pts=(int *)malloc(sizeof(int)*2*n);
        double temp=0,output=0;
        //input
        for(int i=0;i<2*n;i++){
            scanf("%d",pts+i);
        }
        //area calc
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    temp=area(pts+2*i,pts+2*j,pts+2*k);
                    if(temp>output) output=temp;
                }
            }
        }
        printf("%.1lf\n",output);
        //free the memory
        free(pts);
    }
    return 0;
}

double area(const int*p1,const int*p2,const int*p3){
    //vector way to calculate the area;
    double a[2]={*(p1+1)-*(p2+1),*(p1)-*(p2)};
    double b[2]={*(p3+1)-*(p2+1),*(p3)-*(p2)};
    double result = sqrt((a[0]*a[0]+a[1]*a[1])*(b[0]*b[0]+b[1]*b[1])-pow(a[0]*b[0]+a[1]*b[1],2));
    return result/2;
}