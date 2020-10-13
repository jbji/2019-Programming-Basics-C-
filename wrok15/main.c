#include <stdio.h>
void main() {
    int m1,d1,m2,d2,i=0;
    scanf("%d:%d %d:%d",&m2,&d2,&m1,&d1);
    int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    if(m1==m2&&d2>=d1){i+=d2-d1;
    }else if(m2>m1){i+=days[m1]-d1+d2;
        for(int j=m1+1;j<m2;j++){i+=days[j];}
    }else{printf("Duang\n");}
    if(m2>m1||(m2=m1&&d2>=d1)){printf ("%d\n",i);}}