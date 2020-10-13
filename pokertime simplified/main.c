#define 定义 define

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define l 3
#define 字符型 char
#define 类型定义 typedef
#define 结构 struct
#define 空返回 void
#define 整数型 int
#define 输出格式化 printf
#define 玩家 Player
#define 排序 qsort
#define 获取大小 sizeof
#define 扑克 Poker
#define 多重选择 switch
#define 情形 case
#define 结束 break;
#define 当 for
#define 自增 ++
#define 如果 if
#define 等于 ==
#define 不大于 <=
#define 不小于 >=
#define 小于 <
#define 大于 >
#define 赋值 =
#define 指向的 ->
#define 加 +
#define 减 -
#define 返回 return


字符型 colors[] = {'C','D','S','H'};
字符型 nums[][3] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

//the 结构 we use.
类型定义 结构 扑克{
    字符型 color;
    字符型 num[3];
    整数型 cVal;// 字符型ateristic value
}扑克;

类型定义 结构 玩家{
    扑克 扑克s[3];
    long long pVal;//玩家Val
}玩家;

空返回 get玩家(玩家 *);
//checktool
整数型 扑克Valid(扑克*);
整数型 inputs_Valid(扑克*);
整数型 inputs_notRep(扑克*,扑克*);
整数型 input_Check(玩家 *,玩家 *);
整数型 扑克Cmp(扑克 a,扑克 b);
整数型 cmp(const 空返回*,const 空返回*);
空返回 pValGenerate(玩家 *);
整数型 whoWin(const 玩家 *,const 玩家 *);
//math tool
long long pow(整数型 base,整数型 times);
整数型 abs(整数型 a);

整数型 main() {
    玩家 pA,pB;
    整数型 winnerFlag = 0;

    get玩家(&pA);
    fflush(stdin);
    get玩家(&pB);

    如果(!input_Check(&pA,&pB)){
        输出格式化("Input Error!\n");
        返回 0;
    }

    排序(pA.扑克s,l, 获取大小(扑克),cmp);
    排序(pB.扑克s,l, 获取大小(扑克),cmp);

    pValGenerate(&pA);
    pValGenerate(&pB);
    winnerFlag = whoWin(&pA,&pB);
    多重选择(winnerFlag){
        情形 1:
            输出格式化("Winner is A!\n");
            跳出;
        情形 -1:
            输出格式化("Winner is B!\n");
            跳出;
        情形 0:
            输出格式化("Winner is X!\n");
    }
    //here can be changed for multiple usage.
    输出格式化("A: %c%s %c%s %c%s\n",pA.扑克s[0].color,pA.扑克s[0].num,pA.扑克s[1].color,pA.扑克s[1].num,pA.扑克s[2].color,pA.扑克s[2].num);
    输出格式化("B: %c%s %c%s %c%s\n",pB.扑克s[0].color,pB.扑克s[0].num,pB.扑克s[1].color,pB.扑克s[1].num,pB.扑克s[2].color,pB.扑克s[2].num);

    返回 0;
}


整数型 扑克Valid(扑克* p){
    整数型 o1 = -1,o2 = -1,result = 0;
    当(整数型 i = 0;i<4;i自增){
        如果(p 指向的 color 等于 colors[i]){
            o1 = i;
            跳出;
        }
    }
    当(整数型 i = 0;i<13;i自增){
        如果(strcmp(p 指向的 num,nums[i]) 等于 0){
            o2 = i  加  2;//absolute num
            跳出;
        }
    }
    如果(o1! = -1&&o2! = -1){
        p 指向的 cVal = o1  加  o2*10;
        result = 1;
    }
    返回 result;
}
整数型 inputs_Valid(扑克 *in){
    整数型 result = 1,temp;
    //to check each 扑克's validity.
    当(整数型 i = 0;i<l;i自增){
        temp = 扑克Valid(in  加  i);
        result = result 大于 temp?temp:result;
    }
    返回 result;
}
整数型 inputs_notRep(扑克 *p1,扑克 *p2){
    整数型 rpcheck[200] = {0},result = 1;
    当(整数型 i = 0;i<l;i自增){
        rpcheck[(p1  加  i) 指向的 cVal]自增;
    }
    当(整数型 i = 0;i<l;i自增){
        rpcheck[(p2  加  i) 指向的 cVal]自增;
    }
    当(整数型 i = 0;i<200;i自增){
        如果(rpcheck[i] 大于 1){
            result = 0;
            跳出;
        }
    }
    返回 result;
}
整数型 input_Check(玩家 *p1,玩家 *p2){
    返回 inputs_Valid(p1 指向的 扑克s)&&inputs_Valid(p2 指向的 扑克s)&&inputs_notRep(p1 指向的 扑克s,p2 指向的 扑克s);
}
整数型 扑克Cmp(扑克 a,扑克 b){
    返回 a.cVal-b.cVal;
}
整数型 cmp(const 空返回 *a,const 空返回 *b){
    扑克 aa  =  *(扑克 *)a;
    扑克 bb  =  *(扑克 *)b;
    返回 -扑克Cmp(aa,bb);
}

