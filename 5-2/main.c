#include <stdio.h>

int main() {
    int sc[3][4], oidx[3]={0,1,2};
    int *psc=sc;//a pointer for input

    void output(const int *);
    float ave(const int *);
    void swap(int *,int*);

    for(int i=0;i<12;i++){
        scanf("%d",psc+i);
    }
    //sort the order
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(ave(sc[i])<ave(sc[j])){
                swap(&oidx[i],&oidx[j]);
            }
        }
    }
    //output
    for(int i=0;i<3;i++){
        output(sc[oidx[i]]);
    }
    return 0;
}

void output(const int *in){
    for(int i=0;i<4;i++){
        printf("%d",in[i]);
        if(i!=3) printf(","); else printf("\n");
    }
}




void swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
    return;
}