#include <stdio.h>
#include <stdlib.h>
int max(char * in){
    int fixedMAX;
    for(int i=0;i<50;i++){
        fixedMAX=fixedMAX>in[i]?fixedMAX:in[i];
    }
    fixedMAX-=fixedMAX>64?55:48;
    return fixedMAX+1;
}
int main() {
    char in1[50]={0}, in2[50]={0};
    scanf("%s %s",in1,in2);
    for(int fixedBase = max(in1);fixedBase<=36;fixedBase++) {
        for (int floatBase = max(in2); floatBase <= 36; floatBase++) {
            if (strtol(in1, NULL, fixedBase) == strtol(in2, NULL, floatBase)) {
                printf("%s (base %i) = %s (base %i)\n", in1, fixedBase , in2, floatBase);
                return 0;
            }
        }
    }
    printf("%s is not equal to %s in any base 2..36\n",in1,in2);
    return 1;
}