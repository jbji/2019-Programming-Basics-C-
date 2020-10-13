#include<bits/stdc++.h>
using namespace std;

long long read()//快读，这个是真的有用，能节省很多时间
{
    long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main(){
    //牛的头数n，要去掉的种数k
    int n,k;
    cin>>n>>k;

    //读入Cow Line中的数据，并将这些数据转换成连续值
    map<long long,int> d_to_c;//离散输入值的连续值替身
    int cowID[100001];//牛的连续连续值编号
    for(int i=0,num_counter=0;i<n;i++)
    {
        long long s=read();//快速读入long long值数据
        if(d_to_c[s] == 0){ //如果这个离散值对应的连续值映射未曾出现
            cowID[i] = d_to_c[s] = ++num_counter;//离散值连续化，如果有没被记录就给它分配新的连续值
        }else{
            cowID[i] = d_to_c[s];//如果有被记录就赋值已分配的连续值
        }
    }


    int counter[100001]={0};//计数器，当前操作区间内的[给定编号]的数量
    int type_counter=0;//计数器，当前操作区间内的操作数种类
    int ans=0;
    for(int inf=0,sup=0; sup < n; sup++)//改为for
    {
        if(counter[cowID[sup]] == 0) type_counter++;//当前读取sup位置 连续值替身 cowID[sup]的计数值counter[cowID[sup]]若为0，则说明第一次遇到该值，种类计数器type_counter+1
        counter[cowID[sup]]++;//无论是否第一次遇见sup位置的数，连续值替身对应的计数值都+1

        while(type_counter - k > 1)
        {
            counter[cowID[inf]]--;
            if(counter[cowID[inf]] == 0){
                type_counter--;
            }
            inf++;//下界上移
        }

        ans=max(ans, counter[cowID[sup]]);//取最优值
    }
    cout<<ans;//输出
    return 0;
}
