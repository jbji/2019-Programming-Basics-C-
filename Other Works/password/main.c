#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,i,j,x,m,b[4];
    char a[100];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        gets(a);
        if (i==1) gets(a);
        x=strlen(a);
        if (x<6) {printf("Not Safe\n");continue;}
        b[0]=0;b[1]=0;b[2]=0;b[3]=0;
        for (j=0;j<=x-1;j++)
        {
            if (48<=a[j]&&a[j]<=57) b[0]=1;
            else
            if  (65<=a[j]&&a[j]<=91) b[1]=1;
            else
            if (97<=a[j]&&a[j]<=123) b[2]=1;
            else b[3]=1;
            if (a[0]+a[1]+a[2]+a[3]==4) break;
        }
        m=b[0]+b[1]+b[2]+b[3];
        switch (m)
        {
            case 1:printf("Not Safe\n");break;


            case 2:printf("Medium Safe\n");break;
            case 3:printf("Safe\n");break;
            case 4:printf("Safe\n");
        }
    }
    return 0;
}
