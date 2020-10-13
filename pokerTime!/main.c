#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 3

char colors[]={'H','S','D','C'};// declining order of color.
char nums[][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

//the struct we use.
typedef struct{
    char color;
    char num[3];
    int cVal;// charateristic value
}Poker;

void getPlayer(Poker*);
void cValGenerate(Poker*);

//prepare for validity check.
int pokerValidity(Poker);
int pokerEquals(Poker a,Poker b);
int pArrayValidity(Poker[]);

//prepare for qsort and winning check
int pokerCompare(Poker a,Poker b);
int cmp(const void*,const void*);

//prepare for the winner check.
int whoWin(Poker a[],Poker b[]);

/*------------------And the Main Function-----------------------*/
int main() {
    //define our player
    Poker playerA[l],playerB[l];
    int winnerFlag=0;

    //do input
    getPlayer(&playerA);
    getPlayer(&playerB);

    //see if the input's valid.
    if(!(pArrayValidity(playerA)&&pArrayValidity(playerB))){
        printf("Input Error!\n");
        return 0;
    }

    //sort our pokers
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

int pokerValidity(Poker in){
    int color=-1;
    int num=-1;
    for(int i=0;i<4;i++){
        if(in.color==colors[i]){
            color=i;
        }
    }
    for(int i=0;i<13;i++){
        if(strcmp(in.num,nums[i])==0){
            num=i;
        }
    }
    if(color!=-1&&num!=-1){
        return 1;
    }else{
        return 0;
    }
}

//return 1 if equal, return 0 if not.
int pokerEquals(Poker a,Poker b){
    if(a.color==b.color&&(strcmp(a.num,b.num)==0)){
        return 1;
    }else{
        return 0;
    }
}

//toCheckOneArray of Pokers' Validity. return 1 if valid.
// you need a method to check interArrayValidity,
int pArrayValidity(Poker in[3]){
    //to check each poker's validity.
    for(int i=0;i<l;i++){
        if(!pokerValidity(in[i])){
            return 0;
        }
    }
    //to compare each poker with another. //HERE YOU HAVE A FATAL ERROR!
    for(int fixed=0;fixed<l;fixed++){
        for(int floating=fixed+1;floating<l;floating++){
            if(pokerEquals(in[fixed],in[floating])){
                return 0;
            }
        }
    }
    return 1;
}

//return value bigger than zero if a>b, vice versa.
int pokerCompare(Poker a,Poker b){
    int aOrder=-1,bOrder=-1;
    for(int i=0;i<4;i++){
        if(a.color==colors[i]){
            aOrder=i;
        }
    }
    for(int i=0;i<4;i++){
        if(b.color==colors[i]){
            bOrder=i;
        }
    }
    if(aOrder==bOrder){
        for(int i=0;i<13;i++){
            if(strcmp(a.num,nums[i])==0){
                aOrder=i;
            }
        }
        for(int i=0;i<13;i++){
            if(strcmp(b.num,nums[i])==0){
                bOrder=i;
            }
        }
        return aOrder-bOrder;
    }else{
        return -(aOrder-bOrder);
    }

}
//the vice version
int cmp(const void *a,const void *b){
    Poker aa = *(Poker *)a;
    Poker bb = *(Poker *)b;
    return -pokerCompare(aa,bb);
}

//to check winner. return 1 if a wins, -1 b wins, 0 x wins.
int whoWin(Poker a[l],Poker b[l]){
    for(int i=0;i<l;i++){
        if(pokerCompare(a[i],b[i])>0){
            return 1;
        }else if(pokerCompare(a[i],b[i])<0) {
            return -1;
        }
    }
    return 0;
}

void getPlayer(Poker *player){
    for(int i=0;i<l;i++){
        scanf("%c",&player[i].color);
        scanf("%s",player[i].num);
        getchar();
    }
}

void cValGenerate(Poker* p){
    int o1=0,o2=0;
    for(int i=0;i<4;i++){
        if(p->color==colors[i]){
            o1=i;
            break;
        }
    }
    for(int i=0;i<14;i++){
        if(p->num==nums[i]){
            o2=i+2;//absolute num
            break;
        }
    }
    p->cVal=o1*100+o2;
}