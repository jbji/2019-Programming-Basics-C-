#include <stdio.h>
#include <string.h>

int main() {
    char *file[]={"Jack","Mary","Good","GoGo","Five"};
    char fname[20];
    int line;
    scanf("%s",fname);
    scanf("%d",&line);

    if(strcmp(fname,"data1.txt")==0){
        if(line<6&&line>0){
            printf("%s\n",file[line-1]);
        }else{
            printf("Line No Error.\n");
        }
    }else{
        printf("File Name Error.\n");
    }
    return 0;
}