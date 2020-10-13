#include <stdio.h>

void main() {
    double s,c;
    scanf("%lf%lf",&s,&c);
    c*=(s>=0&&s<60)?0:((s>=60&&s<70)?1:((s>=70&&s<80)?1.1:((s>=80&&s<90)?1.2:((s>=90&&s<=100)?1.4:-1))));
    if(c>=0){
        if(c!=0){
            printf("%.2lf\n",c);
        }else{
            printf("0\n");
        }
    }else{
        printf("Error.\n");
    }
}