#include <stdio.h>

int main() {
    int tube(int);
    int in;
    int nums[5]={0};
    while(1){
        scanf("%d",&in);
        if(in==0){
            break;
        }
        for(int i=0;i<5;i++){
            nums[4-i]=in%10;
            in/=10;
        }
        for(int i=0;i<5;i++){
            printf("%X",tube(nums[i]));
            switch(i){
                case 4:
                    printf("\n");
                    break;
                default:
                    printf(" ");
            }
        }
    }


    return 0;
}
int tube(int num){
    switch(num){
        case 0:
            return 125;
        case 1:
            return 80;
        case 2:
            return 55;
        case 3:
            return 87;
        case 4:
            return 90;
        case 5:
            return 79;
        case 6:
            return 111;
        case 7:
            return 84;
        case 8:
            return 127;
        case 9:
            return 95;
        default:
            return 0;
    }
}