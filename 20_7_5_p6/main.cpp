#include <iostream>
#include <cstring>
#include <string>


using namespace std;

char CODEOFF1[27]="QJCVOHATMFYRKDWPIBUNGZSLEX";

int def1(int x)
{
    return CODEOFF1[x];
}
int def2(int x, int key)
{
    return x ^ key;
}
void decode(char *str,int len){
    int v1; // eax
    int i; // [rsp+14h] [rbp-4h]
    for ( i = len-1; i>=0; i-- )
    {
        if ( i )
            v1 = str[i - 1];
        else
            v1 = 0;
        str[i] = def2(str[i], v1);
        str[i] = def1(str[i]);
    }
}

int main() {
    int n;
    cin >> n;
    unsigned char key[n];
    for(int i=0;i<n;i++){
        scanf("%x",&key[i]);
    }
    char* p = new char[sizeof(key)];
    memcpy(p,key,sizeof(key));
    p[sizeof(key)] = 0;
    decode(p,n);
    cout << p <<endl;
    return 0;
}