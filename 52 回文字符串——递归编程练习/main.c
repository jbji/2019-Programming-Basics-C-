#include <stdio.h>

int main() {
    char *inf,*sup;
    char input[100]={'\0'};
    int check(char*,char*);

    gets(input);
    inf=input;
    for(sup=inf;*sup!='\0';sup++);
    sup--;

    printf("%s\n",check(inf,sup)==1?"Yes":"No");

    return 0;
}

int check(char *inf,char *sup){
    if(inf>=sup){
        return 1;
    }else if(*inf==*sup){
        return check(++inf,--sup);
    }
    return 0;
}