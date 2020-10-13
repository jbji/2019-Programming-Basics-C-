#include<iostream>
#include<cstring>
using namespace std;

int seed;//ʤ�����ӣ�ע����ȫ�ֱ���
int result(){
    //���������
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
}//result������ȫ�ֱ���seed��Ϊ���ӣ��������dragon����Ķ�ս���

class dragon{
    char name[20];//�ǳ�
    int grade;//�ȼ�
    int fight;//��ս����
    int fail;//��սʧ�ܴ���
    int r_power;//����ս��
    int r_exp;//����ѵ������
    int r_win;//����սʤ����
public:
    dragon(char *);//   ���캯�������ݳ�Ա�ĸ�ֵ�����ο��������
    void train();	  /*   train��������ѵ������r_exp�Ϳ���ս��r_power������Ϊ��
	                                ��ѵ������r_exp��300�� ������Ӻ��ѵ�����㲻����2000��ս��r_power��
                                        100��ѵ������r_exp����2000    */
    void pk(dragon &);	    /*  pk����ʵ������dragon����֮���ս�����������£�
				                ֻ��ս��r_power����300��dragon����ſ��Զ�ս��
	                                         ��ս���ֱ�ӵ���result�����õ���result�ķ���ֵΪ1����ս��ʤ����
                                                result�ķ���ֵΪ0��Ӧս��ʤ����
		                                ��ս˫���Ķ�ս����fight����1��
                                                ʤ����ս��r_power��200������սʤ����r_win��1��
                                                ʧ����ս��r_power��200��ʧ�ܴ���fail��1��
                                                ����µ�սʤ����r_win������5���ȼ�ֵ��1��սʤ����r_win����5��*/
    ~dragon();   /*    ����������������Ķ�ս��������սʤ����������սʧ�ܴ�����
                                    �����ʾ��ο����ʾ��    */
    void show();
};

void dragon::show() {
    char line[]="------------------";
    cout<<line<<endl;
    cout<<"�ǳƣ�"<<name<<endl;
    cout<<"�ȼ�ֵ��"<<grade<<endl;
    cout<<"ս��������"<<fight<<endl;
    cout<<"ʧ�ܴ�����"<<fail<<endl;
    cout<<"����ս����"<<r_power<<endl;
    cout<<"����ѵ�����㣺"<<r_exp<<endl;
    cout<<"����սʤ���㣺"<<r_win<<endl;
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
        cout<<"pk������ʤ����"<<((rand)?name:d2.name)<<endl;
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
        cout<<"����ֵ����������PK"<<endl;
    }
}
dragon::~dragon(){
    char line[]="***********************";
    cout<<line<<endl;
    cout<<name<<endl;
    cout<<"ս��������"<<fight<<endl;
    cout<<"ʤ��������"<<fight-fail<<endl;
    cout<<"ʧ�ܴ�����"<<fail<<endl;
    cout<<line<<endl;
}
int main(){
    int tn,pn;
    cin>>seed; //����ʤ������
    cin>>tn; //����ѵ������
    cin>>pn; //�����ս����
    dragon red_d("sun");
    dragon blue_d("moon");
    red_d.show(); //��ʾred_d�ĳ�ʼ����
    for (int i=0 ;i<tn; i++)
        red_d.train(),blue_d.train();// ѵ����ֻС��
    red_d.show(); blue_d.show();  //��ʾС��ѵ���������
    for (int i=0 ;i<pn; i++)
        red_d.pk(blue_d); //red_d��Ϊ��ս�ߣ���blue_d�����ս��blue_dӦս
    red_d.show(); blue_d.show(); //��ʾС����ս�����������
    return 0;

}