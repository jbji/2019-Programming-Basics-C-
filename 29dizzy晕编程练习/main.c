#include <stdio.h>
int * rMove(int *,int,int);
int * lMove(int *,int,int);
int * uMove(int *,int,int);
int * dMove(int *,int,int);
int * fill(int *matrix, int pos1 ,int pos2,int pos3,int pos4);
int n=0;

//定义填0函数并给标记数组填0
int mark[100][100];
void fillZero(int *matrix){
    int *p=matrix;
    for(int i=0;i<sizeof(matrix)/4;i++,p++){
        *p=0;
    }
}

int main() {
    scanf("%i",&n);
    int matrix[n][n];
    int pos1=0,pos2=0;
    fillZero(&mark);
    fillZero(&matrix);
    if(n==1){
        printf("%3i\n",1);
        return 0;
    }
    fill(&matrix,pos1,pos2,pos1,pos2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//只要程序把上一次走的地方发过来，就可以自动向前走

int * rMove(int * matrix,int pos1 ,int pos2){
    return fill(matrix,pos1,pos2+1,pos1,pos2);
}
int * lMove(int * matrix,int pos1 ,int pos2){
    return fill(matrix,pos1,pos2-1,pos1,pos2);
}
int * uMove(int * matrix,int pos1 ,int pos2){
    return fill(matrix,pos1-1,pos2,pos1,pos2);
}
int * dMove(int * matrix,int pos1 ,int pos2){
    return fill(matrix,pos1+1,pos2,pos1,pos2);
}


int * fill(int *matrix, int pos1 ,int pos2,int pos3,int pos4){
    static int sequence=0;
    static int pos1_;
    static int pos2_;
    pos1_=pos3;
    pos2_=pos4;

    sequence++;
    matrix[pos2+n*pos1]=sequence;
    mark[pos1][pos2]=1;

    if (/*初始情形*/pos1==pos1_&&pos2==pos2_||
        /*自左方来*/pos2-pos2_>0/*右方可走*/&&mark[pos1][pos2+1]!=1&&/*右未触边界*/(pos2+1<n)||
        /*自下方来*/pos2==pos2_&&pos1-pos1_<0&&/*右方可走*/mark[pos1][pos2+1]!=1&&/*上触边界*/(mark[pos1-1][pos2]==1||pos1-1<0)){
        return rMove(matrix,pos1,pos2);
    }
    if (/*自上方来*/pos1-pos1_>0&&/*下方可走*/mark[pos1+1][pos2]!=1&&/*下未触边界*/(pos1+1<n)||
        /*自左方来*/pos1==pos1_&&pos2-pos2_>0&&/*下方可走*/mark[pos1+1][pos2]!=1&&/*右触边界*/(mark[pos1][pos2+1]==1||pos2+1>=n)){
        return dMove(matrix,pos1,pos2);
    }
    if (/*自右方来*/pos2-pos2_<=0&&/*左方可走*/pos2-1>=0&&mark[pos1][pos2-1]!=1&&/*左未触边界*/(pos2-1>=0)||
        /*自下方来*/pos2==pos2_&&pos1-pos1_>0&&/*左方可走*/pos2-1>=0&&mark[pos1][pos2-1]!=1&&/*下触边界*/(mark[pos1+1][pos2]==1||pos1+1>=n)){
        return lMove(matrix,pos1,pos2);
    }
    if (/*自下方来*/pos1-pos1_<=0&&/*上方可走*/pos1-1>=0&&mark[pos1-1][pos2]!=1&&/*上未触边界*/(pos1-1>=0)||
        /*自右方来*/pos1==pos1_&&pos2-pos2_<0&&/*上方可走*/pos1-1>=0&&mark[pos1-1][pos2]!=1&&/*左触边界*/(mark[pos1][pos2-1]==1||pos2-1<0)){
        return uMove(matrix,pos1,pos2);
    }
    return matrix;
}