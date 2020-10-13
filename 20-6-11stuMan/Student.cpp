//
// Created by jbji on 20-6-11.
//

#include "IO.h"
#include "IdGenerator.h"
#include "Student.h"
#include <iomanip>

#define AUTO 1
#define MANUAL 2
#define BYNAME 1
#define BYID 2

string prompt2_1_1="输入姓名来添加学生："
        ,success2_1_1="学生添加成功！本次添加的学生为："
        ,prompt2_1_2="输入学生UID、姓名来添加学生（以空格分隔）："
        ,failed2_1_2="添加失败，学生UID非法!\n请重新输入学生UID、姓名来添加学生:"
        ,prompt2_3_1="当前学生列表："
        ,prompt2_2="输入学生UID以删除学生："
        ,success2_2="删除成功！"
        ,failed2_2="删除失败！请检查UID是否存在..."
        ,prompt2_3_2_1="输入姓名以查找学生："
        ,prompt2_3_2_2="输入UID以查找学生："
        ,success2_3_2_a="找到了"
        ,success2_3_2_b="个学生"
        ,prompt2_3_3="输入UID以修改学生姓名："
        ,prompt2_3_3_1="输入新的学生姓名："
        ,success2_3_3="修改成功！"
        ,prompt2_3_4="您正在尝试为学生添加课程！\n"
                     "请依次输入学生的UID、多门课程的CID(以空格分隔，0结尾)。\n"
                     "注：若该学生已选择某课程、或某课程不存在，则自动跳过\n"
                     "例如：U2020123 C2020134 C2020216 C2020326 C2020128 0"
;

extern string sp,nl;

void addStu(map<string,Student> &ulib,int mode){
    if(mode==AUTO){
        string tmpID=idGenerator("U");
        for(int p=0;p!=-1;){
            while(ulib.count(tmpID)){
                tmpID=idGenerator("U");
            }
            clr();
            cout << prompt2_1_1<< endl;
            string tmpname;
            cin >> tmpname;
            ulib[tmpID]=Student(tmpID,tmpname);
            cout << success2_1_1 <<endl;
            spe();
            ulib[tmpID].showBasicTitle();
            ulib[tmpID].basicInf();
            spe();
            navi(p,"以自动模式添加学生");
        }
    }else if(mode == MANUAL){
        string tmpID,tmpName;
        for(int p=0;p!=-1;){
            clr();
            cout << prompt2_1_2 << nl;
            cin >> tmpID >> tmpName;
            while(ulib.count(tmpID)){
                cout << failed2_1_2 << nl;
                cin >> tmpID >> tmpName;
            }
            ulib[tmpID]=Student(tmpID,tmpName);
            cout << success2_1_1 <<endl;
            spe();
            ulib[tmpID].showBasicTitle();
            ulib[tmpID].basicInf();
            spe();
            navi(p,"以手动模式添加学生");
        }
    }
}
void delStu(map<string,Student> &ulib){
    for(int p=0;p!=-1;){
        clr();
        spe();
        showStu(ulib);
        cout << prompt2_2<< endl;
        string tmpID;
        cin >> tmpID;
        if(ulib.count(tmpID)){
            cout << success2_2 <<endl;
            ulib.erase(tmpID);
        }else{
            cout << failed2_2 <<endl;
        }
        spe();
        navi(p,"删除学生");
    }
}
void showStu(map<string, Student> ulib){
    clr();
    cout<< prompt2_3_1 << endl;
    Student::showBasicTitle();
    spe();
    Student::showBasicTitle();
    for (map<string, Student>::iterator ulib_it = ulib.begin(); ulib_it != ulib.end(); ulib_it++){
        ulib_it->second.basicInf();
    }
    spe();
}
void findStu(map<string,Student> &ulib,int mode){
    if(mode==BYNAME){
        for(int p=0;p!=-1;){
            clr();
            cout << prompt2_3_2_1<< endl;
            string tmpname;
            cin >> tmpname;
            Student::showBasicTitle();
            int i=0;
            for (map<string, Student>::iterator ulib_it = ulib.begin(); ulib_it != ulib.end(); ulib_it++){
                if(!ulib_it->second.getName().compare(tmpname)){
                    ulib_it->second.basicInf();
                    i++;
                }
            }
            cout << success2_3_2_a << i << success2_3_2_b<<endl;
            spe();
            navi(p,"按姓名查找学生");
        }
    }else if(mode==BYID){
        for(int p=0;p!=-1;){
            clr();
            cout << prompt2_3_2_2<< endl;
            string tmpID;
            cin >> tmpID;
            int i=0;
            for (map<string, Student>::iterator ulib_it = ulib.begin(); ulib_it != ulib.end(); ulib_it++){
                if(!ulib_it->second.getID().compare(tmpID)){
                    spe();
                    ulib_it->second.showFullTitleLong();
                    spe();
                    ulib_it->second.fullInfLong();
                    spe();
                    i++;
                    break;
                }
            }
            cout << success2_3_2_a << i << success2_3_2_b<<endl;
            spe();
            navi(p,"按UID查找学生");
        }
    }
}
void editStu(map<string,Student> &ulib){
    for(int p=0;p!=-1;){
        clr();
        cout << prompt2_3_3<< endl;
        string tmpID,tmpname;
        cin >> tmpID;
        for (map<string, Student>::iterator ulib_it = ulib.begin(); ulib_it != ulib.end(); ulib_it++){
            if(!ulib_it->second.getID().compare(tmpID)){
                cout<<prompt2_3_3_1<<endl;
                cin >> tmpname;
                ulib_it->second.newName(tmpname);
                break;
            }
        }
        cout << success2_3_3 <<endl;
        spe();
        navi(p,"修改学生信息");
    }
}
void addCosToStu(map<string,Student> &ulib,map<string,Course> &clib){
    for(int p=0;p!=-1;){
        clr();
        navi(p,"为学生添加课程");
    }
}
void delCosFromStu(map<string,Student> &ulib,map<string,Course> &clib){

}

void Student::basicInf() {
    cout << setw(15) <<left<< UID <<setw(15) <<left<< name << endl;
}

void Student::showBasicTitle() {
    cout << setw(15) <<left<< "学生UID" <<setw(15) <<left<< "学生姓名" << endl;
}

string Student::getName() {
    return name;
}

string Student::getID() {
    return UID;
}

void Student::showFullTitleLong() {
    cout << setw(15) <<left<< "学生UID: " <<setw(15) <<left<< UID <<setw(15) <<left<< "学生姓名: " <<setw(15) <<left<< name << endl;
    cout << setw(15) <<left<< "已选课程数量: " <<setw(15) <<left<< course_counter <<setw(15) <<left<< "已选学分: " <<setw(15) <<left<< credit_counter << endl;
    cout << setw(15) <<left<< "加权成绩: " <<setw(15) <<left<< weightScore <<setw(15) <<left<< "总排名: " <<setw(15) <<left<< rank << endl;
}

void Student::fullInfLong() {
    cout << setw(15) <<left<< "课程ID" <<setw(15) <<left<< UID <<setw(15) <<left<< "课程名称" <<setw(15) <<left<< name << endl;
}

void Student::newName(string name) {
    this->name=name;
}
