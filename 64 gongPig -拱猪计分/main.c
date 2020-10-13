#include <stdio.h>
#include <stdlib.h>

int score_dict[]={-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40};
typedef enum Game_Type{
    ALL_RED,NORMAL
}Game_Type;

typedef struct _node{
    char color;
    int number;
    struct _node *next;
}Node;

typedef struct _player{
    Node * pokers;
    _Bool hasS;
    _Bool hasD;
    int Poker_Num;
    int H_Num;
    int score;
}Player;

typedef  struct _round{
    Player players[4];
    Game_Type type;
}Round;

int getInput(Round *);
void judge(Round *);

int main() {
    int inValid=1;
    while(inValid){
        Round * a= (Round*)malloc(sizeof(Round));
        inValid=getInput(a);
        if(inValid){
            judge(a);
        }
    }
    return 0;
}

int getInput(Round *in){
    int tmp;
    char color;
    int number;
    for(int i=0;i<4;i++){
        (in->players+i)->pokers=NULL;
        scanf("%d",&tmp);// num of pokers
//        getchar();
        (in->players+i)->Poker_Num=tmp;
        (in->players+i)->H_Num=0;
        (in->players+i)->score=0;
        (in->players+i)->hasD=0;
        (in->players+i)->hasS=0;
        //get the input for one player
        for(int j=0;j<tmp;j++){
            //store input
            Node * tmpPoker=(Node *)malloc(sizeof(Node));
            scanf(" %c %d",&color,&number);
//            getchar();
            tmpPoker->color=color;
            tmpPoker->number=number;
            tmpPoker->next=NULL;
            if(tmpPoker->color=='H'){
                (in->players+i)->H_Num++;
            }else if(tmpPoker->color=='S'){
                (in->players+i)->hasS=1;
            }else if(tmpPoker->color=='D'){
                (in->players+i)->hasD=1;
            }
            //find last
            Node *last=(in->players+i)->pokers;
            if(last){
                while(last->next){
                    last=last->next;
                }
                //attach
                last->next=tmpPoker;
            }else{
                //attach
                (in->players+i)->pokers=tmpPoker;
            }
        }
    }
    tmp=0;
    int roundType=0;
    for(int i=0;i<4;i++){
        tmp+=(in->players+i)->Poker_Num;
        roundType+=(in->players+i)->H_Num==13?1:0;
    }
    if(roundType==1){
        in->type=ALL_RED;
    }else{
        in->type=NORMAL;
    }
    return tmp==0?0:1;
}

void judge(Round *in){
    if(in->type==NORMAL){
        for(int i=0;i<4;i++){
            Player * tmpPla=(in->players+i);
            for(Node * p=tmpPla->pokers;p;p=p->next){
                if(p->color=='C'&&p->number==10&&(in->players+i)->Poker_Num==1){
                    tmpPla->score+=50;
                    break;
                }
                if(p->color=='H'){
                    tmpPla->score+=score_dict[p->number-1];
                }else if(p->color=='S'&&p->number==12){
                    tmpPla->score+= -100;
                }else if(p->color=='D'&&p->number==11){
                    tmpPla->score+=  100;
                }
            }
            for(Node * p=(in->players+i)->pokers;p;p=p->next){
                if(p->color=='C'&&p->number==10&&(in->players+i)->Poker_Num!=1){
                    tmpPla->score*=2;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++){
            if(in->players[i].score!=0){
                printf("%+d",in->players[i].score);
            }else {
                printf("0");
            }
            if(i!=3){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }else{// ALL_RED
        for(int i=0;i<4;i++){
            Player * tmpPla=(in->players+i);
            int isadded=0;
            for(Node * p=tmpPla->pokers;p;p=p->next){
                if(p->color=='C'&&p->number==10&&(in->players+i)->Poker_Num==1){
                    tmpPla->score+=50;
                    break;
                }
                if(p->color=='H'){
                    if(isadded==0){
                        if(tmpPla->hasS&&tmpPla->hasD){
                            tmpPla->score+=500;
                        }else{
                            tmpPla->score+=200;
                        }
                        isadded=1;
                    }
                }else if(p->color=='S'&&p->number==12){
                    tmpPla->score+= -100;
                }else if(p->color=='D'&&p->number==11){
                    tmpPla->score+=  100;
                }
            }
            for(Node * p=(in->players+i)->pokers;p;p=p->next){
                if(p->color=='C'&&p->number==10&&(in->players+i)->Poker_Num!=1){
                    tmpPla->score*=2;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++){
            if(in->players[i].score!=0){
                printf("%+d",in->players[i].score);
            }else {
                printf("0");
            }
            if(i!=3){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
}