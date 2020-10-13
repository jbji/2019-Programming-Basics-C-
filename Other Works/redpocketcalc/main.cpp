#include <iostream>

int main() {
    int ds[]={31,28,31,30,31,30,31,31,30,31,30,31};
    double sum=0;
    for(int i=0;i<12;i++){
        for(int j=1;j<=ds[i];j++){
            sum+=i+1+0.01*j;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}