#include <stdio.h>
#include <string.h>

int main() {
    int sum(const int*);

    char *names[4]={"wanglei","lihong","zhangli","liuming"};
    int sc[4][4]={
            {78,90,87,92},
            {88,91,89,78},
            {84,76,83,75},
            {88,90,71,83}
    };
    int s;

    for(int i=0;i<4;i++){
        if((int)sum(sc[i])%4==0){
            printf("%s,%d\n",names[i],sum(sc[i])/4);
        }else{
            printf("%s,%.2f\n",names[i],(float)sum(sc[i])/4);
        }
    }
    printf("AVERAGE:");
    for(int j=0;j<4;j++){
        s=0;
        for(int i=0;i<4;i++){
            s+=sc[i][j];
        }
        if(s%4==0) printf("%d",s/4); else printf("%.2f",(float)s/4);
        if(j!=3) printf(","); else printf("\n");
    }
    return 0;
}

int sum(const int *in){
    int o=0;
    for(int i=0;i<4;i++){
        o+=*(in+i);
    }
    return o;
}