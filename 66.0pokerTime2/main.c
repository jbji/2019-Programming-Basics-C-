#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define l 3
//You may find this code a little bit more ironic.
char as[]={'H','S','D','C'};
char bs[][3]={"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
typedef struct{
    char a;
    char b[3];
    int cValue;
}Po;
int fa(Po in){
    int a=-1,b=-1;
    for(int i=0;i<4;i++) if(in.a==as[i]) a=i;
    for(int i=0;i<13;i++) if(strcmp(in.b,bs[i])==0) b=i;
    if(a!=-1&&b!=-1)return 1;
    else return 0;
}
int fb(Po a,Po b){
    if(a.a==b.a&&(strcmp(a.b,b.b)==0)) return 1;
    else return 0;
}
int fc(Po in[3]){
    for(int i=0;i<l;i++) if(!fa(in[i])) return 0;
    for(int fi=0;fi<l;fi++)
        for(int fl=fi+1;fl<l;fl++)
            if(fb(in[fi],in[fl]))
                return 0;
    return 1;
}
int fd(Po a,Po b){
    int aO=-1,bO=-1;
    for(int i=0;i<4;i++) if(a.a==as[i]) aO=i;
    for(int i=0;i<4;i++) if(b.a==as[i]) bO=i;
    if(aO==bO){
        for(int i=0;i<13;i++) if(strcmp(a.b,bs[i])==0) aO=i;
        for(int i=0;i<13;i++) if(strcmp(b.b,bs[i])==0) bO=i;
        return aO-bO;
    }else{
        return -(aO-bO);
    }
}
int cmp(const void *a,const void *b){
    Po aa = *(Po *)a;
    Po bb = *(Po *)b;
    return -fd(aa,bb);
}
int fe(Po a[l],Po b[l]){
    for(int i=0;i<l;i++) if(fd(a[i],b[i])>0) return 1;
        else if(fd(a[i],b[i])<0) return -1;
    return 0;
}
void ff(Po pA[l]){
    for(int i=0;i<l;i++){
        scanf("%c",&pA[i].a);
        scanf("%s",pA[i].b);
        getchar();
    }
}
int main() {
    Po pA[l],pB[l];
    int wf=0;
    ff(pA);
    fflush(stdin);
    ff(pB);
    if(!(fc(pA)&&fc(pB))){
        printf("Input Error!\n");
        return 0;}
    qsort(pA,l, sizeof(Po),cmp);
    qsort(pB,l, sizeof(Po),cmp);
    wf=fe(pA,pB);
    switch(wf){
        case 1:
            printf("Winner is A!\n");
            break;
        case -1:
            printf("Winner is B!\n");
            break;
        case 0:
            printf("Winner is X!\n");
    }
    printf("A: %c%s %c%s %c%s\n",pA[0].a,pA[0].b,pA[1].a,pA[1].b,pA[2].a,pA[2].b);
    printf("B: %c%s %c%s %c%s\n",pB[0].a,pB[0].b,pB[1].a,pB[1].b,pB[2].a,pB[2].b);
    return 0;
}