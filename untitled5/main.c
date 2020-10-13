#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node* next;
}Node;

typedef  struct _list{
    Node * head;
}List;

void add(List *list,int input);

int main() {
    List * l;
    l->head=NULL;
    for(int i=0;i<15;i++){
        add(l,i);
    }
    for(Node *p=l->head;p;p=p->next){
        printf("%d ",p->value);
    }
    printf("Hello, World!\n");
    return 0;
}
void add(List * list,int input){
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->value=input;
    tmp->next=NULL;

    Node * last= list->head;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=tmp;
    }else{
        list->head=tmp;
    }
}