//
// Created by jbji on 20-6-11.
//


#include "IO.h"


using namespace std;

string titlein = "��ѡ�����������еĲ����������Ӧ���ֱ�ţ�����������ֵ��������һ���˵�����"
        ,title1 = " 1) �γ̹��� - ��ӡ�ɾ�����޸Ŀγ̡�"
            ,title1_1 = " 1)) ����ӿγ̡�"
                ,title1_1_1 = " 1))) ��ϣ���Զ����ɿγ�CID��"
                ,title1_1_2 = " 2))) ��ϣ���ֶ�����γ�CID��"
            ,title1_2 = " 2)) ��ɾ���γ̡�"
            ,title1_3 = " 3)) �γ���Ϣ��ѯ���޸ġ�"
                ,title1_3_1 = " 1))) ��ʾ���пγ̵Ļ�����Ϣ��"
                ,title1_3_2 = " 2))) ����ָ���γ���ϸ��Ϣ��"
                    ,title1_3_2_1 = " 1)))) ���γ����Ʋ��� - ģ�����ҡ�"
                    ,title1_3_2_2 = " 2)))) ���γ�CID���� - ������ʾ�γ�����ѧ�����γ̳ɼ�����ƽ���ɼ�"
                ,title1_3_3 = " 3))) �޸Ŀγ̻�����Ϣ�����γ�CID����"
                ,title1_3_4 = " 4))) Ϊ�γ����ѧ��"
                ,title1_3_5 = " 5))) Ϊ�γ�ɾ��ѧ��"
        ,title2=" 2) ѧ������ - ��ӡ�ɾ�����޸�ѧ����Ϣ��"
            ,title2_1 = " 1)) �����ѧ����"
                ,title2_1_1 = " 1))) ��ϣ���Զ�����ѧ��UID��"
                ,title2_1_2 = " 2))) ��ϣ���ֶ�����ѧ��UID��"
            ,title2_2 = " 2)) ��ɾ��ѧ����"
            ,title2_3 = " 3)) ѧ����Ϣ��ѯ���޸ġ�"
                ,title2_3_1 = " 1))) ��ʾ����ѧ���Ļ�����Ϣ��"
                ,title2_3_2 = " 2))) ����ָ��ѧ����ϸ��Ϣ��"
                    ,title2_3_2_1 = " 1)))) ���������� - ģ�����ҡ�"
                    ,title2_3_2_2 = " 2)))) ��ѧ��UID���� - ������ʾѧ����ѡ�γ̡���ѡѧ�֡��γ̳ɼ�����Ȩ�ɼ�"
                ,title2_3_3 = " 3))) �޸�ѧ��������Ϣ����ѧ��UID����"
                ,title2_3_4 = " 4))) Ϊѧ����ӿγ�"
                ,title2_3_5 = " 5))) Ϊѧ��ɾ���γ�"
        ,title3=" 3) �ɼ����� - ¼��ɼ���ɼ�����"
            ,title3_1 = " 1)) ¼��ɼ�"
                ,title3_1_1 = " 1))) ��[ָ��ѧ��]��[ָ���γ�]¼��"
                ,title3_1_2 = " 2))) ��[�γ�]¼��[����δ¼��ɼ���ѧ��]�ĳɼ�"
                ,title3_1_3 = " 2))) ��[ѧ��]¼��[����δ¼��ɼ��Ŀγ�]�ĳɼ�"
            ,title3_2 = " 2)) �γ̳ɼ�����"
            ,title3_3 = " 3)) ѧ�����˳ɼ�����"
            ,title3_4 = " 4)) ѧ���ɼ��������"
        ,title4=" 4) �������в������˳�"
        ,title5=" 5) �˳����������κβ���";
string sp="===================================";
string nl="\n";

void mainMenu(){
    cout << sp << nl
         << "��ӭʹ��ѧ���ɼ�����ϵͳ��" << nl
         << "�汾�� Alpha v0.5 by jbji" << nl
         << "! ǿ�ҽ������κ�����£�������0��������һ���˵�" << nl
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
    cout << "����Y����" << mode << "�����������ַ������ϼ��˵�...";
    char tmp;
    cin >> tmp;
    clr();
    if(tmp!='Y'&&tmp!='y'){
        defaultInput(p);
    }
}

void navi(int&p) {
    cout << "���������ַ������ϼ��˵�...";
    char tmp;
    cin >> tmp;
    clr();
    defaultInput(p);
}
void navi() {
    cout << "���������ַ������ϼ��˵�...";
    char tmp;
    cin >> tmp;
    clr();
}

void spe() {
    cout << sp << endl;
}


// loop��׼ģ��
//for(int p=0;p!=-1;){
//clr();
//navi(p,"Ϊѧ����ӿγ�");
//}