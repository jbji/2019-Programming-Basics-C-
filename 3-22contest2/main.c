#include <stdio.h>
#define len 1000
int main() {
    char str[len];
    int cnt=0;
    scanf("%s",str);
    for(int i=0;i<len;i++){
        if(str[i]=='U'&&i<=len-3){
            if(str[i+1]=='A'&&(str[i+2]=='A'||str[i+2]=='G')){
                cnt++;
            }
            if(str[i+1]=='G'&&(str[i+2]=='A')){
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}