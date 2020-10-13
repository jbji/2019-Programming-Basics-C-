#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 0
const int MIN=0;

int *getTenRandNum();
int op2(int *num1,int num2);
int main() {
    int *ip;
    int *p2=NULL;
    const int MAX=3;

    int  var[] = {10, 100, 200};
    int  i, *ptr;
    int *ptr1[3];
    int **ptr2[3];

    ip=getTenRandNum();

    for(int i=0;i<3;i++){
        ptr1[i]=&var[i];
    }
    for(int i=0;i<3;i++){
        ptr2[i]=&ptr1[i];
    }
    ptr=&var;
    for ( i = 0; i < MAX; i++)
    {

        printf("存储地址：var[%d] = %x\n", i, ptr2[i] );
        printf("存储值：var[%d] = %d,%d\n", i, *ptr2[i] ,**ptr2[i] );

        printf("//存储地址：var[%d] = %x\n", i, ptr );
        printf("//存储值：var[%d] = %d\n", i, *ptr );
        ptr++;
    }

    printf("%d",NUMBER);
    return 0;
}
int *getTenRandNum(){
    static int r[10];
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++){
        r[i]=rand();
    }
    return r;
}