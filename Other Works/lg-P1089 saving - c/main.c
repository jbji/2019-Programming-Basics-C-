#include <stdio.h>

int main() {
    int balance=0;
    int currentMonth=1;
    int insfiMon=0;
    int momDpst=0;
    int flag=1;
    while(flag){
        //money from mom
        balance+=300;
        //get budget;
        int tmp;
        scanf("%d",&tmp);
        if(balance<tmp&&insfiMon==0){
            insfiMon=currentMonth;
        }
        //deposit money
        if(balance-tmp>=100){
            momDpst+=balance-tmp-(balance-tmp)%100;
            balance=tmp+(balance-tmp)%100;
        }
        //spend the money
        balance-=tmp;
        if(currentMonth!=12){
            currentMonth++;
            flag=1;
        }else{
            flag=0;
        }
    }
    if(insfiMon){
        printf("-%d\n",insfiMon);
    }else{
        printf("%d\n",(int)(balance+1.2*momDpst));
    }
    return 0;
}