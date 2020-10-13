#include <stdio.h>

int main() {
    char filename[20];
    char store[5];
    int line;
    scanf("%s",filename);
    scanf("%d",&line);

    FILE* fp=fopen(filename,"r");
    if(fp){
        for(;line>0;line--){
            if(fgets(store,20,fp)!=NULL){
                continue;
            }else{
                printf("Line No Error.\n");
                return 0;
            }
        }
        for(int i=0;*(store+i)!='\n'&&*(store+i)!='\0';i++){
            printf("%c",*(store+i));
        }
        printf("\n");
        fclose(fp);
    }else{
        printf("File Name Error.\n");
    }
    return 0;
}