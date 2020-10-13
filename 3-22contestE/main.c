#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int status;
    char *str1[n];
    char *str2[m];
    for(int i=0;i<n;i++){
        str1[i]=(char *)malloc(sizeof(char)*10);
        scanf("%s",str1[i]);
    }
    for(int i=0;i<m;i++){
        str2[i]=(char *)malloc(sizeof(char)*10);
        scanf("%s",str2[i]);
    }
    for(int i=0;i<m;i++){
        status=0;
        for(int j=0;j<n;j++){
            if(strcmp(str2[i],str1[j])==0){
                status=1;
                break;
            }
        }
        printf("%s\n",status==1?"YES":"NO");
    }
    return 0;
}