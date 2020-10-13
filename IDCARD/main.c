#include <stdio.h>
#include <string.h>

int main(){
    int times;
    scanf("%i",&times);

    char input[times][19];
    char output[times][19];

    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int sum=0;
    char checkTemp;

    for(int i=0;i<times;i++){
        scanf("%s",input[i]);
        if(input[i][18]=='\0'&&input[i][17]!='\0'){
            sum=0;
            for(int k=0;k<17;k++){
                sum+=weight[k]*(input[i][k]-'0');
            }
            switch(sum%11){
                case 0:
                    checkTemp= '1';
                    break;
                case 1:
                    checkTemp='0';
                    break;
                case 2:
                    checkTemp='X';
                    break;
                default:
                    checkTemp=12-sum%11+'0';
            }
            if(checkTemp==input[i][17]){
                strcpy(output[i],"Valid");
            }else{
                strcpy(output[i],"Invalid");
            }
        }else if(input[i][15]=='\0'&&input[i][14]!='\0'){
            for(int p=0;p<6;p++){
                output[i][p]=input[i][p];
            }
            for(int p=8;p<17;p++){
                output[i][p]=input[i][p-2];
            }
            output[i][6]='1';
            if(output[i][14]=='9'&&output[i][15]=='9'&&output[i][16]-'6'>=0){
                output[i][7]='8';
            }else{
                output[i][7]='9';
            }


            sum=0;
            for(int k=0;k<17;k++){
                sum+=weight[k]*(output[i][k]-'0');
            }
            switch(sum%11){
                case 0:
                    checkTemp= '1';
                    break;
                case 1:
                    checkTemp='0';
                    break;
                case 2:
                    checkTemp='X';
                    break;
                default:
                    checkTemp=12-(sum%11)+'0';
            }
            output[i][17]=checkTemp;

            output[i][18]='\0';
        }else{
            strcpy(output[i],"Invalid");
        }
        printf("%s\n",output[i]);
    }
//    for(int i=0;i<times;i++){
//        printf("%s\n",output[i]);
//    }
    return 0;
}