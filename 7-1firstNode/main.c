#include <stdio.h>

void encode(char *p);

int main() {
    char str[100];
    scanf("%s",str);
    for(int i=0;*(str+i)!='\0';i++){
        encode(str+i);
    }
    printf("%s\n",str);
    return 0;
}

void encode(char *p){
    switch(*p){
        case 'a':
            *p='d';break;
        case 'b':
            *p='w';break;
        case 'c':
            *p='k';break;
        case 'd':
            *p=';';break;
        case 'e':
            *p='i';break;
        case 'i':
            *p='a';break;
        case 'k':
            *p='b';break;
        case ';':
            *p='c';break;
        case 'w':
            *p='e';break;
    }
    return;
}