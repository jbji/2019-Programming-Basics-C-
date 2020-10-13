#include <iostream>
using namespace std;

int main() {
    char in,*out;
    cin>>in;
    int ascii=in;
    sprintf(out,"%d %d %d",ascii,ascii+1,ascii+2);
    cout << out << endl;
//    cout << ascii <<' '<< ascii+1 <<' '<< ascii+2 << endl;
    return 0;
}