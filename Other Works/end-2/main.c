#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node ;
int isValid(char *);
void addToList(Node **,int);
int main() {
    int a,b;
    char num[10];
    Node *head=NULL;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        sprintf(num,"%d",i);
        if(isValid(num)){
            addToList(&head,i);
        }
    }
    if(head){
        for(Node *p=head;p;p=p->next){
            printf("%d",p->value);
            printf("\n");
        }
    }else{
        printf("No output\n");
    }
    return 0;
}

int isValid(char *in){
    char *p=in;
    char *q;
    int cnt1=0,cnt2=0;
    while(*in){
        q=in;
        in++;
    }
    while(p<=q){
        cnt1+=*p++ -'0';
        cnt2+=*q-- -'0';
    }
    return cnt1==cnt2;
}

void addToList(Node **head,int in){
    Node *p=(Node *)malloc(sizeof(Node));
    p->value=in;
    p->next=NULL;
    Node *q=*head;
    if(q){
        while(q->next){
            q=q->next;
        }
        q->next=p;
    }else{
        *head=p;
    }
    return;
}