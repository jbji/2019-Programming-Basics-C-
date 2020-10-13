#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int cube[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cube[i][j]=0;
        }
    }
    cube[0][n/2]=1;
    int Lrow,LCol;
    for(int i=2;i<=n*n;i++){
        int temp=i-1;
        int isFound=0;
        int j=0;
        //case1
        for(j=0;j<n;j++){
            if(temp==cube[0][j]){
                isFound=1;
                break;
            }
        }
        if(j!=n-1&&isFound){
            cube[n-1][j+1]=i;
            Lrow=n-1;LCol=j+1;
            continue;
        }
        isFound=0;
        //case2
        for(j=0;j<n;j++){
            if(temp==cube[j][n-1]){
                isFound=1;
                break;
            }
        }
        if(j!=0&&isFound){
            cube[j-1][0]=i;
            Lrow=j-1;LCol=0;
            continue;
        }
        isFound=0;
        //case3
        if(cube[0][n-1]==temp){
            cube[1][n-1]=i;
            Lrow=1;LCol=n-1;
            continue;
        }
        //case4
        if(cube[Lrow-1][LCol+1]==0){
            cube[Lrow-1][LCol+1]=i;
            Lrow--;LCol++;
            continue;
        }else{
            cube[Lrow+1][LCol]=i;
            Lrow++;
            continue;
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",cube[i][j]);
        }
        printf("\n");
    }
    return 0;
}