#include <stdio.h>

int main() {
    int current=0;
    int next=1;
    int time=0;
    while(next){
        scanf("%d",&next);
        if(next){
            if(next-current>0){
                time+=(next-current)*6+5;
            }else{
                time+=(current-next)*4+5;
            }
            current=next;
        }
    }
    printf("%d\n",time);
    return 0;
}