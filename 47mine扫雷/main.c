#include <stdio.h>
#define N 102
int gN,gM;
char gMap[N][N];

int main() {
    void voidSet();
    void generate();
    void process();

    for(int k=1;1;k++){
        scanf("%d %d",&gN,&gM);
        getchar();
        if(gN!=0&&gM!=0){
            voidSet();
            generate();
            if(k!=1){
                printf("\n");
            }
            printf("Field #%d:\n",k);
            process();
        }else{
            break;
        }
    }
    return 0;
}
void voidSet(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            gMap[i][j]='0';
        }
    }
}
void generate(){
    for(int i=1;i<=gN;i++){
        for(int j=1;j<=gM;j++){
            scanf("%c",&gMap[i][j]);
        }
        getchar();
    }
}

void process(){
    int count=0;
    for(int i=1;i<=gN;i++){
        for(int j=1;j<=gM;j++){
            if(gMap[i][j]!='*'){
                count=0;
                for(int p=i-1;p<=i+1;p++){
                    for(int q=j-1;q<=j+1;q++){
                        if(gMap[p][q]=='*'){
                            count++;
                        }
                    }
                }
                printf("%d",count);
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
}