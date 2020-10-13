#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int st[10];
    for(int i=0;i<10;i++){
        cin>>st[i];
    }
    int top=0;
    int num=0;
    int l=0;
    for(int j=0;j<10;j++){
        for(int k=1;k<10;k++){
            if(st[j]-st[k]>=0&&k==9){
                top=st[j];
                cout<<"最高分为"<<top<<endl;
                j=10;
                break;
            }
            if(st[j]-st[k]<0){
                break;
            }
        }
    }
    for(int j=0;j<10;j++){
        if(top-st[j]==0){
            num++;
        }
    }
    cout<<"获得最高分的共有"<<num<<"人"<<endl;
    cout<<"获得最高分的同学编号为";
    for(int j=0;j<10;j++) {
        if (top - st[j] == 0&&l<num-1) {
            cout << j+1 <<',';
            l++;
        }
    }
    for(int j=9;j>=0;j--) {
        if (top - st[j] == 0) {
            cout << j+1 ;
            break;
        }
    }
    return 0;
}