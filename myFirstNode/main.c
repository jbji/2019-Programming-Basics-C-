#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node * next;
}Node;

typedef struct list{
    Node * node;
}List;

void adLst(List,int);
int srhLst(List,int); //index returned
void delLst(List,int);
void freeLst(List,int);

int main() {
    List list1;
    for(int i=0;i<10;i++){
        adLst(list1,i);
    }


    printf("Hello, World!\n");
    return 0;
}

void adLst(List l, int n){
    Node * head = l.node;
    if(l.node){
        while(l.node->next){
            l.node=l.node->next;
        }
    }
    l.node=(Node *)malloc(sizeof(Node));
    l.node->value=n;
    l.node->next=NULL;
    l.node=head;
    return;
}

