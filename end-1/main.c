#include <stdio.h>
#include <stdlib.h>

char nextAlpha(char*);
char beforeAlpha(char*);
void drawLine(char*,int);
int main() {
    int line;
    char *chr=(char*)malloc(sizeof(char));
    scanf("%d,%c",&line,chr);
    beforeAlpha(chr);
    drawLine(chr,line);
    for(int j=line-2;j>0;j--){
        for(int i=j;i>0;i--){
            printf(" ");
        }
        printf("%c",nextAlpha(chr));
        printf("\n");
    }
    drawLine(chr,line);
    return 0;
}

void drawLine(char* in,int line){
    for(int i=0;i<line;i++){
        printf("%c",nextAlpha(in));
    }
    printf("\n");
}
char nextAlpha(char* in){
    if(*in<'z'&&*in>='a'){
        (*in)++;
    }else{
        *in='a';
    }
    return *in;
}
char beforeAlpha(char* in){
    if(*in<='z'&&*in>'a'){
        (*in)--;
    }else{
        *in='z';
    }
    return *in;
}