
#include <stdio.h>

int main() {
    int year,month;
    int weekCalc(int year,int month,int day);
    int count=0;

    scanf("%i",&year);
    for(int i=1;i<=31;i++){
        if(weekCalc(year,5,i)==0){
            count++;
            if(count==2){
                printf("%i\n",i);
                break;
            }
        }
    }
    return 0;
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