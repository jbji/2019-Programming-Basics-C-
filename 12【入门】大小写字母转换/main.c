#include <stdio.h>
void main(){
    char b=getchar();
    if(b>='A'&&b<='Z') b+=32;
    else if(b>='a'&&b<='z') b-=32;
    printf("%c\n",b);}