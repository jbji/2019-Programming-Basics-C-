#include <stdio.h>

int main() {
    int a,b;
    int pa,pb,pc,pd;
    int counter;
    do{
        scanf("%i %i",&a,&b);
        counter=0;
        if(a>=1000&&a<=9999&&b>=1000&&b<=9999){
            for(int i=a;i<=b;i++){
                pa=i/1000;
                pb=(i%1000)/100;
                pc=(i%100)/10;
                pd=i%10;
                if(i%2==0){
                    if(pa!=pb&&pa!=pc&&pa!=pd&&pb!=pc&&pb!=pd&&pc!=pd){
                        printf("%i  ",i);
                        counter++;
                    }
                }
            }
            printf("\ncounter=%i\n",counter);
        }else if(a!=0&&b!=0){
            printf("Error\n");
        }
    }while(a!=0&&b!=0);
    return 0;
}