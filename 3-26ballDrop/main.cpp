#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main( ) {
    int n;
    cin>>n;
    if(n<1||n>10){
        cin>>n;
    }
    double sum=100,h=100/pow(2,n);
    for(int i=2;i<=n;i++){
        sum=sum+100/pow(2,i-2);
    }
    cout<<fixed<<setprecision(4)<<"第"<<""<<n<<"次落地时，"<<"共经过"<<""<<sum<<"米；"<<"反弹高度是"<<""<<h<<"米。";
    return 0;
}
