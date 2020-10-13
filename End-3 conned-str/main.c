#include <stdio.h>
#include <stdlib.h>

typedef struct _string{
    char data;
    struct _string * next;
}String;

typedef struct _strs{
    String *str;
    struct _strs *next;
}StrG;

//void strsInitialize(StrG *);
void append(String **,char);
void expand(StrG **,char);
void addToStrG(StrG **,char);
void getOutput(const StrG *);

int main() {
    StrG *output=NULL;
//    strsInitialize(output);
    char in;
    while((in=getchar())!='\n'){
        addToStrG(&output,in);
    }
    getOutput(output);
    return 0;
}

//void strsInitialize(StrG *in){
//    in->str=NULL;
//    in->next=NULL;
//    return;
//}
void append(String ** in,char data){
    String * p =(String *)malloc(sizeof(String));
    p->data=data;
    p->next=NULL;

    String *q=*in;
    if(q){
        while(q->next){
            q=q->next;
        }
        q->next=p;
    }else{
        *in=p;
    }
    return;
}

void addToStrG(StrG **in,char data){
    int isAppend=0;
    StrG *qG=*in;
    if(qG){
        while(qG->next){
            qG=qG->next;
        }
        String *q=qG->str;
        while(q->next){
            q=q->next;
        }
        if((q->data)+1==data){
            append(&q,data);
            isAppend=1;
        }
    }
    if(!isAppend){
        expand(in,data);
    }
    return;
}

void expand(StrG **in,char data){
    StrG * p= (StrG*)malloc(sizeof(StrG *));
    p->next=NULL;
    p->str=NULL;
    append(&(p->str),data);
    StrG *q=*in;
    if(q){
        while(q->next){
            q=q->next;
        }
        q->next=p;
    }else{
        *in=p;
    }
    return;
}


void getOutput(const StrG *in){
    StrG *qG=in;
    while(qG){
        String *q=qG->str;
        if(q->next){
            while(q){
                printf("%c",q->data);
                q=q->next;
            }
            printf("\n");
        }
        qG=qG->next;
    }
    return;
}