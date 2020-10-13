/*
 *写几个函数：
 *1 输入10个职工的姓名和职工号
 *2 按职工号由小到大顺序排序，姓名顺序也随之调整
 *3 要求输入一个职工号，用折半查找法找出该职工的姓名、
 * 从主函数输入要查找的职工号，输出该职工姓名
 * */
#define NUM 10 //为了防止10个职工成为魔法数，我们把10定义一下
#include <stdio.h>
#include <stdlib.h>

typedef struct _people{
    int no;
    char name[20];
}People;

//函数声明（原型）：
int getPeople(People *);//获取输入的函数
int sortPeople(People *);//排序函数
int cmp(const void *,const void *); //qsort函数所需要使用的比较函数
int searchPeople(int,People *);//查找函数


int main() {
    People a[NUM];
    getPeople(a);
    sortPeople(a);
    int num;
    do{
        printf("输入要查找的职工号：");
        scanf("%d",&num);
        num=searchPeople(num,a);
    }while(!num);


    return 0;
}

//函数定义：
int getPeople(People * a){
    printf("请依次输入%d个职工的姓名和职工号：\n格式：姓名 职工号，如：\nJason 666\n",NUM);
    for(int i=0;i<NUM;i++){
        printf("职工%d：",i+1);
        scanf("%s %d",(a+i)->name,&((a+i)->no));
    }
    return 0;
}
int sortPeople(People * a){
    qsort(a,NUM, sizeof(People),cmp);
    return 0;
}
int cmp(const void *a,const void *b){
    People * a1=(People *)a;
    People * b1=(People *)b;
    return a1->no-b1->no;
}

int searchPeople(int num,People *a){
    int inf=0,sup=NUM-1;
    int index = sup/2;
    int isFound=0;
    while(sup-inf!=0&&!isFound){
        if(num>(a+index)->no){
            inf=index;
            index=(sup+inf)/2;
            if(index==inf){
                index=sup;
            }
        }else if(num<(a+index)->no){
            if(sup==index){
                inf=sup;
            }
            sup=index;
            index=(sup+inf)/2;
        }else{
            isFound=1;
        }
    }
    if(isFound){
        printf("找到职工! 姓名:%s\n",(a+index)->name);
    }else{
        printf("职工未找到! 请重试!\n");
    }
    return isFound;
}

/*
 * 折半查找----又称为二分查找，这种查找方法需要待查的查找表满足两个条件：首先，查找表必须使用顺序存储结构；其次，查找表必须按关键字大小有序排列。



下面通过一个实际的例子来分析折半查找算法的执行步骤。假设有如下经过排序的数据：3 、12 、31 、42 、54 、59 、69 、77 、90 、97 。待查找关键字为42 。在折半查找过程如下：

(1) 取中间数据项mid 与待查找关键字42 对比， mid 项的值大千42 。因此， 42 应该在数据的前半部分。

(2) 取前半部分的中间数据项mid 与待查找关键字42 对比， mid 项的值小于42 。因此，42 应该在数据的后半部分。

(3) 取后半部分的中间数据项mid 与待查找关键字42 对比， mid 项的值小于42 。因此，42 应该在数据的后半部分。

(4) 最后数据仅剩一项，将其作为mid 与待查找关键字42 对比，正好相等，表示查找到该数据。这样，经过4 次比较便查找到42 所在的位置.

 */