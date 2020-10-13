#include <stdio.h>

void main(){
    int isTri(int p, int q, int r);
    int triType(int p, int q, int r);
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(isTri(a,b,c)==1){
        switch(triType(a,b,c)){
            case 0 :
                printf("equilateral triangle.\n");
                break;
            case 1 :
                printf("isoceles triangle.\n");
                break;
            case 2 :
                printf("triangle.\n");
                break;
        }
    }else{
        printf("non-triangle.\n");
    }
}
//判断是否是三角形
int isTri(int p, int q, int r){
    int max(int p,int q,int r);
    if (2*max(p,q,r)<p+q+r){
        return 1;
    }else{
        return 0;
    }
}
//找出最大值
int max(int p,int q,int r){
    return (((p>q)?p:q)>r)?((p>q)?p:q):r;
}
//判断三角形类型
int triType(int p, int q, int r){
    if(p==q||q==r||p==r){
        if(p==q&&q==r){
            return 0; //等边三角形
        }else{
            return 1; //等腰三角形
        }
    }else{
        return 2; // 普通三角形
    }
}