#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    char x = 0b10100111;
    char s[10];
    itoa((x+2)^(~3), s, 2);
    printf("%s\n",s);
    printf("Hello, World!\n");
    return 0;
}