整数型 whoWin(const 玩家 * pa,const 玩家 * pb){
    整数型 result;
    如果(pa 指向的 pVal 大于 pb 指向的 pVal){
        result = 1;
    }else 如果(pa 指向的 pVal<pb 指向的 pVal){
        result = -1;
    }else{
        result = 0;
    }
    返回 result;
}

空返回 get玩家(玩家 *p){
    当(整数型 i = 0;i<l;i自增){
        scanf("%c",&((p 指向的 扑克s  加  i) 指向的 color));
        scanf("%s",(p 指向的 扑克s  加  i) 指向的 num);
        getchar();
    }
}
空返回 pValGenerate(玩家 * p){
    //pVal的结构：同花顺|炸弹|连牌|对子|逆序三张牌
    整数型 flag = 1;整数型 sp = 0;
    p 指向的 pVal = 0;//务必将特征值置空
    //basic part
    当(整数型 i = 0;i<3;i自增){
        p 指向的 pVal  += ((p 指向的 扑克s  加  i) 指向的 cVal)*pow(10,3*(2-i));//务必注意此时的数字顺序。
    }
    //对子
    flag = 0;
    当(整数型 i = 0;i<3;i自增){
        当(整数型 j = i  加  1;j<3;j自增){
            如果(strcmp((p 指向的 扑克s  加  i) 指向的 num,(p 指向的 扑克s  加  j) 指向的 num) 等于 0){
                flag = 1;
                跳出;
            }
        }
    }
    p 指向的 pVal  加   = flag*pow(10,10);
    //连牌
    flag = 0;sp = 0;
    整数型 tmp1,tmp2;
    tmp1 = abs((p 指向的 扑克s 指向的 cVal)/10-((p 指向的 扑克s  加  1) 指向的 cVal)/10);
    tmp2 = abs(((p 指向的 扑克s  加  1) 指向的 cVal)/10-((p 指向的 扑克s  加  2) 指向的 cVal)/10);
    如果(tmp1 等于 tmp2&&tmp1 等于 1){
        flag = 1;sp = 1;
    }
    p 指向的 pVal  += flag*pow(10,11);
    //炸弹
    flag = 0;
    整数型 tmp3;
    tmp1 = ((p 指向的 扑克s  加  0) 指向的 cVal)/10;
    tmp2 = ((p 指向的 扑克s  加  1) 指向的 cVal)/10;
    tmp3 = ((p 指向的 扑克s  加  2) 指向的 cVal)/10;
    如果(tmp1 等于 tmp2&&tmp2 等于 tmp3){
        flag = 1;
    }
    p 指向的 pVal  += flag*pow(10,12);
    //同花顺
    flag = 0;
    如果(sp){
        tmp1 = ((p 指向的 扑克s  加  0) 指向的 cVal)%10;
        tmp2 = ((p 指向的 扑克s  加  1) 指向的 cVal)%10;
        tmp3 = ((p 指向的 扑克s  加  2) 指向的 cVal)%10;
        如果(tmp1 等于 tmp2&&tmp2 等于 tmp3){
            flag = 1;
        }
    }
    p 指向的 pVal  加   = flag*pow(10,13);
}

long long pow(整数型 base,整数型 times){
    long long result = 1;
    当(整数型 i = times;i 大于 0;i --){
        result *= base;
    }
    返回 result;
}
整数型 abs(整数型 a){
    返回 a<0?-a:a;

