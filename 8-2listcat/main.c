#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
    char value;
    struct node * next;
}Node;

typedef struct list{
    Node *head;
}List;

void add_var(List *,char);
void get_input(List *);
void list_combine(const List*,const List*,List*);
void get_output(const List*);

int main() {
    List * l1=(List *)malloc(sizeof(List));
    List * l2=(List *)malloc(sizeof(List));
    List * l3=(List *)malloc(sizeof(List));
    l1->head=NULL;
    l2->head=NULL;
    l3->head=NULL;
    get_input(l1);
    get_input(l2);
    list_combine(l1,l2,l3);
    get_output(l3);
    return 0;
}

void add_var(List * h,char var){
    Node *p = (Node *)malloc(sizeof(Node));
    p->value=var;
    p->next=NULL;
    Node *last=h->head;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=p;
    }else{
        h->head=p;
    }
    return;
}
void get_input(List * l1){
    char temp;
    while((temp=getchar())!='\n'){
        if(isalpha(temp)){
            add_var(l1,temp);
        }
    }
    return;
}

void list_combine(const List*l1,const List*l2,List*l3){
    Node *p1=l1->head;
    Node *p2=l2->head;
    while(p1||p2){
        if(p1&&p2){
            if(p1->value<p2->value){
                add_var(l3,p1->value);
                p1=p1->next;
            }else if(p1->value==p2->value){
                add_var(l3,p1->value);
                p1=p1->next;
                p2=p2->next;
            }else{
                add_var(l3,p2->value);
                p2=p2->next;
            }
        }else if(p1){
            add_var(l3,p1->value);
            p1=p1->next;
        }else if(p2){
            add_var(l3,p2->value);
            p2=p2->next;
        }
    }
    return;
}

void get_output(const List*l){
    Node *p=l->head;
    for(;p;p=p->next){
        if(p->next){
            printf("%c ",p->value);
        }else{
            printf("%c",p->value);
        }

    }
    printf("\n");
    return;
}