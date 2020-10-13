#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
    int value;
    struct _node * next;
    struct _node * before;
}Node;

typedef struct _list{
    Node * head;
    Node * last;
}List;

void add(List *,int);

int main() {
    List * list=(List *)malloc(sizeof(List));
    list->head=NULL;
    list->last=NULL;
    //add to the list
    int temp;
    while(temp!=-1){
        scanf("%d",&temp);
        if(temp!=-1){
            add(list,temp);
        }
    }
    //output
    Node *last=list->last;
    while(last){
        printf("%d ",last->value);
        last=last->before;
    }
    return 0;
}

void add(List * l,int data){
    Node * p = (Node *)malloc(sizeof(Node));
    p->value=data;
    p->next=NULL;
    p->before=NULL;
    if(l->head){
        l->last->next=p;
        p->before=l->last;
        l->last=l->last->next;
    }else{
        l->head=p;
        l->last=p;
    }
    return;
}