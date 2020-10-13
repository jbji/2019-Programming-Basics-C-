#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 3

char colors[]={'C','D','S','H'};
char nums[][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

//the struct we use.
typedef struct poker{
    char color;
    char num[3];
    int cVal;// charateristic value
}Poker;

void getPlayer(Poker*);
//prepare for validity check.
int pokerValid(Poker *);
    int inputs_Valid(Poker[]);
    int inputs_notRep(Poker[]);
int input_Check(Poker[],Poker[]);
int pokerCmp(Poker a,Poker b);
int cmp(const void*,const void*);
int whoWin(Poker a[],Poker b[]);

int main() {
    Poker playerA[l],playerB[l];
    int winnerFlag=0;

    getPlayer(playerA);
    fflush(stdin);
    getPlayer(playerB);
    if(!input_Check(playerA,playerB)){
        printf("Input Error!\n");
        return 0;
    }

    qsort(playerA,l, sizeof(Poker),cmp);
    qsort(playerB,l, sizeof(Poker),cmp);
    winnerFlag=whoWin(playerA,playerB);
    switch(winnerFlag){
        case 1:
            printf("Winner is A!\n");
            break;
        case -1:
            printf("Winner is B!\n");
            break;
        case 0:
            printf("Winner is X!\n");
    }
    //here can be changed for multiple usage.
    printf("A: %c%s %c%s %c%s\n",playerA[0].color,playerA[0].num,playerA[1].color,playerA[1].num,playerA[2].color,playerA[2].num);
    printf("B: %c%s %c%s %c%s\n",playerB[0].color,playerB[0].num,playerB[1].color,playerB[1].num,playerB[2].color,playerB[2].num);

    return 0;
}
int pokerValid(Poker* p){
    int o1=-1,o2=-1,result=0;
    for(int i=0;i<4;i++){
        if(p->color==colors[i]){
            o1=i;
            break;
        }
    }
    for(int i=0;i<13;i++){
        if(strcmp(p->num,nums[i])==0){
            o2=i+2;//absolute num
            break;
        }
    }
    if(o1!=-1&&o2!=-1){
        p->cVal=o1*100+o2;
        result=1;
    }
    return result;
}
int inputs_Valid(Poker in[l]){
    int result=1,temp;
    //to check each poker's validity.
    for(int i=0;i<l;i++){
        temp=pokerValid(in+i);
        result=result>temp?temp:result;
    }
    return result;
}
int inputs_notRep(Poker i1[]){
    int rpcheck[500]={0},result=1;
    for(int i=0;i<l;i++){
        rpcheck[i1[i].cVal]++;
    }
    for(int i=0;i<500;i++){
        if(rpcheck[i]>1){
            result=0;
        }
    }
    return result;
}
int input_Check(Poker i1[],Poker i2[]){
    return inputs_Valid(i1)&&inputs_Valid(i2)&&(inputs_notRep(i1))&&(inputs_notRep(i2));
}
//return value bigger than zero if a>b, vice versa.
int pokerCmp(Poker a,Poker b){
    return a.cVal-b.cVal;
}
//the vice version
int cmp(const void *a,const void *b){
    Poker aa = *(Poker *)a;
    Poker bb = *(Poker *)b;
    return -pokerCmp(aa,bb);
}

//to check winner. return 1 if a wins, -1 b wins, 0 x wins.
int whoWin(Poker a[l],Poker b[l]){
    for(int i=0;i<l;i++){
        if(pokerCmp(a[i],b[i])>0){
            return 1;
        }else if(pokerCmp(a[i],b[i])<0) {
            return -1;
        }
    }
    return 0;
}

void getPlayer(Poker *player){
    for(int i=0;i<l;i++){
        scanf("%c",&((player+i)->color));
        scanf("%s",(player+i)->num);
        getchar();
    }
}
