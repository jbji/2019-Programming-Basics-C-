//
// Created by jbji on 20-6-11.
//


#include "IO.h"


using namespace std;

string titlein = "请选择你期望进行的操作（输入对应数字编号，输入其他数值将返回上一级菜单）："
        ,title1 = " 1) 课程管理 - 添加、删除或修改课程√"
            ,title1_1 = " 1)) 仅添加课程√"
                ,title1_1_1 = " 1))) 我希望自动生成课程CID√"
                ,title1_1_2 = " 2))) 我希望手动键入课程CID√"
            ,title1_2 = " 2)) 仅删除课程√"
            ,title1_3 = " 3)) 课程信息查询与修改√"
                ,title1_3_1 = " 1))) 显示所有课程的基本信息√"
                ,title1_3_2 = " 2))) 查找指定课程详细信息√"
                    ,title1_3_2_1 = " 1)))) 按课程名称查找 - 模糊查找√"
                    ,title1_3_2_2 = " 2)))) 按课程CID查找 - 额外显示课程已有学生、课程成绩、总平均成绩"
                ,title1_3_3 = " 3))) 修改课程基本信息（按课程CID）√"
                ,title1_3_4 = " 4))) 为课程添加学生"
                ,title1_3_5 = " 5))) 为课程删除学生"
        ,title2=" 2) 学生管理 - 添加、删除或修改学生信息√"
            ,title2_1 = " 1)) 仅添加学生√"
                ,title2_1_1 = " 1))) 我希望自动生成学生UID√"
                ,title2_1_2 = " 2))) 我希望手动键入学生UID√"
            ,title2_2 = " 2)) 仅删除学生√"
            ,title2_3 = " 3)) 学生信息查询与修改√"
                ,title2_3_1 = " 1))) 显示所有学生的基本信息√"
                ,title2_3_2 = " 2))) 查找指定学生详细信息√"
                    ,title2_3_2_1 = " 1)))) 按姓名查找 - 模糊查找√"
                    ,title2_3_2_2 = " 2)))) 按学生UID查找 - 额外显示学生已选课程、已选学分、课程成绩、加权成绩"
                ,title2_3_3 = " 3))) 修改学生基本信息（按学生UID）√"
                ,title2_3_4 = " 4))) 为学生添加课程"
                ,title2_3_5 = " 5))) 为学生删除课程"
        ,title3=" 3) 成绩操作 - 录入成绩与成绩分析"
            ,title3_1 = " 1)) 录入成绩"
                ,title3_1_1 = " 1))) 按[指定学生]的[指定课程]录入"
                ,title3_1_2 = " 2))) 按[课程]录入[所有未录入成绩的学生]的成绩"
                ,title3_1_3 = " 2))) 按[学生]录入[所有未录入成绩的课程]的成绩"
            ,title3_2 = " 2)) 课程成绩分析"
            ,title3_3 = " 3)) 学生个人成绩分析"
            ,title3_4 = " 4)) 学生成绩整体分析"
        ,title4=" 4) 保存所有操作并退出"
        ,title5=" 5) 退出但不保存任何操作";
string sp="===================================";
string nl="\n";

void mainMenu(){
    cout << sp << nl
         << "欢迎使用学生成绩管理系统！" << nl
         << "版本号 Alpha v0.5 by jbji" << nl
         << "! 强烈建议在任何情况下，都输入0来返回上一级菜单" << nl
         << sp << nl
         << titlein << nl
         << title1 << nl
         << title2 << nl
         << title3 << nl
         << sp << nl
         << title4 << nl
         << title5 << nl
         << sp << nl << endl;
}

void cosMenu(int &p, map <string, Student> &ulib, map <string, Course> &clib){
    p=0;
    while(p != -1){
        cout << sp << nl
            << title1 << nl
            << sp << nl
            << title1_1 << nl
            << title1_2 << nl
            << title1_3 << nl
            << titlein << nl
            << sp << nl << endl;
        cin >> p;
        clr();
        switch (p){
            case 1:
                cout <<sp<<nl<<title1_1<<nl<<sp<<nl
                    << title1_1_1 << nl
                     << title1_1_2 << nl
                     << titlein << nl
                     << sp << nl << endl;
                cin >> p;
                clr();
                addCos(clib, p);
                break;
            case 2:
                delCos(clib);
                break;
            case 3:
                cosMenu_3(p,ulib,clib);
                break;
            default:
                defaultInput(p);
                break;
        }
    }
    p=0;
}

