#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
} Node;

int main() {
    Node * head = NULL;

    int n,num;
    scanf("%d %d",&n,&num);
    //add numbers to the list
    for(int i=1;i<=n;i++){
        //create the node for the value
        Node *p=(Node *)malloc(sizeof(Node));
        p->value=i;
        p->next=NULL;
        Node * last = head;
        if(last){
            while(last->next){
                last=last->next;
            }
            last->next=p;
        }else{
            head=p;
        }
    }
    //print out
//    for(Node *p=head;p;p=p->next){
//        printf("%d\n",p->value);
//    }
    //close as a cycle
    Node * last = head;
    if(last){
        while(last->next){
            last=last->next;
        }
        last->next=head;
    }
    //eliminate the found child
    for(Node *p = head;p->next!=p;){
        Node *e,*q;
        q=p;
        e=q;


        //找到循环一圈的循环节点 这样做的目的是将e q p的顺序完全纠正 这时p指向第一个元素
        int len=1;
        Node* last=p;
        //为此，我们先找一圈的长度
        while(last->next!=p){
            len++;
//            printf("length=%d\n",len);
            last=last->next;
        }
        //再来跑一圈
        for(int i=0;i<len;i++){
            e=q;
            q=p;
            p=p->next;
        }



        //然后可以开始eliminate了
        for(int i=0;i<num;i++){
            e=q;
            q=p;
            p=p->next;
//            printf("e=%d,q=%d,p=%d\n",e->value,q->value,p->value);
        }
        e->next=p;
//        printf("Eliminated child is NO %d.\n",q->value);
        head=p;
    }
    printf("The left child is NO %d.\n",head->value);


    //connect the list as a cycle
    //count the number and eliminate;




//
//
//    for(int num=0;num<100;num++){
//        //add to linked-list
//        Node *p=(Node*)malloc(sizeof(Node));
//        p->value=num;
//        p->next=NULL;
//        //find the last
//        Node *last = head;
//        if(last){
//            while(last->next){
//                last=last->next;
//            }
//            //attach
//            last->next=p;
//        }else{
//            //attach
//            head=p;
//        }
//
//    }
    return 0;
}