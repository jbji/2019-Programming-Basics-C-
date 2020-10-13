#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define mpow(x) ((x)*(x))
typedef struct _pos{
    int x;
    int y;
}Pos;

int w,l;

void process(Pos*,char);
void getPos(Pos *);
int calc(Pos *,Pos *);

int main() {
    Pos *p1=(Pos *)malloc(sizeof(Pos)),*p2=(Pos *)malloc(sizeof(Pos));
    scanf("%d %d",&w,&l);
    getPos(p1);
    getPos(p2);
    char tmp;
    while((tmp=getchar())!='\n'){
        process(p1,tmp);
    }
    printf("%.4lf\n",sqrt(calc(p1,p2)));
    free(p1);free(p2);
    return 0;
}
void process(Pos* p,char tmp){
    p->y=(tmp=='L'||tmp=='R')?p->y:((tmp=='F')*(-p->y)+(tmp=='B')*(2*l-p->y));
    p->x=(tmp=='F'||tmp=='B')?p->x:((tmp=='L')*(-p->x)+(tmp=='R')*(2*w-p->x));
    return;
}
void getPos(Pos *p){
    scanf("%d %d",&p->x,&p->y);
    getchar();
    return;
}

int calc(Pos *p1,Pos *p2){
    return mpow(p1->x-p2->x)+mpow(p1->y-p2->y);
}