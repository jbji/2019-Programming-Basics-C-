#include <iostream>
#include <iomanip>

using namespace std;

//class Ball{
//public:
//    Ball():initialHeight(100){
//        cin>>n;
//    }
//    double sumHeight(){
//        double h=initialHeight;
//        double result=initialHeight;
//        for(int i=1;i<n;i++){
//            h/=2;
//            result+=2*h;
//        }
//        return result;
//    }
//    double getHeight(){
//        double result=initialHeight;
//        for(int i=0;i<n;i++){
//            result/=2;
//        }
//        return result;
//    }
//    int getN(){
//        return n;
//    }
//private:
//    const double initialHeight;
//    int n;
//};
int main() {
//    Ball myball;
//    cout<<fixed<<setprecision(4)<<"��"<<""<<myball.getN()<<"�����ʱ��"<<"������"<<""<<myball.sumHeight()<<"�ף�"<<"�����߶���"<<""<<myball.getHeight()<<"�ס�";
    int n;
    cin>>n;
    double initialH=100;
    double sumH=100,bounceH=initialH;
    double tempH=initialH;
    for(int i=1;i<n;i++){
        tempH/=2;
        sumH+=2*tempH;
        bounceH/=2;
    }
    cout<<fixed<<setprecision(4)<<"��"<<""<<n<<"�����ʱ��"<<"������"<<""<<sumH<<"�ף�"<<"�����߶���"<<""<<bounceH/2<<"�ס�";
    return 0;
}