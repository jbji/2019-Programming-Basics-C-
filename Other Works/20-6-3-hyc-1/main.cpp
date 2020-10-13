#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int detection(char a[12],char b[9]);
int main()
{
    char number[12];
    char merchant[9];
    cin>>number;
    if(detection(number, merchant))
        cout<<merchant<<endl;
    else
        cout<<"不确定"<<endl;
    return 0;
}
int detection(char a[],char b[]){
    //data for comparation
    map<int,int> merchants;
    int data[3][25]={{133,149,153,173,177,180,181,189,191,199},
                     {130,131,132,145,155,156,166,171,175,176,185,186},
                     {134,135,136,137,138,139,147,150,151,152,157,158,159,172,178,182,183,184,187,188,198}};
    for(int i=0;i<3;i++){
        for(int j=0;j<25;j++){
            merchants[data[i][j]]=i+1;
        }
    }
    int numberinit = (a[1] - '0') * 10 + ( a[2] - '0');
    int result=1;
    switch (merchants[numberinit]){
        case 1:
            strcpy(b,"中国电信");
            break;
        case 2:
            strcpy(b,"中国联通");
            break;
        case 3:
            strcpy(b,"中国移动");
            break;
        default:
            result=0;
            break;
    }
    return result;
}