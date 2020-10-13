#include <stdio.h>
int maxLine(int *in){
    int temp=in[0];
    for(int i=0;i<sizeof(in);i++){
        if(temp<in[i]){
            temp=in[i];
        }
    }
    return temp;
}
int main(){
    int m,n;
    int flag=0;
    scanf("%i %i",&m,&n);
    int matrix[m][n];
//	for(int i=0;i<m*n;i++){
//		scanf("%i",(matrix[0]+i));
//	}
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%i",&matrix[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            flag=0;
            for(int k=0;k<n;k++){
                if(matrix[i][j]<matrix[i][k]){
                    flag=1;
                }
            }
            if(flag==0){
                for(int p=0;p<m;p++){
                    if(matrix[i][j]>matrix[p][j]){
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("Point:a[%i][%i]==%i\n",i,j,matrix[i][j]);
                    return 0;
                }
            }
        }
    }
    printf("No Point\n");
    return 0;
}