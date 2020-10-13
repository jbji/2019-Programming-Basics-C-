#include<iostream>
using namespace std;

void EKG(int ekg[100],int n);
int gcd(int,int);

int marks[1000]={0};


int main()
{
    int i, n, ekg[100]={1,2};
    cin>>n;
    EKG(ekg, n);
    cout<<*(ekg+0);
    for(i=1; i<n; i++)
        cout<<" "<<*(ekg+i);
    cout<<endl;
    system("pause");
    return 0;
}

void EKG(int ekg[100],int n){
    //清空标记数组
    for(int i=0;i<100;i++){
        marks[i]=0;
    }
    int lastBig;
    int currentIndex;
    if(n>2){
        //标记当前已有数字
        for(int i=0;i<100;i++){
            if(ekg[i]!=0){
                currentIndex=i;
                marks[ekg[i]]=1;
                lastBig=ekg[i];
                n--;
            }
        }
        //遍历正整数
        for(int i=1;n>0;i++){
            if(marks[i]==1){
                continue;
            }else{
                if(marks[i]==0&&gcd(i,lastBig)!=1){
                    ekg[++currentIndex]=i;
                    lastBig=i;
                    marks[i]=1;
                    n--;
                    i=1;
                }
            }

        }
    }

}

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}