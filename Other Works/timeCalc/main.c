#include <stdio.h>

int main()
{
    int hour1,minute1;
    int hour2,minute2;
    scanf("%d %d",&hour1,&minute1);
    scanf("%d %d",&hour2,&minute2);
    int dh=hour2-hour1;
    int dm=minute2-minute1;
    if(hour2*100+minute2<hour1*100+minute1){
        dh=hour1-hour2;
        dm=minute1-minute2;
    }
    if(dm>=0){
        printf("时间差是%d时%d分",dh,dm);
    }else{
        printf("时间差是%d时%d分",dh-1,dm+60);
    }
    return 0;
}
