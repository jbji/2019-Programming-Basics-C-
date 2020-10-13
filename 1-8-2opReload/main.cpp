#include <iostream>
#include <cstring>

const int MAXN=5000;

struct BIGNUM{
    int len,s[MAXN];
    BIGNUM(){
        len=1;
        memset(s,0, sizeof(s));
    }
    BIGNUM operator = (const char * num){
        len=strlen(num);
        for(int i=0;i<len;++i){
            s[i]=num[len-i-1]-'0';
            return *this;
        }
    }
    BIGNUM operator = (const int num){
        char a[MAXN];
        sprintf(a,"%d",num);
        *this = a;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}