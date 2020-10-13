#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char *instr=(char *)malloc(256);
    char *pin=instr;// to record the initial place;
    char *rstr;
    scanf("%s",instr);
    rstr=instr+strlen(instr)-1;

    while(*instr++==*rstr--&&rstr-instr>0);
    if(*instr==*rstr){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    instr=pin;//restore the initial place;n
    free(instr);
    return 0;
}