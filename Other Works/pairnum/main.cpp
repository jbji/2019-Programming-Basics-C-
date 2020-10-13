#include <iostream>
#include <cmath>
#include<string>
int numPairs(int m,int n, int num[100][2]);
int realRoots(int n);
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    if(m>n){
        cout<<"输入错误";
        cin>>m>>n;
    }
    int i=0,j=0;
    for(i=(m/2)*2;i<=n;i+=2) {
        for (j = i+2 ; j <= n; j+=2) {
            if (realRoots(j) == i && realRoots(i) == j) {
                cout << "(" << i << ',' << j << ')' << endl;
                continue;
            }
        }
    }
    return 0;
}
int realRoots(int n){
    int k=sqrt(n);
    int ans=1;
    int r=0;
    for(int i=2;i<=k;i++)
    {
        if(n%i==0)
        {
            ans+=i;
            r=n/i;
            ans+=r;
        }
    }
    if(k*k==n)
        ans-=k;
    return ans;
}
/*int numPairs(int m,int n, int num[100][2]){
    int i=0,j=0,k=0,l=0,p=0,sum1=0,sum2=0;
    for(i=m,sum1=0,sum2=0;i<=n;i++){
        for(j=m;i<=n&&j!=i;j++){
            for(k=1;k<i;k++){
                if(i%k!=0){
                    continue;
                }
                else{
                    sum1+=k;
                }
            }
            for(l=0;l<j;l++){
                if(j%l!=0){
                    continue;
                }
                else{
                    sum2+=l;
                }
            }
            if(sum2==i&&sum1==j){
                num[p][1]=m;
                num[p][2]=n;
                p++;
            }
            cout<<"("<<num[p][1]<<','<<num[p][2]<<')'<<endl;
        }
    }
}*/