#include <iostream>
class NumberDisplay{
    //这是一种专门存储小时或者分钟这种数据的类
public:
    //初始化 构造函数 constructor
    NumberDisplay();
    NumberDisplay(int val,int lim);
    //函数
    bool increase();
private:
    int value;
    int limit;
};

class ClockDisplay{
    //就是时钟类，一定包含一个小时和分钟
    //hour, minute.
public:
    ClockDisplay();
    ClockDisplay(int hour_,int minute_);
    int start();
    int getTime();
    int getHour();
    int getMinute();
private:
    NumberDisplay hour;
    NumberDisplay minute;
};

class WorldClock{
private:
    ClockDisplay beijing;
    ClockDisplay tokyo;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}