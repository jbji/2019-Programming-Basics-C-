#include <stdio.h>

int main() {
    int year;
    int weekCalc(int year,int month,int day);
    int counter=0;
    scanf("%i",&year);
    for(int i=1;i<12;i++){
        if(weekCalc(year,i,13)==5){
            counter++;
        }
    }
    if(counter>1){
        printf("There are %d Black Fridays in year %d.\nThey are:\n",counter,year);
    }else{
        printf("There is %d Black Friday in year %d.\nIt is:\n",counter,year);
    }

    for(int i=1;i<12;i++){
        if(weekCalc(year,i,13)==5){
            printf("%d/%d/13\n",year,i);
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