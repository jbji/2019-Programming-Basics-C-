#include <iostream>
#include <cmath>
int main() {
    int n;
    std::cin>>n;
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
    std::cout<<ans<<std::endl;
}