#include<iostream>
#include<cstring>
using namespace std;

int seed;//胜负种子，注意是全局变量
int result(){
    //随机数数组
    int r[100]={41,18467,6334,26500,19169,15724,11478,29358,26962,24464,5705,

                28145,23281,16827,9961,491,2995,11942,4827,5436,32391,14604,3902,153,292,

                12382,17421,18716,19718,19895,5447,21726,14771,11538,1869,19912,25667,26299,

                17035,9894,28703,23811,31322,30333,17673,4664,15141,7711,28253,6868,25547,

                27644,32662,32757,20037,12859,8723,9741,27529,778,12316,3035,22190,1842,

                288,30106,9040,8942,19264,22648,27446,23805,15890,6729,24370,15350,15006,

                31101,24393,3548,19629,12623,24084,19954,18756,11840,4966,7376,13931,26308,

                16944,32439,24626,11323,5537,21538,16118,2082,22929,16541};
    seed++;
    return (r[seed%100]%2);
}//result函数以全局变量seed作为种子，随机产生dragon对象的对战结果

class dragon{
    char name[20];//昵称
    int grade;//等级
    int fight;//对战次数
    int fail;//对战失败次数
    int r_power;//可用战力
    int r_exp;//可用训练绩点
    int r_win;//可用战胜绩点
public:
    dragon(char *);//   构造函数，数据成员的赋值结果请参看输出样例
    void train();	  /*   train函数提升训练绩点r_exp和可用战力r_power。规则为：
	                                将训练绩点r_exp加300。 如果增加后的训练绩点不低于2000，战力r_power加
                                        100，训练绩点r_exp消耗2000    */
    void pk(dragon &);	    /*  pk函数实现两个dragon对象之间的战斗。规则如下：
				                只有战力r_power大于300的dragon对象才可以对战。
	                                         对战结果直接调用result函数得到。result的返回值为1，挑战者胜利，
                                                result的返回值为0，应战者胜利。
		                                对战双方的对战次数fight都加1。
                                                胜利者战力r_power加200，可用战胜绩点r_win加1。
                                                失败者战力r_power减200，失败次数fail加1。
                                                如果新的战胜绩点r_win不低于5，等级值加1，战胜绩点r_win消耗5。*/
    ~dragon();   /*    析构函数，输出龙的对战次数、对战胜利次数、对战失败次数，
                                    输出提示请参看输出示例    */
    void show();
};

void dragon::show() {
    char line[]="------------------";
    cout<<line<<endl;
    cout<<"昵称："<<name<<endl;
    cout<<"等级值："<<grade<<endl;
    cout<<"战斗次数："<<fight<<endl;
    cout<<"失败次数："<<fail<<endl;
    cout<<"可用战力："<<r_power<<endl;
    cout<<"可用训练绩点："<<r_exp<<endl;
    cout<<"可用战胜绩点："<<r_win<<endl;
    cout<<line<<endl;
}

dragon::dragon(char *_name): grade(0),fight(0),fail(0),r_power(0),r_exp(0),r_win(0){
    strcpy(name,_name);
}

void dragon::train() {
    r_exp+=300;
    if(r_exp>=2000){
        r_power+=100;
        r_exp-=2000;
    }
}
void dragon::pk(dragon &d2){
    int rand=result();
    if(r_power>300&&d2.r_power>300){
        cout<<"pk结束，胜者是"<<((rand)?name:d2.name)<<endl;
        fight++;
        d2.fight++;
        if(rand){
            this->r_power+=200;
            this->r_win+=1;
            d2.r_power-=200;
            d2.fail+=1;
            if(r_win>=5){
                grade+=1; r_win-=5;
            }
        }else{
            d2.r_power+=200;
            d2.r_win+=1;
            r_power-=200;
            fail+=1;
            if(d2.r_win>=5){
                d2.grade+=1; d2.r_win-=5;
            }

        }
    }else{
        cout<<"武力值不够，不能PK"<<endl;
    }
}
dragon::~dragon(){
    char line[]="***********************";
    cout<<line<<endl;
    cout<<name<<endl;
    cout<<"战斗次数："<<fight<<endl;
    cout<<"胜利次数："<<fight-fail<<endl;
    cout<<"失败次数："<<fail<<endl;
    cout<<line<<endl;
}
int main(){
    int tn,pn;
    cin>>seed; //输入胜负种子
    cin>>tn; //输入训练次数
    cin>>pn; //输入对战次数
    dragon red_d("sun");
    dragon blue_d("moon");
    red_d.show(); //显示red_d的初始数据
    for (int i=0 ;i<tn; i++)
        red_d.train(),blue_d.train();// 训练两只小龙
    red_d.show(); blue_d.show();  //显示小龙训练后的数据
    for (int i=0 ;i<pn; i++)
        red_d.pk(blue_d); //red_d作为挑战者，向blue_d发起对战，blue_d应战
    red_d.show(); blue_d.show(); //显示小龙对战结束后的数据
    return 0;

}