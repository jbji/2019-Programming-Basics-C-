#include<stdio.h>
int main()
{
    int a,b,c,d,t;
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    if(a>c)
    {
        t=a;
        a=c;
        c=t;
    }
    if(a>d)
    {
        t=a;
        a=d;
        d=t;
    }
    if(b>c)
    {
        t=b;
        b=c;
        c=t;
    }
    if(b>d)
    {
        t=b;
        b=d;
        d=t;
    }
    if(c>d)
    {
        t=c;
        c=d;
        d=t;
    }
    printf("%d,%d,%d,%d\n",a,b,c,d);
    return 0;
}

//#include <stdio.h>
//
//void swap(int*,int*);
//
//int main(){
//	int num[4];
//	for(int i=0;i<4;i++) scanf("%d",num+i);
//	for(int i=0;i<4;i++){
//		for(int j=i;j<4;j++){
//			if(num[i]>num[j]) swap(num+i,num+j);
//		}
//	}
//	printf("%d %d %d %d\n",num[0],num[1],num[2],num[3]);
//	return 0;
//}
//
//void swap(int* a,int* b){
//	int t=*a;
//	*a=*b;
//	*b=t;
//}
