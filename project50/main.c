#include <stdio.h>

int main() {
    int n,m;
    int sum(int,int);

    scanf("%d %d",&n,&m);
    printf("The sum from %d to %d is %d.\n",n,m,sum(n,m));

    return 0;
}

int sum(int inf,int sup){
    if(sup==inf){
        return inf;
    }else{
        return sup+sum(inf,sup-1);
    }
}