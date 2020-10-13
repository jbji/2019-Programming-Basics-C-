#include <iostream>
#define LIMIT 100
using namespace std;

int main() {
    char characters[LIMIT]={0};//用于保存输入的字符串
    int result[129]={0}; //用于保存结果的数组 下标是ascii值
    char out=0; //用于转换int数称为char字符
    cin.getline(characters,LIMIT); //获得输入
    for(int i=0;i<LIMIT;i++){
        if(characters[i]!=0){//不统计0
            //算法核心
            result[characters[i]]+=1;
        }
    }
    for(int i=0;i<129;i++){
        out=i; //用于转换int数成char字符
        if(result[i]!=0){
            cout << out << result[i]<<endl;
        }
    }
    return 0;
}