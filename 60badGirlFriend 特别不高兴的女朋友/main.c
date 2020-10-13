#include <stdio.h>
int main() {
    int tmp1,tmp2,tmpVal=-1,tmpIdx=0,lamda;//lamda is the charateristic num of the input
    for(int j=0;j<7;j++){
        scanf("%d %d",&tmp1,&tmp2);
        if(tmpVal<(lamda=tmp1+tmp2-10>=0?tmp1+tmp2-10:-1)){
            tmpVal=lamda;
            tmpIdx=j+1;
        }
    }
    printf("%d\n",tmpVal==-1?0:tmpIdx);
    return 0;
}