#include <stdio.h>
#include <string.h>
#define MAX(x,y) (x>y?x:y)

int main(){
	char input[10000]={'\0'};
	char in1[5000]={'\0'};
	char in2[5000]={'\0'};
	char op;
	int i=0,j=0;
	int num1[5000]={0};
	int num2[5000]={0};
    int result[5000]={0};
    int temp=0;//这里定义了一个查找上限的变量
    int t=0;
    scanf("%d",&t);
    //这是定义我们的多次运算
    for(;t>0;t--){
    //这里首先清空我们所使用的所有变量。
    i=0,j=0,temp=0;
    for(int k=0;k<5000;k++){
        in1[k]='0';
        in2[k]='0';
        num1[k]=0;
        num2[k]=0;
        result[k]=0;

    }

	//输入字符串并对其进行拆解
	scanf("%s",input);
	for(i=0;input[i]!='+'&&input[i]!='-';i++){
		in1[i]=input[i];
	}
	op=input[i];
	in1[i]='\0';
	i++;
	for(j=0;input[i]!='\0';i++,j++){
		in2[j]=input[i];
	}
	in2[j]='\0';

	//处理两串数字
	//首先指定数字长度
	num1[0]=strlen(in1);
	num2[0]=strlen(in2);
	//然后填充数字
    for(int k=num1[0];k>=1;k--){
        num1[k]=in1[num1[0]-k]-'0';
    }
    for(int k=num2[0];k>=1;k--){
        num2[k]=in2[num2[0]-k]-'0';
    }
    //现在我们拿到了两串数字构成的数组。




    //现在进行加法运算
    if(op=='+'){
        //进行一遍累加
        for(int k=1;k<=MAX(num1[0],num2[0]);k++){
            result[k]=num1[k]+num2[k];
        }
        //进行一遍进位
        for(int k=1;k<=MAX(num1[0],num2[0]);k++){
            result[k+1]+=result[k]/10;
            result[k]%=10;
        }
        //寻找最大位数
        for(temp=4999;result[temp]==0&&temp>1;temp--){}
        //逐字符倒序输出
        for(int k=temp;k>=1;k--){
            printf("%d",result[k]);
        }
        //换行并完成操作
        printf("\n");

    }



    //这里进行减法运算
    if(op=='-'){
        //进行一遍累减
        for(int k=1;k<=MAX(num1[0],num2[0]);k++){
            result[k]=num1[k]-num2[k];
        }
        //寻找最大位数
        for(temp=4999;result[temp]==0&&temp>1;temp--){}
        //进行一遍进位
        //这是最大位小于零的情况，此时结果一定为负数
        if(result[temp]<0){
            //根据一定的算术原理，将除了最高位以外的位数全部取相反数
            for(int k=1;k<temp;k++){
                result[k]=-result[k];
            }
            //并对剩下的数字按照普通进位法则进位
            for(int k=1;k<temp-1;k++){
                if(result[k]<0){
                    result[k]+=10;
                    result[k+1]-=1;
                }
            }
            //处理最高位前面一位数字的进位时，考虑最高位继续进位是否变为0
            if(result[temp-1]<0){//如果最高位前面一位数字仍然需要进位
                //则进位
                result[temp-1]+=10;
                result[temp]+=1;
                //如果进位后最高位变为零，那么符号由前一位提供。
                if(result[temp]==0){
                    result[temp-1]=-result[temp-1];
                }
            }
        }
        //这是最高位大于0的情况，这时候就可以按照普通进位法则进位啦。
        if(result[temp]>0){
            for(int k=1;k<=temp;k++){
                if(result[k]<0){
                    result[k]+=10;
                    result[k+1]-=1;
                }
            }
        }
        //再次寻找最大位数
        for(temp=4999;result[temp]==0&&temp>1;temp--){}
        //逐字符倒序输出
        for(int k=temp;k>=1;k--){
            printf("%d",result[k]);
        }
        //换行并完成操作
        printf("\n");

    }
    }
	return 0;
}