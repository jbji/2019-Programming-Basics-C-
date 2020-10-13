//
// Created by jbji on 20-6-11.
//

#include "Course.h"
#include "IO.h"
#include "IdGenerator.h"
#include <iomanip>

#define AUTO 1
#define MANUAL 2
#define BYNAME 1
#define BYID 2

string prompt1_1_1="输入课程名称、学分来添加课程："
    ,success1_1_1="课程添加成功！本次添加的课程为："
    ,prompt1_1_2="输入课程CID、名称、学分来添加课程（以空格分隔）："
    ,failed1_1_2="添加失败，课程CID非法!\n请重新输入课程CID、名称来添加课程:"
    ,prompt1_3_1="当前课程列表："
    ,prompt1_2="输入课程CID以删除课程："
    ,success1_2="删除成功！"
    ,failed1_2="删除失败！请检查CID是否存在..."
    ,prompt1_3_2_1="输入名称以查找课程："
    ,prompt1_3_2_2="输入CID以查找课程："
    ,success1_3_2_a="找到了"
    ,success1_3_2_b="个课程"
    ,prompt1_3_3="输入CID以修改课程名称和学分："
    ,prompt1_3_3_1="输入新的课程名称、学分："
    ,success1_3_3="修改成功！"

;

extern string sp,nl;

void addCos(map<string,Course> &clib,int mode){
    if(mode==AUTO){
        string tmpID=idGenerator("C");
        for(int p=0;p!=-1;){
            while(clib.count(tmpID)){
                tmpID=idGenerator("C");
            }
            clr();
            cout << prompt1_1_1<< endl;
            string tmpname;
            cin >> tmpname;
            float tmpcredit;
            cin >> tmpcredit;
            clib[tmpID]=Course(tmpID,tmpname,tmpcredit);
            cout << success1_1_1 <<endl;
            spe();
            clib[tmpID].showBasicTitle();
            clib[tmpID].basicInf();
            spe();
            navi(p,"以自动模式添加课程");
        }
    }else if(mode == MANUAL){
        string tmpID,tmpName;
        float tmpcredit;
        for(int p=0;p!=-1;){
            clr();
            cout << prompt1_1_2 << nl;
            cin >> tmpID >> tmpName >> tmpcredit;
            while(clib.count(tmpID)){
                cout << failed1_1_2 << nl;
                cin >> tmpID >> tmpName >> tmpcredit;
            }
            clib[tmpID]=Course(tmpID,tmpName,tmpcredit);
            cout << success1_1_1 <<endl;
            spe();
            clib[tmpID].showBasicTitle();
            clib[tmpID].basicInf();
            spe();
            navi(p,"以手动模式添加课程");
        }
    }
}
void delCos(map<string,Course> &clib){
    for(int p=0;p!=-1;){
        clr();
        spe();
        showCos(clib);
        cout << prompt1_2<< endl;
        string tmpID;
        cin >> tmpID;
        if(clib.count(tmpID)){
            cout << success1_2 <<endl;
            clib.erase(tmpID);
        }else{
            cout << failed1_2 <<endl;
        }
        spe();
        navi(p,"删除课程");
    }
}
void showCos(map<string, Course> clib){
    clr();
    cout<< prompt1_3_1 << endl;
    Course::showBasicTitle();
    spe();
    Course::showBasicTitle();
    for (map<string, Course>::iterator clib_it = clib.begin(); clib_it != clib.end(); clib_it++){
        clib_it->second.basicInf();
    }
    spe();
}
void findCos(map<string,Course> &clib,int mode){
    if(mode==BYNAME){
        for(int p=0;p!=-1;){
            clr();
            cout << prompt1_3_2_1<< endl;
            string tmpname;
            cin >> tmpname;
            Course::showBasicTitle();
            int i=0;
            for (map<string, Course>::iterator clib_it = clib.begin(); clib_it != clib.end(); clib_it++){
                if(!clib_it->second.getName().compare(tmpname)){
                    clib_it->second.basicInf();
                    i++;
                }
            }
            cout << success1_3_2_a << i << success1_3_2_b<<endl;
            spe();
            navi(p,"按名称查找课程");
        }
    }else if(mode==BYID){
        for(int p=0;p!=-1;){
            clr();
            cout << prompt1_3_2_2<< endl;
            string tmpID;
            cin >> tmpID;
            int i=0;
            for (map<string, Course>::iterator clib_it = clib.begin(); clib_it != clib.end(); clib_it++){
                if(!clib_it->second.getID().compare(tmpID)){
                    spe();
                    clib_it->second.showFullTitleLong();
                    spe();
                    clib_it->second.fullInfLong();
                    spe();
                    i++;
                    break;
                }
            }
            cout << success1_3_2_a << i << success1_3_2_b<<endl;
            spe();
            navi(p,"按CID查找课程");
        }
    }
}
void editCos(map<string,Course> &clib){
    for(int p=0;p!=-1;){
        clr();
        cout << prompt1_3_3<< endl;
        string tmpID,tmpname;
        float tmpcredit;
        cin >> tmpID;
        for (map<string, Course>::iterator clib_it = clib.begin(); clib_it != clib.end(); clib_it++){
            if(!clib_it->second.getID().compare(tmpID)){
                cout<<prompt1_3_3_1<<endl;
                cin >> tmpname >> tmpcredit;
                clib_it->second.newName(tmpname);
                clib_it->second.newCredit(tmpcredit);
                break;
            }
        }
        cout << success1_3_3 <<endl;
        spe();
        navi(p,"修改课程信息");
    }
}

void addStuToCos(map<string, Student> &ulib, map<string, Course> &clib) {

}

void delStuFromCos(map<string, Student> &ulib, map<string, Course> &clib) {

}


void Course::basicInf() {
    cout << setw(15) <<left<< CID <<setw(15) <<left<< name <<setw(15) <<left<< credit << endl;
}

void Course::showBasicTitle() {
    cout << setw(15) <<left<< "课程CID" <<setw(15) <<left<< "课程名称" << setw(15) <<left<< "课程学分"<< endl;
}

string Course::getName() {
    return name;
}

string Course::getID() {
    return CID;
}

void Course::showFullTitleLong() {
    cout << setw(15) <<left<< "课程CID: " <<setw(15) <<left<< CID <<setw(15) <<left<< "课程名称" <<setw(15) <<left<< name << endl;
//    cout << setw(15) <<left<< "已选课程数量: " <<setw(15) <<left<< course_counter <<setw(15) <<left<< "已选学分: " <<setw(15) <<left<< credit_counter << endl;
//    cout << setw(15) <<left<< "加权成绩: " <<setw(15) <<left<< weightScore <<setw(15) <<left<< "总排名: " <<setw(15) <<left<< rank << endl;
}

void Course::fullInfLong() {
//    cout << setw(15) <<left<< "课程ID" <<setw(15) <<left<< CID <<setw(15) <<left<< "课程名称" <<setw(15) <<left<< name << endl;
}

void Course::newName(string name) {
    this->name=name;
}

void Course::newCredit(float credit) {
    this->credit=credit;
}
