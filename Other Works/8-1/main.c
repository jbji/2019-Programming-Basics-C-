#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
    char value;
    struct node * next;
}Node;

int main() {
    char values[7]={'a','b','c','d','c','b','a'};
    char in;
    scanf("%c",&in);

    Node * head;
    head=NULL;

    for(int i=0;i<7;i++){
        Node *p = (Node *)malloc(sizeof(Node));
        p->value=values[i];
        p->next=NULL;
        Node *last=head;
        if(last){
            while(last->next){
                last=last->next;
            }
            last->next=p;
        }else{
            head=p;
        }
    }
    Node *p=head;
    if(isalpha(in)){
        int index=-1;
        for(int i=0;p->next;p=p->next,i++){
            if(p->value==in){
                index=i;
            }
        }
        if(index!=-1){
            printf("%d\n",index);
        }else{
            printf("N\n");
        }
    }else{
        for(int i=in-'0';i>0;i--){
            if(p){
                p=p->next;
            }
        }
        if(p){
            printf("%c\n",p->value);
        }else{
            printf("N\n");
        }

    }

    return 0;
}