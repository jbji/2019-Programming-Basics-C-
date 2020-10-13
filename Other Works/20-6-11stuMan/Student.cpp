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

string prompt2_1_1="�������������ѧ����"
        ,success2_1_1="ѧ����ӳɹ���������ӵ�ѧ��Ϊ��"
        ,prompt2_1_2="����ѧ��UID�����������ѧ�����Կո�ָ�����"
        ,failed2_1_2="���ʧ�ܣ�ѧ��UID�Ƿ�!\n����������ѧ��UID�����������ѧ��:"
        ,prompt2_3_1="��ǰѧ���б�"
        ,prompt2_2="����ѧ��UID��ɾ��ѧ����"
        ,success2_2="ɾ���ɹ���"
        ,failed2_2="ɾ��ʧ�ܣ�����UID�Ƿ����..."
        ,prompt2_3_2_1="���������Բ���ѧ����"
        ,prompt2_3_2_2="����UID�Բ���ѧ����"
        ,success2_3_2_a="�ҵ���"
        ,success2_3_2_b="��ѧ��"
        ,prompt2_3_3="����UID���޸�ѧ��������"
        ,prompt2_3_3_1="�����µ�ѧ��������"
        ,success2_3_3="�޸ĳɹ���"
        ,prompt2_3_4="�����ڳ���Ϊѧ����ӿγ̣�\n"
                     "����������ѧ����UID�����ſγ̵�CID(�Կո�ָ���0��β)��\n"
                     "ע������ѧ����ѡ��ĳ�γ̡���ĳ�γ̲����ڣ����Զ�����\n"
                     "���磺U2020123 C2020134 C2020216 C2020326 C2020128 0"
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
            navi(p,"���Զ�ģʽ���ѧ��");
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
            navi(p,"���ֶ�ģʽ���ѧ��");
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
        navi(p,"ɾ��ѧ��");
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
            navi(p,"����������ѧ��");
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
            navi(p,"��UID����ѧ��");
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
        navi(p,"�޸�ѧ����Ϣ");
    }
}
void addCosToStu(map<string,Student> &ulib,map<string,Course> &clib){
    for(int p=0;p!=-1;){
        clr();
        navi(p,"Ϊѧ����ӿγ�");
    }
}
void delCosFromStu(map<string,Student> &ulib,map<string,Course> &clib){

}

void Student::basicInf() {
    cout << setw(15) <<left<< UID <<setw(15) <<left<< name << endl;
}

void Student::showBasicTitle() {
    cout << setw(15) <<left<< "ѧ��UID" <<setw(15) <<left<< "ѧ������" << endl;
}

string Student::getName() {
    return name;
}

string Student::getID() {
    return UID;
}

void Student::showFullTitleLong() {
    cout << setw(15) <<left<< "ѧ��UID: " <<setw(15) <<left<< UID <<setw(15) <<left<< "ѧ������: " <<setw(15) <<left<< name << endl;
    cout << setw(15) <<left<< "��ѡ�γ�����: " <<setw(15) <<left<< course_counter <<setw(15) <<left<< "��ѡѧ��: " <<setw(15) <<left<< credit_counter << endl;
    cout << setw(15) <<left<< "��Ȩ�ɼ�: " <<setw(15) <<left<< weightScore <<setw(15) <<left<< "������: " <<setw(15) <<left<< rank << endl;
}

void Student::fullInfLong() {
    cout << setw(15) <<left<< "�γ�ID" <<setw(15) <<left<< UID <<setw(15) <<left<< "�γ�����" <<setw(15) <<left<< name << endl;
}

void Student::newName(string name) {
    this->name=name;
}