void cosMenu_3(int &p, map<string,Student> &ulib, map<string,Course> &clib){
    p=0;
    while(p!=-1){
        cout <<sp<<nl<< title1_3 << nl <<sp<<nl
             << title1_3_1 << nl
             << title1_3_2 << nl
             << title1_3_3 << nl
             << title1_3_4 << nl
             << title1_3_5 << nl
             << titlein << nl
             << sp << nl << endl;
        cin >> p;
        clr();
        switch(p){
            case 1:
                showCos(clib);
                navi();
                break;
            case 2:
                cout <<sp<<nl << title1_3_2 << nl <<sp << nl
                    << title1_3_2_1 << nl
                     << title1_3_2_2 << nl
                     << titlein << nl
                     << sp << nl << endl;
                cin >> p;
                clr();
                findCos(clib, p);
                break;
            case 3:
                editCos(clib);
                break;
            case 4:
                addStuToCos(ulib,clib);
                break;
            case 5:
                delStuFromCos(ulib,clib);
                break;
            default:
                defaultInput(p);
                break;
        }
    }
    p=0;
}

void stuMenu(int &p, map<string,Student> &ulib, map<string,Course> &clib) {
    p=0;
    while(p != -1){
        cout << sp << nl
             << title2 << nl
             << sp << nl
             << title2_1 << nl
             << title2_2 << nl
             << title2_3 << nl
             << titlein << nl
             << sp << nl << endl;
        cin >> p;
        clr();
        switch (p){
            case 1:
                cout <<sp<<nl<<title2_1<<nl<<sp<<nl
                    << title2_1_1 << nl
                     << title2_1_2 << nl
                     << titlein << nl
                     << sp << nl << endl;
                cin >> p;
                clr();
                addStu(ulib, p);
                break;
            case 2:
                delStu(ulib);
                break;
            case 3:
                stuMenu_3(p,ulib,clib);
                break;
            default:
                defaultInput(p);
                break;
        }
    }
    p=0;
}
void stuMenu_3(int &p, map<string, Student> &ulib, map<string, Course> &clib) {
    p=0;
    while(p!=-1){
        cout <<sp<<nl<<title2_3<<nl<<sp<<nl
             << title2_3_1 << nl
             << title2_3_2 << nl
             << title2_3_3 << nl
             << title2_3_4 << nl
             << title2_3_5 << nl
             << titlein << nl
             << sp << nl << endl;
        cin >> p;
        clr();
        switch(p){
            case 1:
                showStu(ulib);
                navi();
                break;
            case 2:
                cout <<sp<<nl<<title2_3<<nl<<sp<<nl
                    << title2_3_2_1 << nl
                     << title2_3_2_2 << nl
                     << titlein << nl
                     << sp << nl << endl;
                cin >> p;
                clr();
                findStu(ulib, p);
                break;
            case 3:
                editStu(ulib);
                break;
            case 4:
                addCosToStu(ulib,clib);
                break;
            case 5:
                delCosFromStu(ulib,clib);
                break;
            default:
                defaultInput(p);
                break;
        }
    }
    p=0;
}


void scoMenu(int &p, map<string, Student> &ulib, map<string, Course> &clib) {
    p=0;
    while(p != -1){
        cout << sp << nl
             << title3 << nl
             << sp << nl
             << title3_1 << nl
             << title3_2 << nl
             << title3_3 << nl
             << title3_4 << nl
             << titlein << nl
             << sp << nl << endl;
        cin >> p;
        clr();
        switch (p){
            case 1:
                scoMenu_1(ulib,clib);
                break;
            case 2:
                cosAna(clib);
                break;
            case 3:
                stuAna_Single(ulib);
                break;
            case 4:
                stuAna_All(ulib);
                break;
            default:
                defaultInput(p);
                break;
        }
    }
    p=0;
}

void scoMenu_1(map<string, Student> &ulib, map<string, Course> &clib) {
    for(int p=0;p != -1;){
        cout << sp << nl
             << title3_1 << nl
             << sp << nl
             << title3_1_1 << nl
             << title3_1_2 << nl
             << title3_1_3 << nl
             << titlein << nl
             << sp << nl << endl;
        cin >> p;
        clr();
        switch (p){
            case 1:
                addScoreOfStuAndCos(ulib,clib);
                break;
            case 2:
                addScoreOfCourse(clib);
                break;
            case 3:
                addScoreOfStudent(ulib);
                break;
            default:
                defaultInput(p);
                break;
        }
    }
}

void saveAndExit(int &pointer, map<string, Student> &ulib, map<string, Course> &clib) {

}

void clr() {
    system("CLS");
}

void defaultInput(int &pointer) {
    //converts all inputs into -1;
    pointer=-1;
}

void exitOnly(int &pointer) {
    defaultInput(pointer);
}

void navi(int &p,string mode) {
    cout << "输入Y继续" << mode << "，输入任意字符返回上级菜单...";
    char tmp;
    cin >> tmp;
    clr();
    if(tmp!='Y'&&tmp!='y'){
        defaultInput(p);
    }
}

void navi(int&p) {
    cout << "输入任意字符返回上级菜单...";
    char tmp;
    cin >> tmp;
    clr();
    defaultInput(p);
}
void navi() {
    cout << "输入任意字符返回上级菜单...";
    char tmp;
    cin >> tmp;
    clr();
}

void spe() {
    cout << sp << endl;
}


// loop标准模板
//for(int p=0;p!=-1;){
//clr();
//navi(p,"为学生添加课程");
//}