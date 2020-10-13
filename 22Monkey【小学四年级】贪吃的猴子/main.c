#include <stdio.h>

int main() {
    int inNum,i=1,p=1;
    scanf("%i",&inNum);
    for(inNum--;inNum>0;inNum--){
        p=2*(p+inNum);
    }
    printf("The monkey got %i peach%s in first day.\n",p,(p==1?"":"es"));
    return 0;
}