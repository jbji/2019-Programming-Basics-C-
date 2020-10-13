#include <iostream>
#include <cstring>
using namespace std;

class phone{
    char number[12];//11位本机号码
    char city[5];//本机归属地编号
    double fee;//本机话费余额
public:
    phone(); //默认构造函数，初始值请参看输出样例第一行
    void recharge(double m);//给手机充值
    void insertcard(char[],char[]);//设置手机号码和归属地
    double  getfee();//返回本机话费
    char *getno();//返回本机号码
    char *getcity();//返回归属地
    int call(phone &other,int m);//和手机other通话m分钟，
    /*  1.归属地相同，本机支付话费，话费为每分钟0.7元。
        2.归属地不同，双方都要支付话费，本机话费为每分钟1.2元，other话费为每分钟0.7元。
        3.通话过程中，如果因为某方话费不足，通话中断，函数结束，返回实际通话时长
        通话正常完成，函数结束，返回m */
};

phone::phone():number("08600000000"),city("***"),fee(0){}
void phone::recharge(double m){
    fee+=m;
}
void phone::insertcard(char _number[] ,char _city[]){
    strcpy(number,_number);
    strcpy(city,_city);
}
double  phone::getfee(){
    return fee;
}
char *phone::getno(){
    return number;
}
char *phone::getcity(){
    return city;
}
int phone::call(phone &other,int m){
    int time=0;
    if(!strcmp(city,other.city)){ //归属地相同
        while(time<m){
            if(fee>=0.7){
                fee-=0.7;
            }else{
                time=m;
                break;
            }
            time++;
        }
    }else{
        while(time<m){
            if(fee>=1.2&&other.fee>=0.7){
                fee-=1.2;
                other.fee-=0.7;
            }else{
                time=m;
                break;
            }
            time++;
        }
    }
    return time;
}


//->测试代码
void display( phone t)
{
    cout<<"手机号码："<<t.getno()
        <<"；归属地："<<t.getcity()
        <<"；话费余额："<<t.getfee()
        <<endl;
}
int main()
{

    phone p1;
    display(p1);
    p1.insertcard("13458901211","027");	p1.recharge(40);

    phone p2,p3;
    p2.insertcard("13652901219","021");	p2.recharge(30);
    p3.insertcard("15651004523","027");	p3.recharge(50);

    char *line="*-------------------------------------------------*";
    int talk,m;
    m=35;
    talk=p1.call(p2,m);
    cout<<line<<endl;
    cout<<"p1主叫p2......."<<endl;
    if (talk==m)
        cout<<"通话时长"<<talk<<"分钟。通话结束,祝您愉快"<<endl;
    else
        cout<<"通话时长"<<talk<<"分钟。余额不足,请尽快预存话费"<<endl;
    display(p1); display(p2);
    cout<<line<<endl;

    p1.recharge(30);
    m=40;
    talk=p3.call(p1,40);
    cout<<line<<endl;
    cout<<"p3主叫p1......."<<endl;
    if (talk==m)
        cout<<"通话时长"<<talk<<"分钟。通话结束,祝您愉快........"<<endl;
    else
        cout<<"通话时长"<<talk<<"分钟。电话余额不足.......请尽快预存话费."<<endl;;
    display(p3); display(p1);
    cout<<line<<endl;

    return 0;
}

