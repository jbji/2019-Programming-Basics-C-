#include <iostream>
#include <cstring>
using namespace std;

class phone{
    char number[12];//11λ��������
    char city[5];//���������ر��
    double fee;//�����������
public:
    phone(); //Ĭ�Ϲ��캯������ʼֵ��ο����������һ��
    void recharge(double m);//���ֻ���ֵ
    void insertcard(char[],char[]);//�����ֻ�����͹�����
    double  getfee();//���ر�������
    char *getno();//���ر�������
    char *getcity();//���ع�����
    int call(phone &other,int m);//���ֻ�otherͨ��m���ӣ�
    /*  1.��������ͬ������֧�����ѣ�����Ϊÿ����0.7Ԫ��
        2.�����ز�ͬ��˫����Ҫ֧�����ѣ���������Ϊÿ����1.2Ԫ��other����Ϊÿ����0.7Ԫ��
        3.ͨ�������У������Ϊĳ�����Ѳ��㣬ͨ���жϣ���������������ʵ��ͨ��ʱ��
        ͨ��������ɣ���������������m */
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
    if(!strcmp(city,other.city)){ //��������ͬ
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


//->���Դ���
void display( phone t)
{
    cout<<"�ֻ����룺"<<t.getno()
        <<"�������أ�"<<t.getcity()
        <<"��������"<<t.getfee()
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
    cout<<"p1����p2......."<<endl;
    if (talk==m)
        cout<<"ͨ��ʱ��"<<talk<<"���ӡ�ͨ������,ף�����"<<endl;
    else
        cout<<"ͨ��ʱ��"<<talk<<"���ӡ�����,�뾡��Ԥ�滰��"<<endl;
    display(p1); display(p2);
    cout<<line<<endl;

    p1.recharge(30);
    m=40;
    talk=p3.call(p1,40);
    cout<<line<<endl;
    cout<<"p3����p1......."<<endl;
    if (talk==m)
        cout<<"ͨ��ʱ��"<<talk<<"���ӡ�ͨ������,ף�����........"<<endl;
    else
        cout<<"ͨ��ʱ��"<<talk<<"���ӡ��绰����.......�뾡��Ԥ�滰��."<<endl;;
    display(p3); display(p1);
    cout<<line<<endl;

    return 0;
}

