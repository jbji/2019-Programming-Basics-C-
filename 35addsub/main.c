#include <stdio.h>
#include <string.h>
void add(char a[],char b[]){
    int i,la,lb,max;
    int na[500]={0},nb[500]={0};
    la=strlen(a);
    lb=strlen(b);
    for(int i=0;i<la;i++){
        na[la-1-i] = a[i] - '0';
    }
    for(int i=0;i<lb;i++){
        nb[lb-1-i] = b[i] - '0';
    }
    max = la>lb?la:lb;
    for(i=0;i<max;i++){
        na[i]+=nb[i];
        na[i+1]+=na[i]/10;
        na[i]%=10;
    }
    if(na[max]){
        max++;
    }
    for(i=max-1;i>=0;i--){
        printf("%d",na[i]);
    }
    printf("\n");
    return;
}
void sub(char a[],char b[]){
    int i,la,lb,max;
    int flag=0;
    int na[500]={0},nb[500]={0};
    la=strlen(a);
    lb=strlen(b);
    max = la>lb?la:lb;
    for(int i=0;i<max;i++){
        if(na[i]<nb[i]){
            flag=1;
        }
    }
    if(la<lb||la==lb&&flag){
        printf("-");
    }
    for(int i=0;i<la;i++){
        na[la-1-i] = a[i] - '0';
    }
    for(int i=0;i<lb;i++){
        nb[lb-1-i] = b[i] - '0';
        nb[lb-1-i] =9-nb[lb-1-i];
    }
    for(i=0;i<max;i++){
        na[i]+=nb[i];
        na[i+1]+=na[i]/10;
        na[i]%=10;
    }
    for(int i=0;i<max;i++){
        na[i]=9-na[i];
    }
    if(na[max]){
        max++;
    }
    for(i=max-1;i>=0;i--){
        printf("%d",na[i]);
    }
    printf("\n");
    return;
}
int main() {
    char a[500]={0},b[500]={0};
    int n;
    sub("53","1000");
//    scanf("%i",&n);
//    for(int i=0;i<n;i++){
//        for(int j=0;((a[j]= getchar())!='+')&&(a[j]!='-');j++){}
//        scanf("%s+%s",a,b);
//        add(a,b);
//    }
    return 0;
}