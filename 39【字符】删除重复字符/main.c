#include <stdio.h>
#include <string.h>
int main() {
    char input[200]={'\0'};
    int mark[128]={0};
    scanf("%s",input);
    for(int i=0;i<strlen(input);i++){
        mark[input[i]]++;
        if(mark[input[i]]==1){
            printf("%c",input[i]);
        }

    }
    printf("\n");

}