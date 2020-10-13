#include <iostream>

using namespace std;

int main() {
    int n,k;
    cin >> n>> k;
    int price [n];
    for(int i=0;i<n;i++){
        cin>> price[i];
    }
    int maxn = n;
    int ans;
    for(int i=0,j=0;i<maxn;i++,j++){
        if(j==k){
            j=0;
            maxn--;
            if(i==maxn) break;
        }
        ans+=price[i];
    }
    std::cout << ans << std::endl;
    return 0;
}