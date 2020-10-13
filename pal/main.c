#include <stdio.h>

int numGet(int n){
    if(n>3){
        return numGet(n-1)+numGet(n-2)+numGet(n-3);
    }else {
        switch (n){
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                return 4;
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("There is %i way of climbing the stairs!\n",numGet(n));
    }else if(n>1){
        printf("There are %i ways of climbing the stairs!\n",numGet(n));
    }else{
        printf("wrong input!\n");
    }
    return 0;
}