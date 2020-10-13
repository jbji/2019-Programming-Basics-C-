#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char *str=(char*)malloc(sizeof(char)*256),*cmp=(char*)malloc(sizeof(char));
    scanf("%[^\n]",str);
    scanf("%s",cmp);
    if(strstr(str,cmp)==NULL){
        printf("No\n");
    }else{
        printf("%s",cmp);
    }
    free(str);free(cmp);
    return 0;
}