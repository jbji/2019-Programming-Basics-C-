#include <iostream>
using namespace std;

int main() {
    int n,cnt=0;
    cin>>n;
    for(int max=0; max <= n; max++){
        for(int min=0; min < max - 1; min++){
            if(n==max*(max+1)/2-min*(min+1)/2){
                cout<<n<<"=";
                for(int p= min + 1; p < max; p++){
                    cout<<p<<"+";
                }
                cout << max << endl;
                cnt++;
            }
        }
    }
    if(cnt==0){
        cout<<n<<"="<<n<<endl;
    }
    return 0;
}

