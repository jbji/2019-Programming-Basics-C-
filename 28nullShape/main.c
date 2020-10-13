#include <stdio.h>

int main() {
    int n,initial;
    int line,lineMarker;
    scanf("%d %d",&n,&initial);
    if(n==1){
        printf("%i\n",initial);
        return 1;
    }
    //输出首行

    for(int i=1;i<=3*n/2-(n%2==1?0:1);i++){
        printf("%i ",initial);
        initial=(initial==9)?0:initial+1;
    }
    initial-=(n%2==1?2:1);
    for(int i=1;i<=3*n/2-1;i++){
        if (i==3*n/2-1){
            printf("%i\n",initial);
        }else{
            printf("%i ",initial);
            initial=(initial==0)?9:initial-1;
        }
    }
    //输出余下各行
    for(line=1;line<n-1;line++){
        //LSpace
        for(lineMarker=line;lineMarker>0;lineMarker--){
            printf("  ");
        }
        //LNum
        initial=(initial==9)?0:initial+1;
        printf("%-2i",initial);
        //MidSpace
//        for(int i=n%2==1?3*n-2-2*line-2:3*n-2-2*line-1;i>0;i--){
        for(int i=3*n-2-2*line-2;i>0;i--){
            printf("  ");
        }
        //RNum
        printf("%i\n",initial);
    }

    //输出最后一行

    //输出空格
    for(lineMarker=line;lineMarker>0;lineMarker--){
        printf("  ");
    }
    //输出数字
    initial=(initial==9)?0:initial+1;
    for(int i=1;i<=n/2+1-(n%2==1?0:1);i++){
        printf("%i ",initial);
        initial=(initial==9)?0:initial+1;
    }
    initial-=(n%2==1?2:1);
    for(int i=1;i<=n/2;i++){
        if (i==n/2){
            printf("%i\n",initial);
        }else{
            printf("%i ",initial);
            initial=(initial==0)?9:initial-1;
        }
    }

    return 0;
}