#include <stdio.h>
#include <string.h>

int main() {
    char str[1000],fi[100];
    char *ps=str;
    int t=0;
    scanf("%[^\n]",str);
    scanf("%s",fi);
    while(ps=strstr(ps,fi)){
        ps+=strlen(fi);
        t++;
    }
    if(t!=0){
        printf("%d\n",t);
    }else{
        printf("No\n");
    }

    return 0;
}