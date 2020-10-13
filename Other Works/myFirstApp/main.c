#include <stdio.h>
#include <float.h>
#define PI 3.14

//Define variables outside.
int x=1;
int y=2;
const int PI1=3.14;

//int addTwoNum(){
//    // 函数内声明变量 x 和 y 为外部变量
//    extern int x;
//    extern int y;
//    // 给外部变量（全局变量）x 和 y 赋值
//    x = 1;
//    y = 2;
//    return x+y;
//}
int addTwoNumII();
int main() {
    printf("Hello, World!\n");
    printf("float %lu %E %E %d", sizeof(float),FLT_MIN,FLT_MAX,FLT_DIG);
    int result;
//    result = addTwoNum();
    result = addTwoNumII()+(int)PI*PI1;
    printf("\n%lu",result);

    return 0;
}