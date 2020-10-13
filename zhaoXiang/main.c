#include <stdio.h>
#include <string.h>

int main(){
    char input[10000]={'\0'};
    int insert[10000]={0};
    scanf("%s",input);
    char temp;
    int counter=1;
    temp=input[0];
    for(int i=1;i<=strlen(input);i++){
        if(input[i]==temp){
            counter++;
            temp=input[i];
            continue;
        }else if(counter!=1){
            insert[i-1]=counter;
        }
        temp=input[i];
        counter=1;
    }
    for(int i=0;i<strlen(input);i++){
        if(insert[i]!=0){
            printf("%d",insert[i]);
        }else{
            printf("%c",input[i]);
        }
    }
    printf("\n");
    return 0;
}