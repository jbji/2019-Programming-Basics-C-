#include<iostream>
#include<cmath>
using namespace std;
int main()
{

    int n; //数组长度
    cin>>n;
    int in[n];
    //临时变量
    int tmpDigit[10];//拆解用临时存储
    int isLoop;
    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<=n-1;i++){
        cin >> in[i];
    }
    for(i=0;i<=n-1;i++){
        //数字拆解
        int tmpIn=in[i];
        for(j=0; tmpIn != 0 ; j++){
            tmpDigit[j]= tmpIn % 10;
            tmpIn /= 10;
        }
        j--;
        //判断originIn[i]是否是一个回文数
        //k是第一个位置而j是最后一个位置
        isLoop=1;
        for(k=0;k<=j;k++,j--){
            if(tmpDigit[k] != tmpDigit[j]){
                isLoop=0;
            }
        }
        if(isLoop){
            cout << in[i] << " is a loop number."<< endl;
        }else{
            cout << in[i] << " is not a loop number."<<endl;
        }
    }


    return 0;
}