#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int risk;
    int pduct;
    long long cVal;
}Plant;

int cmpfunc(const void *a,const void *b){
    Plant aa = *(Plant *)a;
    Plant bb = *(Plant *)b;
    return bb.cVal-aa.cVal>0?1:-1;
}
int main() {
    int alls,picks;
    long long risks=0,pducts=0;
    scanf("%d %d",&alls,&picks);
    Plant ps[alls];
    for(int i=0;i<alls;i++){
        scanf("%d",&(ps[i].risk));
        ps[i].cVal=0;
    }
    for(int i=0;i<alls;i++){
        scanf("%d",&(ps[i].pduct));
        ps[i].cVal=((long long)ps[i].pduct)*10000000000LL-(long long)ps[i].risk;
    }
    qsort(ps,alls,sizeof(Plant),cmpfunc);
    for(int i=0;i<picks;i++){
        risks+=ps[i].risk;
        pducts+=ps[i].pduct;
    }
    printf("%d %d\n",risks,pducts);
    return 0;
}