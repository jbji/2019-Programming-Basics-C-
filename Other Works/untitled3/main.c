#include<stdio.h>

typedef struct poker
{
    int num;
    char color;
}Poker;

int getInput();
void output();
void reset();
void check();

Poker card[4][16]={{0,0}};

int pkr_num[4]={0},
result[4]={0},
dict_cmp[2][13]={-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40,};

int num_H=0,is_C=0,is_D=0,is_S=0;

int main(){
    while(getInput()){
        check();
        output();
        reset();
    }
    return 0;
}

int getInput(){
    int rlt=0;
    for(int i=0;i<4;i++){
        scanf("%d",&pkr_num[i]);
        rlt+=pkr_num[i];
        for(int j=0;j<pkr_num[i];j++){
            scanf(" %c %d",&card[i][j].color,&card[i][j].num);
        }
    }
    return rlt;
}

void output(){
    for(int i=0;i<4;i++){
        if(result[i]==0){
            printf("0",result[i]);
        }else{
            printf("%+d",result[i]);
        }
        if(i==3){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    return;
}

void reset(){
    for(int k=0;k<13;k++){
        dict_cmp[1][k]=0;
    }
    for(int i=0;i<4;i++){
        result[i]=0;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<16;j++){
            card[i][j].num=0;
            card[i][j].color=0;
        }
    }
    num_H=is_C=is_D=is_S=0;
    return;
}

void check(){
    for(int i=0;i<4;i++){
        if(pkr_num[i]==0){
            result[i]=0;
            continue;
        }else{
            for(int j=0;j<pkr_num[i];j++){ // take out cards
                if (card[i][j].color == 'H') {
                    num_H++;
                    dict_cmp[1][card[i][j].num-1] = 1;
                }
            }
            for(int j=0;j<pkr_num[i];j++){// take out cards
                if(card[i][j].color=='C'&&card[i][j].num==10){
                    is_C=1;
                }
                if(card[i][j].color=='D'&&card[i][j].num==11){
                    is_D=1;
                }
                if(card[i][j].color=='S'&&card[i][j].num==12){
                    is_S=1;
                }
            }
        }
        //calc score
        if(num_H==13){
            if(is_D==1&&is_S==1){
                result[i]=500;
            }else if(is_D==1){
                result[i]=300;
            }else if(is_S==1){
                result[i]=100;
            }else{
                result[i]=200;
            }
        }else{
            for(int k=0;k<13;k++){
                if(dict_cmp[1][k]==1) result[i] +=dict_cmp[0][k];
            }
            if(is_D==1){
                result[i] +=100;
            }
            if(is_S==1){
                result[i] +=-100;
            }
        }
        if(is_C==1){
            if(pkr_num[i]==1){
                result[i]=50;
            }else{
                result[i]=2*result[i];
            }
        }
        //reset dict_cmp
        for(int k=0;k<13;k++){
            dict_cmp[1][k]=0;
        }
        num_H=is_C=is_D=is_S=0;
    }
}