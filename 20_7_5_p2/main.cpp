#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str1[200],str2[200];
    char tmpstr[200];
    cin >> str1 >> str2;
    int len = strlen(str1);
    bool isFound=false;
    for(int i=0;i<len;i++){
        for(int j=i,k=0;j<len;j++,k++){
            tmpstr[k]=str1[j];
        }
        for(int j=0,k=len-i;j<i;j++,k++){
            tmpstr[k]=str1[j];
        }
        tmpstr[len]='\0';
        if(strcmp(str2,tmpstr)==0){
            isFound=true;
            break;
        }
//        cout << tmpstr <<endl;
    }
    std::cout << (isFound?"YES":"NO") << std::endl;
    return 0;
}