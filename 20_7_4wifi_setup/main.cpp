#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N;
    double A,B;
    cin>>N>>A>>B;
    int loc[N];
    for(int i=0;i<N;i++){
        cin>> loc[i];
    }
    sort(loc,loc+N); //输入数据升序排序
    double ans=0;
    for(int inf=0,sup=0;sup<N;inf=sup){
        while(sup+1<N&&loc[sup+1]-loc[sup]<2.0*A/B){
            sup++;
        }
        ans+=A+B*(loc[sup]-loc[inf])/2.0;
        sup++;
    }

    if(ans==(int)ans){
        cout << (int)ans << endl;
    }else{
        cout << fixed << setprecision(1) << ans << endl;
    }

    return 0;
}