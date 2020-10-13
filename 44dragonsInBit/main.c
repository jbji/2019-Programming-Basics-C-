#include <stdio.h>
#include <stdlib.h>
#define N 100
int cmp(const void* _a,const void* _b){
    int* a =(int*) _a;
    int* b =(int*) _b;
    return *a-*b;
}
int main() {
    int dragon[N]={0};
    int warriors[N]={0};
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d",&dragon[i]);
        getchar();
    }
    for(int i=0;i<n;i++){
        scanf("%d",&warriors[i]);
        getchar();
    }
    qsort(dragon,m, sizeof(dragon[0]),cmp);
    qsort(warriors,n, sizeof(dragon[0]),cmp);

    int cost=0;
    int dragonLeft=m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(dragon[i]!=-1&&warriors[j]!=-1&&warriors[j]>=dragon[i]){
                cost+=warriors[j];
                dragon[i]=-1;
                dragonLeft--;
                warriors[j]=-1;
            }
        }
    }
    if(dragonLeft>0){
        printf("bit is doomed!\n");
    }else{
        printf("%d\n",cost);
    }

    return 0;
}