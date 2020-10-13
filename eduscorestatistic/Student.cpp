//
// Created by jbji on 20-4-17.
//

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student():sum(0), ave(0){
    cin >> NO;
    for(int i=0;i<3;i++){
        cin >> scores[i];
        sum+=scores[i];
    }
    ave=sum/3.0;
}
void Student::NOOverwrite(int no){
    this->NO=no;
}
void Student::scoreOverwrite(int j,double score){
    scores[j]=score;
    sum=0;
    for(int i=0;i<3;i++){
        sum+=scores[i];
    }
    ave=sum/3.0;
}
int Student::getNO(){
    return NO;
}
double Student::getAverage(){
    return ave;
}
double Student::getSum(){
    return sum;
}