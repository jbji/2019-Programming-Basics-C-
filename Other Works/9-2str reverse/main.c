#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
    char value;
    struct node * before;
    struct node * next;
}Node;

typedef struct list{
    Node *head;
    Node *tail;
}List;

void list_initailize(List **);
void add_var(List *,char);
void get_input(List *);
void get_output(List *l);


int main() {
    List * l1;
    list_initailize(&l1);
    get_input(l1);
    get_output(l1);
    return 0;
}
void list_initailize(List **l){
    List *l2=(List *)malloc(sizeof(List));
    l2->head=NULL;
    l2->tail=NULL;
    *l=l2;
    return;
}
void add_var(List * h,char var){
    Node *p = (Node *)malloc(sizeof(Node));
    p->value=var;
    p->next=NULL;
    p->before=NULL;
    if(h->tail){
        p->before=h->tail;
        h->tail->next=p;
        h->tail=h->tail->next;
    }else{
        h->head=p;
        h->tail=h->head;
    }
    return;
}
void get_input(List *l){
    char temp;
    while((temp=getchar())!='\n'){
        add_var(l,temp);
    }
    return;
}

void get_output(List *l){
    for(Node *p=l->tail;p;p=p->before){
        printf("%c",p->value);
    }
    printf("\n");
    return;
}

