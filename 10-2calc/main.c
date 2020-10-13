#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum type{
    NUM,ADD,SUB,MUL,DIV
}Type;

typedef struct node{
    Type type;
    char value;
    int num_value;
    struct node * before;
    struct node * next;
}Node;

typedef struct list{
    Node *head;
    Node *tail;
}List;

void list_initailize(List **);
void add_char(List *,char);
void add_var(List *,int);
Type type_tranform(char);
void get_input(List *);
void get_output(List *);

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

void add_char(List * h,char var){
    Node *p = (Node *)malloc(sizeof(Node));
    p->value=var;
    p->num_value=0;
    p->type=type_tranform(var);
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
void add_var(List * h,int var){
    Node *p = (Node *)malloc(sizeof(Node));
    p->num_value=var;
    p->value='\0';
    p->type=NUM;
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
void get_input(List * l){
    char tmp;
    int num=0;
    while((tmp=getchar())!='\n'){
        if(isdigit(tmp)){
            num*=10;
            num+=tmp-'0';
        }else{
            add_var(l,num);
            num=0;
            add_char(l,tmp);
        }
    }
    add_var(l,num);
    return;
}
void get_output(List *l){
    int times=-1;
    while(times!=0){
        times=0;
        Node *p=l->head;
        for(;p;p=p->next){
            if(p->type!=NUM){
                switch (p->type){
                    case MUL:
                        //改变p的属性
                        p->num_value=(p->before->num_value)*(p->next->num_value);
                        p->type=NUM;
                        //解决前后连接关系问题
                        if(p->next->next)p->next->next->before=p;
                        if(p->before->before) p->before->before->next=p;
                        p->next=p->next->next;
                        //解决第一个元素的连接问题
                        if(p->before==l->head){
                            l->head=p;
                        }
                        p->before=p->before->before;
                        times++;
                        break;
                    case DIV:
                        p->num_value=(p->before->num_value)/(p->next->num_value);
                        p->type=NUM;
                        if(p->next->next)p->next->next->before=p;
                        if(p->before->before) p->before->before->next=p;
                        p->next=p->next->next;
                        if(p->before==l->head){
                            l->head=p;
                        }
                        p->before=p->before->before;
                        times++;
                        break;
                }
            }
        }
    }
    times=-1;
    while(times!=0){
        times=0;
        Node *p=l->head;
        for(;p;p=p->next){
            if(p->type!=NUM){
                switch (p->type){
                    case ADD:
                        p->num_value=(p->before->num_value)+(p->next->num_value);
                        p->type=NUM;
                        if(p->next->next)p->next->next->before=p;
                        if(p->before->before) p->before->before->next=p;
                        p->next=p->next->next;
                        if(p->before==l->head){
                            l->head=p;
                        }
                        p->before=p->before->before;
                        times++;
                        break;
                    case SUB:
                        p->num_value=(p->before->num_value)-(p->next->num_value);
                        p->type=NUM;
                        if(p->next->next)p->next->next->before=p;
                        if(p->before->before) p->before->before->next=p;
                        p->next=p->next->next;
                        if(p->before==l->head){
                            l->head=p;
                        }
                        p->before=p->before->before;
                        times++;
                        break;
                }
            }
        }
    }
    printf("%d",l->head->num_value);

}
Type type_tranform(char c){
    Type result=NUM;
    switch(c){
        case '+':
            result=ADD;
            break;
        case '-':
            result=SUB;
            break;
        case '*':
            result=MUL;
            break;
        case '/':
            result=DIV;
            break;
    }
    return result;
}
