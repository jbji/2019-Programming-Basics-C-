#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
} Node;

typedef struct _list{
    Node * head;
} List;

void addList(List*,int);
void printList(List *in);
void freeList(List * list);

int main() {
    List * list=(List *)malloc(sizeof(list));
    list->head=NULL;

    for(int num=0;num<100;num++){
        addList(list,num);
    }

    printList(list);
    freeList(list);
    return 0;
}

void addList(List * list, int num){
    //add to linked-list
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=num;
    p->next=NULL;
    //find the last
    Node *last = list->head;
    if(last){
        while(last->next){
            last=last->next;
        }
        //attach
        last->next=p;
    }else{
        //attach
        list->head=p;
    }
    return;
}

void printList(List *in){
    for(Node *p=in->head;p;p=p->next){
        printf("%d ",p->value);
    }
    printf("\n");
    return;
}

void delLst(List * in,int value){
    for(Node *q=NULL,*p=in->head ; p ; q=p,p=p->next){
        if(p->value==value){
            if(q){
                q->next=p->next;
            }else{
                in->head=p->next;
            }
            free(p);
            break;
        }
    }
    return;
}

void freeList(List * list){
    for(Node * p=list->head,*q=NULL;p;p=q){
        q=p->next;
        free(p);
    }
    free(list);
    return;
}