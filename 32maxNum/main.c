#include <stdio.h>

int main() {
    int input[50]={[0]=0},output[50]={[0]=0};
    int in;
    int index=0;
    int switchCounter=1;

    scanf("%i",&in);
    do{
        input[index]=in%10;
        in=in/10;
        index++;
    }while(in!=0);

    while(switchCounter!=0){
        switchCounter=0;
        for(int i=1;i<50;i++){
            if(input[i-1]<input[i]){
                input[i]=input[i]^input[i-1];
                input[i-1]=input[i]^input[i-1];
                input[i]=input[i]^input[i-1];
                switchCounter++;
            }
        }
    }
    index--;
    for(int i=0;index>=0;index--,i++){
        printf ("%d",input[i]);
    }
    printf("\n");
    return 0;
}