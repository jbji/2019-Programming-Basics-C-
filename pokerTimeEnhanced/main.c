#define 定义 define

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

typedef struct player{
    Poker pokers[3];
    long long pVal;//playerVal
}Player;

void getPlayer(Player *);
//checktool
int pokerValid(Poker*);
int inputs_Valid(Poker*);
int inputs_notRep(Poker*,Poker*);
int input_Check(Player *,Player *);
int pokerCmp(Poker a,Poker b);
int cmp(const void*,const void*);
void pValGenerate(Player *);
int whoWin(const Player *,const Player *);
//math tool
long long pow(int base,int times);
int abs(int a);

int main() {
    Player pA,pB;
    int winnerFlag=0;

    getPlayer(&pA);
    fflush(stdin);
    getPlayer(&pB);

    if(!input_Check(&pA,&pB)){
        printf("Input Error!\n");
        return 0;
    }

    qsort(pA.pokers,l, sizeof(Poker),cmp);
    qsort(pB.pokers,l, sizeof(Poker),cmp);

    pValGenerate(&pA);
    pValGenerate(&pB);
    winnerFlag=whoWin(&pA,&pB);
    switch(winnerFlag){
        case 1:
            printf("Winner is A!\n");
            break;
        case -1:           printf("Winner is B!\n");
            break;
        case 0:
            printf("Winner is X!\n");
    }
    //here can be changed for multiple usage.
    printf("A: %c%s %c%s %c%s\n",pA.pokers[0].color,pA.pokers[0].num,pA.pokers[1].color,pA.pokers[1].num,pA.pokers[2].color,pA.pokers[2].num);
    printf("B: %c%s %c%s %c%s\n",pB.pokers[0].color,pB.pokers[0].num,pB.pokers[1].color,pB.pokers[1].num,pB.pokers[2].color,pB.pokers[2].num);

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
        p->cVal=o1+o2*10;
        result=1;
    }
    return result;
}
int inputs_Valid(Poker *in){
    int result=1,temp;
    //to check each poker's validity.
    for(int i=0;i<l;i++){
        temp=pokerValid(in+i);
        result=result>temp?temp:result;
    }
    return result;
}
int inputs_notRep(Poker *p1,Poker *p2){
    int rpcheck[200]={0},result=1;
    for(int i=0;i<l;i++){
        rpcheck[(p1+i)->cVal]++;
    }
    for(int i=0;i<l;i++){
        rpcheck[(p2+i)->cVal]++;
    }
    for(int i=0;i<200;i++){
        if(rpcheck[i]>1){
            result=0;
            break;
        }
    }
    return result;
}
int input_Check(Player *p1,Player *p2){
    return inputs_Valid(p1->pokers)&&inputs_Valid(p2->pokers)&&inputs_notRep(p1->pokers,p2->pokers);
}
int pokerCmp(Poker a,Poker b){
    return a.cVal-b.cVal;
}
int cmp(const void *a,const void *b){
    Poker aa = *(Poker *)a;
    Poker bb = *(Poker *)b;
    return -pokerCmp(aa,bb);
}

int whoWin(const Player * pa,const Player * pb){
    int result;
    if(pa->pVal>pb->pVal){
        result=1;
    }else if(pa->pVal<pb->pVal){
        result=-1;
    }else{
        result=0;
    }
    return result;
}

void getPlayer(Player *p){
    for(int i=0;i<l;i++){
        scanf("%c",&((p->pokers+i)->color));
        scanf("%s",(p->pokers+i)->num);
        getchar();
    }
}
void pValGenerate(Player * p){
    //pVal的结构：同花顺|炸弹|连牌|对子|逆序三张牌
    int flag=1;int sp=0;
    p->pVal=0;//务必将特征值置空
    //basic part
    for(int i=0;i<3;i++){
        p->pVal+=((p->pokers+i)->cVal)*pow(10,3*(2-i));//务必注意此时的数字顺序。
    }
    //对子
    flag=0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(strcmp((p->pokers+i)->num,(p->pokers+j)->num)==0){
                flag=1;
                break;
            }
        }
    }
    p->pVal+=flag*pow(10,10);
    //连牌
    flag=0;sp=0;
    int tmp1,tmp2;
    tmp1=abs((p->pokers->cVal)/10-((p->pokers+1)->cVal)/10);
    tmp2=abs(((p->pokers+1)->cVal)/10-((p->pokers+2)->cVal)/10);
    if(tmp1==tmp2&&tmp1==1){
        flag=1;sp=1;
    }
    p->pVal+=flag*pow(10,11);
    //炸弹
    flag=0;
    int tmp3;
    tmp1=((p->pokers+0)->cVal)/10;
    tmp2=((p->pokers+1)->cVal)/10;
    tmp3=((p->pokers+2)->cVal)/10;
    if(tmp1==tmp2&&tmp2==tmp3){
        flag=1;
    }
    p->pVal+=flag*pow(10,12);
    //同花顺
    flag=0;
    if(sp){
        tmp1=((p->pokers+0)->cVal)%10;
        tmp2=((p->pokers+1)->cVal)%10;
        tmp3=((p->pokers+2)->cVal)%10;
        if(tmp1==tmp2&&tmp2==tmp3){
            flag=1;
        }
    }
    p->pVal+=flag*pow(10,13);
}

long long pow(int base,int times){
    long long result=1;
    for(int i=times;i>0;i--){
        result*=base;
    }
    return result;
}
int abs(int a){
    return a<0?-a:a;
}