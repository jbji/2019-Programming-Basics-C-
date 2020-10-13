#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

NODE * find( NODE * , int * );
void outputring( NODE * );
void change( int , int , NODE * );

void outputring( NODE * pring )
{   NODE * p;
    p = pring;
    if ( p == NULL )
        printf("NULL");
    else
        do
        {   printf("%d", p->data);
            p = p->next;
        } while ( p != pring );
    printf("\n");
    return;

}

int main()
{   int n, m;
    NODE * head, * pring;

    scanf("%d%d", &n, &m);
    head = (NODE *)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;

    change( n, m, head );
    pring = find( head, &n );
    printf("ring=%d\n", n);
    outputring( pring );

    return 0;
}


NODE *head_mod;


void change( int a , int b , NODE *h ){
    int digit,mod,flag=0;
    NODE *p,*tmp1;
    NODE *q,*tmp2;
    head_mod=(NODE*)malloc(sizeof(NODE));
    head_mod->data=-1;
    head_mod->next=NULL;
    mod=a;
    while(mod!=0){
        digit=10*mod/b;
        mod=10*mod%b;
        for(tmp1=h,tmp2=head_mod ;tmp1->next; tmp2=tmp2->next,tmp1=tmp1->next){
            if(tmp2->data==mod)   flag=1;
        }
        if(tmp2->data==mod)   flag=1;

        p=(NODE*)malloc(sizeof(NODE));
        p->data=digit;
        p->next=tmp1->next;
        tmp1->next=p;

        q=(NODE*)malloc(sizeof(NODE));
        q->data=mod;
        q->next=tmp2->next;
        tmp2->next=q;

        if(flag)    break;
    }
}


NODE * find( NODE *h , int *n ){
    NODE *p,*e1;
    NODE *q,*e2;
    int k1=0,k2=0;
    e1=h;e2=head_mod;
    while(e1->next!=NULL){
        e1=e1->next;
        e2=e2->next;
        k1++;
    }
    if(e2->data==0){
        *n=0;
        return e1->next;
    }else{
        p=h;q=head_mod;
        while(q->data!=e2->data){
            p=p->next;q=q->next;k2++;
        }
        *n=k1-k2;
        //p->next stands for the initial digit of the loop unit
        //e1 stands for the tail of the loop unit
        e1->next=p->next;
        //return e1 if loop from the beginning ,
        //          that's because you've skipped the initial using p->next, using e1 as initial instead.
        //return e1->next if not so,
        //          that's because e1 now is the genuine tail of the digits, and you get the initial by using its next.
        // Therefore, check needed to see if <something>.
        if(p==h->next){
            return e1;
        }else{
            return e1->next;
        }

    }
}