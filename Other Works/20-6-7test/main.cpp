#include <iostream>
#include <cstring>
using namespace std;
void fun(int a[],int n){
    int j;
    static int m=0;
    for(j=0;j<n;j++){
        a[j]+=j+m;
    }cout<<a[m++]<<" ";
}

class A{
public:
    int m;
};
int main() {

}