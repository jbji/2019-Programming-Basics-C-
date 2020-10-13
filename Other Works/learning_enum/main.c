#include <stdio.h>
enum season{
    spring,summer,autumn,winter
};

int main(){
    enum season sea;
    for(int i=0;i<4;i++){
        sea=(enum season)i;
        switch(sea){
            case spring:
                printf("sea:0\n");
                break;
            case summer:
                printf("sea:1\n");
                break;
            case autumn:
                printf("sea:2\n");
                break;
            case winter:
                printf("sea:3\n");
                break;
        }
    }
    enum season lake;
    int a=2;
    lake=(enum season)a;
    printf("lake:%d",lake);
    return 0;
}