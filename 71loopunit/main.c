/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

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

/* Here is waiting for you. 
void change( int n, int m, NODE * head ) 
{  
} 
 
NODE * find( NODE * head, int * n ) 
{ 
} 
*/

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int isFound=0;
int addAndSearch(NODE **mods,int n){
    int result=-1;
    if(*mods){
        NODE * qlast=NULL;
        NODE * last = *mods;
        for(int i=1;last;i++,qlast=last,last=last->next){
            if(n==last->data){
                return i;
            }
        }
        NODE *p=(NODE * )malloc(sizeof(NODE));
        p->data=n;
        p->next=NULL;
        qlast->next=p;
        result=0;
    }else{
        NODE *p=(NODE * )malloc(sizeof(NODE));
        p->data=n;
        p->next=NULL;
        *mods=p;
        result=0;
    }
    return result;
}
void change( int n, int m, NODE * head){
    isFound=0;
    NODE *mods=NULL;
    NODE *tail=head;
    isFound=addAndSearch(&mods,n);
    while(!isFound&&n!=0){
        n*=10;
        //create node
        NODE *p=(NODE *)malloc(sizeof(NODE));
        p->data=n/m;
        p->next=NULL;
        //attach
        tail->next=p;
        tail=tail->next;
        n=n%m; // now n is the mod
        isFound=addAndSearch(&mods,n);
    }
    if(isFound){
        for(int i=isFound;i>0;i--){
            head=head->next;
        }
        tail->next=head;
    }
    return;
}
NODE * find(NODE * head, int * n){
    if(isFound){
        for(int i=isFound;i>0;i--){
            head=head->next;
        }
        NODE *thead=head;
        int i=1;
        while(thead->next!=head){
            thead=thead->next;
            i++;
        }
        *n=i;
        return head;
    }else{
        *n=0;
        return NULL;
    }
}