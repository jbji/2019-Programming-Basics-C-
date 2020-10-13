#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int GetTxtLine(const char*filename){
    FILE*fd;
    int count=0;
    if(fd=fopen(filename,"r")){
        while(!feof(fd)){
            if('\n'==fgetc(fd)){
                count++;
            }
        }
    }
    if(fd){
        fclose(fd);
    }
    return count;
}

class courses{
    string ID[20];
    string name[20];
    double credits[20];
    int num=0;
    double scores[20];
public:
    void writeID(int i){
        cin >> ID[i];
    }
    void writename(int i){
        cin>>name[i];
    }
    void writescores(int i){
        cin>>scores[i];
        cin>>credits[i];
    }
    void writecredits(int i) {
        cin >> credits[i];
    }
    double getcredit(int i){
        return credits[i];
    }
    double getscore(int i){
        return scores[i];
    }
    string getid(int i){
        return ID[i];
    }
    string getname(int i){
        return name[i];
    }
    int getnum(){
        return num;
    }
    void add();
    void del();
    void change();
    void showall();//��ʾ���п�
    void cousave(courses course,int n);
    static int couload(courses &courses);
};
void courses::add(){
    while(1) {
        cout << "������γ�������";
        int n;
        cin >> n;
        for (int i = num, j = 1; i < num + n; i++, j++) {
            cout << "�������" << num + j << "��ѧ�Ƶ�ID�����ƺ�ѧ��:";
            writeID(i);
            writename(i);
            writecredits(i);
        }
        num += n;
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void courses::del(){
    while(1) {
        string a;
        cout << "������γ�ID";
        cin >> a;
        for (int i = 0; i < num; i++) {
            if (ID[i] == a) {
                for (int j = i + 1; j <= num; j++) {
                    ID[j - 1] = ID[j];
                    name[j - 1] = name[j];
                    credits[j-1]=credits[j];
                }
                cout << "ɾ���ɹ�"<<endl;
                num--;
                break;
            }
            if (i == num-1) {
                cout << "����δ��ѯ���Ŀγ�"<<endl;
            }
        }
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void courses::change(){
    while(1) {
        cout << "��������Ҫ�޸Ŀγ̵�ID";
        string a;
        cin >> a;
        for (int i = 0; i < num||num==0; i++) {
            if (ID[i] == a) {
                cout << "������Ҫ�޸ĵ�ID������";
                cin >> ID[i];
                cin >> name[i];
                cin >> credits[i];
                cout << "�޸ĳɹ�";
                break;
            }
            if (i == num-1||num==0) {
                cout << "����δ��ѯ���Ŀγ�";
                break;
            }
        }
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void courses::showall(){
    cout<<setw(10)<<"�γ�����"<<"        "<<"�γ�ID"<<setw(10)<<endl;
    for(int i=0;i<num;i++){
        cout<<setw(10)<<name[i]<<"        "<<ID[i]<<setw(10)<<endl;
    }
}
void courses::cousave(courses course,int n){
    ofstream ofile("courses.csv",ios::app | ios::binary);
    ofile<<"ID"<<","<<"NAME"<<","<<"CREIDTS"<<endl;
    for(int i=0;i<num;i++){
        ofile<<course.getid(i)<<","<<course.getname(i)<<","<<course.getcredit(i)<<","<<endl;
    }
    ofile.close();
}

int courses::couload(courses &courses) {
    cout << "�������ɻ���γ̿��ļ�courses.csv"<<endl;
    int returnvalue=0;
    ifstream ifile("./courses.csv",ios::app | ios::binary);
//    ifile>>"INSTITUTE"<<","<<"ID"<<","<<"NAME"<<","<<"WEIGHTING"<<endl;
    if(ifile){
        string strTemp;
        ifile >> strTemp;
        for(int i=0;i<GetTxtLine("./courses.csv");i++){
            ifile >> strTemp;
            stringstream sStream;
            int pos = strTemp.find(',');
            while (pos != string::npos)
            {
                strTemp = strTemp.replace(pos, 1, 1, ' ');  //���ַ����е�','�ÿո����
                pos = strTemp.find(',');
            }
            sStream << strTemp;  //���ַ������������
            sStream >> courses.ID[i];
            sStream >> courses.name[i];
            sStream >> courses.credits[i];
//        ifile >> students.institute <<","<<students.getid(students,i)<<","<<students.getname(students,i)<<","<<students.getfinal(students,i)<<","<<endl;
        }
        cout << "�ɹ���"<<endl;
        returnvalue=0;
    }else{
        cout << "ʧ�ܣ�"<<endl;
        returnvalue=1;
    }
    ifile.close();
    return returnvalue;
}

class students{
    string ID[100];
    string name[100];
    double finalscore[100];
    string institute;
public:
    int num=0,h=0;;//�ڼ���ѧ��
    courses courses[100];
    void writeID(int i){
        cin >> ID[i];
    }
    void writename(int i){
        cin>>name[i];
    }
    void writeintstitute(){
        cin>>institute;
    }
    string getid(students students,int i){
        return students.ID[i];
    }
    string getname(students student,int i){
        return student.name[i];
    }
    double getfinal(students student,int i){
        return finalscore[i];
    }
    string getinstitute(){
        return institute;
    }
    void add();
    void del();
    void search();//����
    void change();//����Ϣ
    void addcourses();//���
    void weighting();//���Ȩ
    void showweighting();//չʾ���ճɼ�
    void showcourses();//չʾ���гɼ�
    void stusave(students students,int n);

    static int stuload(students &students);
};
void students::add(){
    cout<<"������ѧ����ID������:";
    while(1){
        writeID(num);
        writename(num);
        cout<<num;
        num++;
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void students::del(){
    while(1){
        cout<<"������ѧ����ID:";
        string a;
        cin>>a;
        for(int i=0;i<100;i++){
            if(ID[i]==a){
                for(int f=i+1; f <= num; f++){
                    ID[f-1]=ID[f];
                    name[f-1]=name[f];
                    courses[f-1]=courses[f];
                    finalscore[f-1]=finalscore[f];
                }
                num--;
                cout<<"ɾ���ɹ�";
                break;
            }
            if(i==99){
                cout<<"����δ��ѯ����ѧ��";
            }
        }
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void students::search(){
    while(1) {
        cout << "������ѧ����ѧ��";
        string a;
        cin >> a;
        for (int i = 0; i < 99; i++) {
            if (ID[i]==a) {
                cout << ID[i] << "   " << name[i]<<endl;
                for(int h=0; h < num; h++){
                    cout<<"��Ŀ:"<<courses[i].getname(h)<<"   "<<"�ɼ�:"<<courses[i].getscore(h)<<endl;
                }
                break;
            }
            if (i == 98) {
                cout << "����δ��ѯ����ѧ��";
            }
        }
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void students::change(){
    while(1) {
        cout << "������ѧ����ѧ��";
        string a;
        cin >> a;
        for (int i = 0; i < 99; i++) {
            if (ID[i] == a) {
                cout<<"�������޸ĵ�ID������";
                cin>>ID[i];
                cin>>name[i];
                break;
            }
            if (i == 99) {
                cout << "����δ��ѯ����ѧ��";
            }
        }
        char c;
        cout<<"���������밴y����n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void students::weighting(){//�ڼ���ѧ���Ϳγ�����
    for(int i=0; i < num; i++){
        double sumcredit=0;
        double a=0;
        int coursenum=0;
        for(coursenum=0;coursenum<20;coursenum++){
            if(courses[i].getid(coursenum)=="\0"){
                break;
            }
        }
        for(int h=0;h<=coursenum;h++) {
            sumcredit += courses[i].getcredit(h);
            a += courses[i].getscore(h) * courses[i].getcredit(h);
        }
        finalscore[i]=a/sumcredit;
    }
}
void students::addcourses() {
    string a;
    cout<<"������ѧ����ѧ��:";
    cin>>a;
    for(h=0; h <= num; h++){
        if(ID[h]==a){
            cout<<ID[h]<<"        "<<name[h]<<endl;
            break;
        }
        if(h == num){
            cout<<"�������,����������"<<endl;
            cin>>a;
            h=0;
        }
    }
    int n;
    cout <<"������γ̵�����";
    cin >> n;
    int i=0;
    for(i=0;i<20;i++){
        if(courses[h].getid(i)=="\0"){
            break;
        }
    }
    for (int e=i;e<i+n;e++) {//h�ڼ�����e�ڼ�����
        cout<<"������"<<"��"<<e+1<<"�ſγ̵�ID�����ơ��ɼ���ѧ��";
        courses[h].writeID(e);
        courses[h].writename(e);
        courses[h].writescores(e);
    }
}
void students::showweighting(){
    weighting();
    for(int i=0; i <= num; i++){
        for(int h=i+1; h <= num; h++){
            if(finalscore[i]<finalscore[h]){
                string temp,temp1;
                double temp2;
                temp=ID[i];ID[i]=ID[h];ID[h]=temp;
                temp1=name[i];name[i]=name[h];name[h]=temp1;
                temp2=finalscore[i];finalscore[i]=finalscore[h];finalscore[h]=temp2;
            }
        }
    }
    for(int i=0; i < num; i++){
        cout<<ID[i]<<"       "<<name[i]<<"        "<<finalscore[i]<<endl;
    }
}
void students::stusave(students students,int n){
    ofstream ofile("students.csv",ios::app | ios::binary);
    ofile<<"INSTITUTE"<<","<<"ID"<<","<<"NAME"<<","<<"WEIGHTING"<<endl;
    for(int i=0;i<n;i++){
        ofile<<students.getinstitute()<<","<<students.getid(students,i)<<","<<students.getname(students,i)<<","<<students.getfinal(students,i)<<","<<endl;
    }
    ofile.close();
}
int students::stuload(students &students){
    cout << "�������ɻ���ѧ�����ļ�students.csv"<<endl;
    int returnvalue=0;
    ifstream ifile("./students.csv",ios::app | ios::binary);
//    ifile>>"INSTITUTE"<<","<<"ID"<<","<<"NAME"<<","<<"WEIGHTING"<<endl;
    if(ifile){
        string strTemp;
        ifile >> strTemp;
        for(int i=0;i<GetTxtLine("./students.csv");i++){
            ifile >> strTemp;
            stringstream sStream;
            int pos = strTemp.find(',');
            while (pos != string::npos)
            {
                strTemp = strTemp.replace(pos, 1, 1, ' ');  //���ַ����е�','�ÿո����
                pos = strTemp.find(',');
            }
            sStream << strTemp;  //���ַ������������

            sStream >> students.institute;
            sStream >> students.ID[i];
            sStream >> students.name[i];
            sStream >> students.finalscore[i];
//        ifile >> students.institute <<","<<students.getid(students,i)<<","<<students.getname(students,i)<<","<<students.getfinal(students,i)<<","<<endl;
        }
        cout << "�ɹ���"<<endl;
        returnvalue=0;
    }else{
        cout << "ʧ�ܣ�"<<endl;
        returnvalue=1;
    }
    ifile.close();
    return returnvalue;
}
void fileEmpty(const string fileName)
{
    fstream file(fileName, ios::out);
}
void showMenu()
{
    cout << "                               \n";
    cout << "===============================\n";
    cout << "      �������ϵͳ\n\n";
    cout << "      1.�γ̹���ϵͳ\n";
    cout << "      2.ѧ���ɼ�����ϵͳ\n";
    cout << "      3.���������Ϣ�˳�ϵͳ\n";
    cout << "===============================\n";
    cout << "                               \n";
}
void showMenu1()
{
    cout << "                               \n";
    cout << "===============================\n";
    cout << "      ѧ���ɼ�����ϵͳ\n\n";
    cout << "      1.�����Ϣ\n";//��ʾ����ѧ���ɼ�
    cout << "      2.ɾ����Ϣ\n";
    cout << "      3.��ѯ��Ϣ\n";
    cout << "      4.������Ϣ\n";
    cout << "      5.����ɼ�\n";
    cout << "      6.��Ȩ�ɼ�����\n";
    cout << "      7.�л����γ̹���ϵͳ\n";
    cout << "      8.������Ϣ\n";
    cout << "      9.�л�ѧԺ\n";
    cout << "      0.�˳�ϵͳ\n";
    cout << "===============================\n";
    cout << "                               \n";
}
void showMenu2()
{
    cout << "                               \n";
    cout << "===============================\n";
    cout << "      �γ̹���ϵͳ\n\n";
    cout << "      1.��ӿγ�\n";
    cout << "      2.ɾ���γ�\n";
    cout << "      3.���Ŀγ�\n";
    cout << "      4.��ʾ���пγ�\n";
    cout << "      5.����γ�\n";
    cout << "      6.�л���ѧ���ɼ�����ϵͳ\n";
    cout << "      7.�л�ѧԺ\n";
    cout << "      0.�˳�ϵͳ\n";
    cout << "===============================\n";
    cout << "                               \n";
}
int main() {
    cout<<"������ѧԺ������"<<endl;
    int n;
    cin>>n;
    students student[n];
    for(int i=0;i<n;i++){
        cout<<"�������"<<i+1<<"��ѧԺ������"<<endl;
        student[i].writeintstitute();
    }
    courses courses[n];
    while(1) {
        now:
        int p;
        string order;
        cout<<"��������Ҫ������ѧԺ������"<<endl;
        cin>>order;
        for(int i=0;i<n;i++){
            if(student[i].getinstitute()==order){
                p=i;

                break;
            }
            if(i==n-1){
                cout<<"��������������"<<endl;
                cin>>order;
            }
        }
        students::stuload(student[p]);
        courses::couload(courses[p]);
        showMenu();
        cout << endl;
        int choice;
        cout << "�����������Ӧ����� : ";
        while (1) {
            cin >> choice;
            switch (choice) {
                case 1: {
                    while (1) {
                        here:
                        showMenu2();
                        cout << "�����������Ӧ����� : ";
                        int h;
                        cin >> h;
                        switch (h) {
                            case 1:
                                courses[p].add();
                                break;
                            case 2:
                                courses[p].del();
                                break;
                            case 3:
                                courses[p].change();
                                break;
                            case 4:
                                courses[p].showall();
                                break;
                            case 5:
                                courses[p].cousave(courses[p], courses[p].getnum());
                                break;
                            case 6:
                                goto there;//ȥѧ������ϵͳ
                            case 7:
                                goto now;//����ѡѧԺ
                            case 0: {
                                return 0;
                            }
                            default:
                                cout << "\n�������������������ȷ����š�" << endl;
                        }
                    }
                }
                case 2: {
                    there:
                    while (1) {
                        showMenu1();
                        cout << "�����������Ӧ����� : ";
                        int h;
                        cin >> h;
                        switch (h) {
                            case 1:
                                student[p].add();
                                break;
                            case 2:
                                student[p].del();
                                break;
                            case 3:
                                student[p].search();
                                break;
                            case 4:
                                student[p].change();
                                break;
                            case 5:
                                student[p].addcourses();
                                break;
                            case 6:
                                student[p].showweighting();
                                break;
                            case 7:
                                goto here;//���ص��γ̹���
                            case 8:
                                student[p].showweighting();
                                student[p].stusave(student[p], student[p].num);
                                break;
                            case 9:
                                goto now;//����ѡѧԺ
                            case 0: {
                                return 0;
                            }
                            default:
                                cout << "\n�������������������ȷ����š�" << endl;
                        }
                    }
                }
                case 3:{
                    fileEmpty("students.csv");
                    fileEmpty("courses.csv");
                    return 0;
                }
                default:
                    cout << "\n�������������������ȷ����š�" << endl;
            }
        }
    }
}
