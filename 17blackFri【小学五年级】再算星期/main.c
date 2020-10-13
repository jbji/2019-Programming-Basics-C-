//    debug utility
//    for(int i=1900;i<3000;i++){
//        for(int j=1;j<14;j++){
//            for(int k=1;k<32;k++){
//                year=i,month=j,day=k;
//
//            }
//        }
//    }

#include <stdio.h>

int main() {
    int year,month,day;
    int weekCalc(int year,int month,int day);
    int inputJudge(int year,int month,int day);

    scanf("%i %i %i",&year,&month,&day);
    switch(inputJudge(year,month,day)){
        case 0:
            printf("%i\n",weekCalc(year,month,day));
            break;
        case 1:
            printf("day is error.\n");
            break;
        case 2:
            printf("month is error.\n");
            break;
//        case 3:
//            printf("year is error.\n");
//            break;
    }
    return 0;
}
//&&year%3200!=0)||(year%172800==0
_Bool isLeap(int year){
    if((year%4==0&&year%100!=0)||(year%400==0)){
        return 1;
    }else{
        return 0;
    }

}
int weekCalc(int year,int month,int day){
    //Algorithm : Kim larsen calculation formula
    auto int output=0;

    if(month==1||month==2){
        month+=12;
        year-=1;
    }

    output = day+ 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400+1;
    return output%7;
}