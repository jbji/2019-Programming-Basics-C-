#include <stdio.h>
#include <string.h>
int loca=0;// this marks the location of our word.
void wordProcess(char in[]){
    int isAppeared=0;
    static char cmpTemp[10000][50];
    for(int i=0;i<loca;i++){
        if(strcmp(cmpTemp[i],in)==0){
            printf("%d",i+1);//to put the num if appeared.
            isAppeared=1;
            break;
        }
    }
    //above are codes to match the word.
    if(isAppeared==0){//if not appeared
        printf("%s",in);//just put the word
        if(in[0]!='\0'){//anf if the word is not a empty one, then we can store it.
            strcpy(cmpTemp[loca],in);
            loca++;
        }
    }
    return;
}
int main(){
    int k=0;
    char input[10000][50],inChar;
    while((inChar=getchar())!=EOF){// As we all know, getchar() is a method which can get SPACE involved.
        //but you know, still i have no idea of this EOF.
        if((inChar>='a'&&inChar<='z')||(inChar>='A'&&inChar<='Z')){// to store valid word
            input[loca][k]=inChar;
            k++;
//        }else if(inChar=='\0'){// to ensure an empty line be entered
//            input[loca][k]='\0';
//            wordProcess(input[loca]);
//            k=0;
//            printf("\n");
        }else{//input ended, start process.
            input[loca][k]='\0';//store the word with no space
            wordProcess(input[loca]);//to process the word we've got
            k=0;//to empty the index
            printf("%c",inChar);// to put the space
        }
    }
}