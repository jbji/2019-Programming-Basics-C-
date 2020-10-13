#include <stdlib.h>
#include <stdio.h>


void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}


int getNextRandomValue(void)
{
    return rand();
}

int main(void){
    int myarray[10];
    int (*p)(int,size_t,int)=populate_array;
    p(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}
