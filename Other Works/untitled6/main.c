#include <stdio.h>
#include <stdlib.h>

int main(){
    char *str;
    int len;
    for(int i=0;i<5;i++){
        scanf("%d",&len);
        str=(char *)malloc(sizeof(char)*(len+1));
        scanf("%s",str);
        printf("%s",str);
    }
    free(str);
    return 0;
}