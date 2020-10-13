#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _member{
    char name[15];
    int balance;
    int remain;
    Node * out;
}Mber;

void getBalance(Mber* p);
void distribute(Mber *ps[],Mber *p);
void addToList(Mber *pin,int money);
int getResult(Mber *p);

int main() {
    int n;
    scanf("%d",&n);
    char temp_name[15];

    Mber *people[n];
    //getPeople
    for(int i=0;i<n;i++){
        people[i]=(Mber *)malloc(sizeof(Mber));
        people[i]->out=NULL;
        scanf("%s",&people[i]->name);
    }
    //get input
    for(int i=0;i<n;i++){
        scanf("%s",temp_name);
        int j=0;
        for(j=0;strcmp(temp_name,people[j]->name)!=0;j++);
        getBalance(people[j]);
        distribute(people,people[j]);
    }
    for(int i=0;i<n;i++){
        printf("%s %d\n",people[i]->name,getResult(people[i]));
    }
    return 0;
}

void getBalance(Mber* p){
    int i=0;
    scanf("%d",&i);
    p->balance=i;
    p->remain=0;
    return;
}
void distribute(Mber *ps[],Mber *p){
    int times=0;
    scanf("%d",&times);
    for(int i=0;i<times;i++){
        int toDistribute=(p->balance)/times;
        p->remain=p->balance%times;
        char temp_name[15];
        int j;
        scanf("%s",temp_name);
        for(j=0;strcmp(temp_name,ps[j]->name)!=0;j++);
        addToList(ps[j],toDistribute);
    }
    return;
}

void addToList(Mber *pin,int money){
    Node *p=(Node *)malloc(sizeof(Node));
    p->value=money;
    p->next=NULL;
    Node * last = pin->out;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=p;
    }else{
        pin->out=p;
    }
    return;
}

int getResult(Mber *p){
    int i=0;
    for(Node *q=p->out;q;q=q->next){
        i+=q->value;
    }
    i-=p->balance;
    i+=p->remain;
    return i;
}