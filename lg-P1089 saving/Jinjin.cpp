//
// Created by jbji on 20-1-22.
//
#include <iostream>
#include "Jinjin.h"
using namespace std;

Jinjin::Jinjin() {
    balance=0;
    currentMonth=1;
    insfiMon=0;
    momDpst=0;
}

Jinjin::~Jinjin() {
    getResult();
}

int Jinjin::nextMonth() {
    //money from mom
    balance+=300;
    //get budget;
    int tmp;
    cin >> tmp;
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
        return 1;
    }else{
        return 0;
    }


}

void Jinjin::getResult(){
    if(insfiMon){
        cout << "-" << insfiMon << endl;
    }else{
        cout << (int)(balance+1.2*momDpst) << endl;
    }
}