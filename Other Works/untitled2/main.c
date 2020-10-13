#include<stdio.h>

long  m[201][5];
int main(){int n;int i,j,d=0;for(i=0;i<201;i++){for(j=0;j<5;j++){m[i][j]=0;}}m[0][0]=m[1][0]=1;for(i=2;i<201;i++){for(j=0;j<5;j++{m[i][j]=m[i-1][j]+m[i-2][j]+d;d=m[i][j]/1000000000;m[i][j]=m[i][j]%1000000000;}}while(scanf("%d",&n)!=EOF){int f=0;for(i=4;i>=0;i--){if(m[n][i]!=0){f=1;printf("%ld",m[n][i]);}else if(f==1){printf("%ld",m[n][i]);}}printf("\n");}return 0;
 }
