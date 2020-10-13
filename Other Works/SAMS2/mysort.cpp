#include "mySort.h"
#include <QString>
#include <iostream>
using namespace std;

//按照学号升序排序
void asc_sort_byNum(_student *stu, int sCount)
{

    _student stutemp;                           //临时中间结构体变量
    for(int i = 0; i < sCount; i++)             //采用冒泡法进行排序
    {
        for(int j = 0; j < sCount - i -1; j++)
        if(stu[j].Num > stu[j+1].Num)
        {
            stutemp.Name =  stu[j].Name;
            stutemp.Num = stu[j].Num;
            stutemp.Score = stu[j].Score;
            stu[j].Name = stu[j+1].Name;
            stu[j].Num = stu[j+1].Num;
            stu[j].Score = stu[j+1].Score;
            stu[j+1].Name = stutemp.Name;
            stu[j+1].Num = stutemp.Num;
            stu[j+1].Score = stutemp.Score;
        }
    }
}

//按照学号降序排序
void desc_sort_byNum(_student *stu,int sCount)
{
    _student stutemp;
    for(int i = 0; i < sCount; i++)
    {
        for(int j = 0; j < sCount - i -1; j++)
        if(stu[j].Num < stu[j+1].Num)
        {
            stutemp.Name =  stu[j].Name;
            stutemp.Num = stu[j].Num;
            stutemp.Score = stu[j].Score;
            stu[j].Name = stu[j+1].Name;
            stu[j].Num = stu[j+1].Num;
            stu[j].Score = stu[j+1].Score;
            stu[j+1].Name = stutemp.Name;
            stu[j+1].Num = stutemp.Num;
            stu[j+1].Score = stutemp.Score;
        }
    }
}

//按照成绩升序排序
void asc_sort_byScore(_student *stu,int sCount)
{
    _student stutemp;
    for(int i = 0; i < sCount; i++)
    {
        for(int j = 0; j < sCount - i -1; j++)
        if(stu[j].Score > stu[j+1].Score)
        {
            stutemp.Name =  stu[j].Name;
            stutemp.Num = stu[j].Num;
            stutemp.Score = stu[j].Score;
            stu[j].Name = stu[j+1].Name;
            stu[j].Num = stu[j+1].Num;
            stu[j].Score = stu[j+1].Score;
            stu[j+1].Name = stutemp.Name;
            stu[j+1].Num = stutemp.Num;
            stu[j+1].Score = stutemp.Score;
        }
    }
}

//按照成绩降序排序
void desc_sort_byScore(_student *stu,int sCount)
{
    _student stutemp;
    for(int i = 0; i < sCount; i++)
    {
        for(int j = 0; j < sCount - i -1; j++)
        if(stu[j].Score < stu[j+1].Score)
        {
            stutemp.Name =  stu[j].Name;
            stutemp.Num = stu[j].Num;
            stutemp.Score = stu[j].Score;
            stu[j].Name = stu[j+1].Name;
            stu[j].Num = stu[j+1].Num;
            stu[j].Score = stu[j+1].Score;
            stu[j+1].Name = stutemp.Name;
            stu[j+1].Num = stutemp.Num;
            stu[j+1].Score = stutemp.Score;
        }
    }
}

