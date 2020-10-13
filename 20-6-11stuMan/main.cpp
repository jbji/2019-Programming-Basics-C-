#include <iostream>
#include "Student.h"
#include "Course.h"
#include "Score.h"
#include "IO.h"
#include <string>
#include <map>

using namespace std;
//注意：所有的函数都是自循环的，无论是操作函数还是菜单函数
int main() {
    //学生库与课程库，分数库名称slib
    map<string,Student> ulib;
    map<string,Course> clib;
    clr();
    for(int pointer=0;pointer!=-1;){
        mainMenu();
        cin>>pointer;
        clr();
        switch(pointer){
            case 1:
                cosMenu(pointer,ulib,clib);
                break;
            case 2:
                stuMenu(pointer,ulib,clib);
                break;
            case 3:
                scoMenu(pointer,ulib,clib);
                break;
            case 4:
                saveAndExit(pointer,ulib,clib);
                break;
            case 5:
                exitOnly(pointer);
                break;
            default:
                defaultInput(pointer);
                break;
        }
    }

    return 0;
}