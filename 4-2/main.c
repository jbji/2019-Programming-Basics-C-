#include <stdio.h>
#include <stdlib.h>
int main() {
//    void swap(int*,int*);
    int *a=(int*)malloc(10);
    int *inita=a;

    for(int i=0;i<10;i++){
        scanf("%d",a+i);
    }

    int fnm;
    scanf("%d",&fnm);

    for(int i=0;i<10;i++){
        printf("%d\n",*(a+i));
    }

    while((*a++)!=(fnm)&&(a-inita<=10)){
        printf("%d %d\n",*a,fnm);
    }
    if((*(--a))!=(fnm)){
        printf("No\n");
    }else{
        printf("%d",*a);
    }

    return 0;
}


//    for(int *pa=a;pa<=&a[10];pa++){
//        for(int *pb=pa+1;pb<=&a[10];pb++){
//            if(*pa>*pb){
//                swap(pa,pb);
//            }
//        }
//    }
//    for(int i=0;i<10;i++){
//        printf("%d",a[i]);
//        if(i!=9){
//            printf(",");
//        }else{
//            printf("\n");
//        }
//    }
void swap(int*a, int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
    return;
}