#include <stdio.h>
#include <string.h>
#include <ctype.h>

int l=0;

int main() {
    char input[3000][100];
    char in;
    void wordProcess(char[]);

    for(int index=0;(in=getchar())!=EOF;index++){
        if(isalpha(in)){//store if it is an alpha
            input[l][index]=in;
        }else{//if not an alpha;
            input[l][index]='\0';
            wordProcess(input[l]);
            index=-1;
            printf("%c",in);
        }
    }
}

void wordProcess(char in[]){
    static char temp[3000][100];
    int isAppeared=0;
    for(int i=0;i<l;i++){
        if(strcmp(temp[i],in)==0){
            isAppeared=1;
            printf("%d",i+1);
            break;
        }
    }
    //compare with the list
    //if not appeared, output the input and then store it into the list
    if(isAppeared==0){
        printf("%s",in);
        if(in[0]!='\0'){
            strcpy(temp[l],in);
            l++;// the num of the word incrase
        }
    }
    return;
}