#include <stdio.h>

int main() {
    int a,b;
    printf("-- 整数的带余除法 -- \n 请输入被除数（整数）\n",(-10)/3);
    scanf("%d",&a);
    printf(" 请输入除数（正整数）\n",(-10)/3);
    scanf("%d",&b);
    printf("a %% b = %d\n",a%b);
    if((a/b)*b!=a){
        if(a/b>0){
            printf("a / b = %d * %d + %d\n",b,(a/b),a-b*(a/b));
        }else{
            printf("a / b = %d * (%d) + %d\n",b,(a/b-1),a-b*(a/b-1));
        }
    }else{
        if(a/b>0){
            printf("a / b = %d * %d + 0\n",b,(a/b));
        }else{
            printf("a / b = %d * (%d) + 0\n",b,(a/b));
        }
    }
    return 0;
}