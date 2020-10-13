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
void get_output(List *l);


int main() {
    List * l1=(List *)malloc(sizeof(List));
    l1->head=NULL;
    get_input(l1);
    get_output(l1);
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
void get_input(List *l){
    char temp;
    while((temp=getchar())!='\n'){
        add_var(l,temp);
    }
    return;
}

void get_output(List *l){
    int flag=0;//to mark if value has been outputed;
    for(Node *p=l->head;p;p=p->next){
        if(p->value=='n'){
            List *ll=(List*)malloc(sizeof(List));
            ll->head=p->next;
            if(flag) printf("\n");
            get_output(ll);
            return;
        }else{
            printf("%c",p->value);
            flag=1;
        }
    }
//    printf("\n");
    return;
}