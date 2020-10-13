/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"

struct node
{   int data;
    struct node * next;
} ;

typedef struct node NODE;
typedef struct node * PNODE;
void outlist( PNODE );
void sortlist( PNODE h, int num );

int main ( )
{   int num=1;
    PNODE head;

    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;

    while ( num!=0 )
    {   scanf("%d", &num);
        if ( num!=0 )
            sortlist( head, num);
    }
    outlist( head );
    return 0;
}

void outlist( PNODE head )
{   PNODE p;
    p = head->next;
    while ( p != NULL )
    {   printf("%d\n", p->data);
        p = p->next;
    }
}

/* This is an example for list. Please programme your code like it. 
sortlist( PNODE h, int num ) 
{   PNODE p; 
    p = (PNODE)malloc( sizeof(NODE) ); 
    p->data = num; 
    p->next = h->next; 
    h->next = p; 
} 
*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void sortlist( PNODE h, int num ){
    PNODE p = (PNODE)malloc( sizeof(NODE) );
    p->data = num;
    p->next=NULL;
    PNODE tmp;
    for(tmp=h;;){
        if(tmp->next){
            if(tmp->next->data<=p->data){
                tmp=tmp->next;
            }else{
                break;
            }
        }else{
            break;
        }

    }
    if((p->data) != (tmp->data)){
        p->next = tmp->next;
        tmp->next = p;
    }
}