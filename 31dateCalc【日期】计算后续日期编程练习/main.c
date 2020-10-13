#include <stdio.h>

int main() {
    int y,m,d,n;
    int yearCheck=0;
    int days[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    scanf("%d %d %d\n",&y,&m,&d);
    scanf("%d",&n);
    //这是检查是不是闰年
    yearCheck=((y%4==0&&y%100!=0)||(y%100==0&&y%400==0))?1:0;
    //这里是首先看看我们这个数字是不是没有出我们的月份
    if(days[yearCheck][m-1]-d>=n){
        d+=n;
    }else{
        do{
            //取出天数来加到日期上
            n-=days[yearCheck][m-1]-d+1;
            d=1;
            y=(m==12)?y+1:y;
            yearCheck=((y%4==0&&y%100!=0)||(y%100==0&&y%400==0))?1:0;
            m=(m==12)?1:m+1;
        }while(n>days[yearCheck][m-1]-d);
        d+=n;
    }
    printf("%i.%i.%i\n",y,m,d);
    return 0;
}