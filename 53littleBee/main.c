#include <stdio.h>
int main() {
    unsigned long long int faboo(int);
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=1;i<200;i++){
        printf("%d ",faboo(i));
    }
    printf("%lld\n",faboo(b-a+1));
    return 0;
}

unsigned long long int faboo(int i){
    static unsigned long long int cache[500]={0,1,1};
    //带缓存的算法
//    int k;
    if(cache[i]!=0){
        return cache[i];
    }else{
        cache[i]=faboo(i-1)+faboo(i-2);
        return cache[i];
        //快速斐波那契算法
//        if(i%2==0){
//            k=i/2;
//            return faboo(k)*(2*faboo(k+1)-faboo(k));
//        }else{
//            k=(i-1)/2;
//            return faboo(k+1)*faboo(k+1)+faboo(k)*faboo(k);
//        }

    }
}