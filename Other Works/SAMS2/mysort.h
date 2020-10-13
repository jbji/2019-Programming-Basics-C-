#ifndef MYSORT_H
#define MYSORT_H

#include <iostream>
#include <QString>
using namespace std;

//添加一个结构体，包含 学生姓名，学号， 分数 三个字段
struct _student
{
    string Name;    //学生姓名
    string Num;        //学号
    string Score;      //分数
};
//int sCount;                         //全局变量计数学生人数
//_student stu[100];                  //定义结构体数组
void asc_sort_byNum(_student *stu, int sCount);              //按照学号升序
void desc_sort_byNum(_student *stu, int sCount);             //按照学号降序
void asc_sort_byScore(_student *stu, int sCount);            //按照成绩升序
void desc_sort_byScore(_student *stu, int sCount);           //按照成绩降序
void showIn_sum();                  //接口函数，按照排序后的学生信息，进行显示

#endif // MYSORT_H
