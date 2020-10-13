#include <stdio.h>
#include <stdlib.h>

int main() {
    char in1[50];
    scanf("%s",in1);
    printf("%s ( base %i ) = %i\n",in1,6,strtol(in1,NULL,6));
    return 0;
}