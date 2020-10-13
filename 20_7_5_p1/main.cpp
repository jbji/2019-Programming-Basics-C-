#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    double up,down,all;
    for(int i=0;i<T;i++){
        cin >> up >> all;
        down = 2*all-up;
        if(down > 100 || down < 0){
            cout << "Impossible" << endl;
        }else{
            cout << down <<"%:" << 100-down << "%"<< endl;
        }
    }
    return 0;
}