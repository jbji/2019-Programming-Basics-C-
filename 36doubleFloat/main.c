#include <stdio.h>
#include <string.h>

int main() {
    char input[100]={'\0'};
    char inNum[100]={'\0'};
    char charCache;
    int exp=0;
    int gotExp=0;
    int floatPoint[200]={0};
    int temp=0;
    scanf("%s %c %d",input,&charCache,&exp);

    //将输入的字符去除小数点
    inNum[0]=input[0];
    for(int i=2;i<100;i++){
        inNum[i-1]=input[i];
    }
    //存储小数点位置
    floatPoint[exp+100]=1;


    //在指数大于零时进行检索小数点
    if(exp>=0){
        for(int i=strlen(input);i<100;i++){
            inNum[i]='0';
        }
        for(int i=0;i<100;i++){
            if(temp>=0){
                if(floatPoint[i+100]!=1){
                    if(inNum[i]=='\0'){
                        putchar('0');
                    }else{
                        putchar(inNum[i]);
                    }

                }else{
                    putchar(inNum[i]);
                    putchar('.');
                    gotExp=1;//标记此时找到了小数点
                    temp=8;
                }
            }
            //记录小数点后数字输出次数
            if(gotExp==1){
                temp--;
            }
        }
        //换行
        printf("\n");
    }

    if(exp<0){
        for(int i=strlen(input)-1;i<100;i++){
            inNum[i]='0';
        }
        temp=8;//这时已经找到了小数点。
        printf("0.");
        //输出前面的零
        for(int i=exp;i<-1&&temp>0;i++){
            printf("0");
            temp--;
        }
        //控制输出后面的数字
        for(int i=0;i<temp;i++){
            putchar(inNum[i]);
        }
        //换行
        printf("\n");
    }
    return 0;
}