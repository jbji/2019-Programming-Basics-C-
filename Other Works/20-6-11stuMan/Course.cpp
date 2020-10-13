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

string prompt1_1_1="����γ����ơ�ѧ������ӿγ̣�"
    ,success1_1_1="�γ���ӳɹ���������ӵĿγ�Ϊ��"
    ,prompt1_1_2="����γ�CID�����ơ�ѧ������ӿγ̣��Կո�ָ�����"
    ,failed1_1_2="���ʧ�ܣ��γ�CID�Ƿ�!\n����������γ�CID����������ӿγ�:"
    ,prompt1_3_1="��ǰ�γ��б�"
    ,prompt1_2="����γ�CID��ɾ���γ̣�"
    ,success1_2="ɾ���ɹ���"
    ,failed1_2="ɾ��ʧ�ܣ�����CID�Ƿ����..."
    ,prompt1_3_2_1="���������Բ��ҿγ̣�"
    ,prompt1_3_2_2="����CID�Բ��ҿγ̣�"
    ,success1_3_2_a="�ҵ���"
    ,success1_3_2_b="���γ�"
    ,prompt1_3_3="����CID���޸Ŀγ����ƺ�ѧ�֣�"
    ,prompt1_3_3_1="�����µĿγ����ơ�ѧ�֣�"
    ,success1_3_3="�޸ĳɹ���"

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
            navi(p,"���Զ�ģʽ��ӿγ�");
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
            navi(p,"���ֶ�ģʽ��ӿγ�");
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
        navi(p,"ɾ���γ�");
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
            navi(p,"�����Ʋ��ҿγ�");
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
            navi(p,"��CID���ҿγ�");
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
        navi(p,"�޸Ŀγ���Ϣ");
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
    cout << setw(15) <<left<< "�γ�CID" <<setw(15) <<left<< "�γ�����" << setw(15) <<left<< "�γ�ѧ��"<< endl;
}

string Course::getName() {
    return name;
}

string Course::getID() {
    return CID;
}

void Course::showFullTitleLong() {
    cout << setw(15) <<left<< "�γ�CID: " <<setw(15) <<left<< CID <<setw(15) <<left<< "�γ�����" <<setw(15) <<left<< name << endl;
//    cout << setw(15) <<left<< "��ѡ�γ�����: " <<setw(15) <<left<< course_counter <<setw(15) <<left<< "��ѡѧ��: " <<setw(15) <<left<< credit_counter << endl;
//    cout << setw(15) <<left<< "��Ȩ�ɼ�: " <<setw(15) <<left<< weightScore <<setw(15) <<left<< "������: " <<setw(15) <<left<< rank << endl;
}

void Course::fullInfLong() {
//    cout << setw(15) <<left<< "�γ�ID" <<setw(15) <<left<< CID <<setw(15) <<left<< "�γ�����" <<setw(15) <<left<< name << endl;
}

void Course::newName(string name) {
    this->name=name;
}

void Course::newCredit(float credit) {
    this->credit=credit;
}
