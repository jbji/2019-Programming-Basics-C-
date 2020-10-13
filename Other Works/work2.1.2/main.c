#include <stdio.h>
#define N 10

int input[N];

int main() {
    void scan();
    void sort(int[]);
    void print(int[]);

    scan();
    sort(input);
    print(input);

    return 0;
}
void scan(){
    for(int i=0;i<N-2;i++){
        scanf("%d%c",&input[i]);
    }
    for(int i=N-2;i<N;i++){
        scanf("%d",&input[i]);
    }
}
void sort(int in[N]){
    int temp;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(in[i]>in[j]){
                temp=in[i];
                in[i]=in[j];
                in[j]=temp;
            }
        }
    }
}

void print(int in[N]){
    for(int i=0;i<N-1;i++){
        printf("%d,",in[i]);
    }
    printf("%d\n",in[N-1]);
}