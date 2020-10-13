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
    void showall();//显示所有课
    void cousave(courses course,int n);
    static int couload(courses &courses);
};
void courses::add(){
    while(1) {
        cout << "请输入课程数量：";
        int n;
        cin >> n;
        for (int i = num, j = 1; i < num + n; i++, j++) {
            cout << "请输入第" << num + j << "个学科的ID、名称和学分:";
            writeID(i);
            writename(i);
            writecredits(i);
        }
        num += n;
        char c;
        cout<<"继续输入请按y否则按n";
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
        cout << "请输入课程ID";
        cin >> a;
        for (int i = 0; i < num; i++) {
            if (ID[i] == a) {
                for (int j = i + 1; j <= num; j++) {
                    ID[j - 1] = ID[j];
                    name[j - 1] = name[j];
                    credits[j-1]=credits[j];
                }
                cout << "删除成功"<<endl;
                num--;
                break;
            }
            if (i == num-1) {
                cout << "错误，未查询到改课程"<<endl;
            }
        }
        char c;
        cout<<"继续输入请按y否则按n";
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
        cout << "请输入需要修改课程的ID";
        string a;
        cin >> a;
        for (int i = 0; i < num||num==0; i++) {
            if (ID[i] == a) {
                cout << "请输入要修改的ID和名称";
                cin >> ID[i];
                cin >> name[i];
                cin >> credits[i];
                cout << "修改成功";
                break;
            }
            if (i == num-1||num==0) {
                cout << "错误，未查询到改课程";
                break;
            }
        }
        char c;
        cout<<"继续输入请按y否则按n";
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
    cout<<setw(10)<<"课程名称"<<"        "<<"课程ID"<<setw(10)<<endl;
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
    cout << "正在生成或导入课程库文件courses.csv"<<endl;
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
                strTemp = strTemp.replace(pos, 1, 1, ' ');  //将字符串中的','用空格代替
                pos = strTemp.find(',');
            }
            sStream << strTemp;  //将字符串导入的流中
            sStream >> courses.ID[i];
            sStream >> courses.name[i];
            sStream >> courses.credits[i];
//        ifile >> students.institute <<","<<students.getid(students,i)<<","<<students.getname(students,i)<<","<<students.getfinal(students,i)<<","<<endl;
        }
        cout << "成功！"<<endl;
        returnvalue=0;
    }else{
        cout << "失败！"<<endl;
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
    int num=0,h=0;;//第几个学生
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
    void search();//查人
    void change();//改信息
    void addcourses();//填课
    void weighting();//算加权
    void showweighting();//展示最终成绩
    void showcourses();//展示所有成绩
    void stusave(students students,int n);

    static int stuload(students &students);
};
void students::add(){
    cout<<"请输入学生的ID和姓名:";
    while(1){
        writeID(num);
        writename(num);
        cout<<num;
        num++;
        char c;
        cout<<"继续输入请按y否则按n";
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
        cout<<"请输入学生的ID:";
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
                cout<<"删除成功";
                break;
            }
            if(i==99){
                cout<<"错误，未查询到该学生";
            }
        }
        char c;
        cout<<"继续输入请按y否则按n";
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
        cout << "请输入学生的学号";
        string a;
        cin >> a;
        for (int i = 0; i < 99; i++) {
            if (ID[i]==a) {
                cout << ID[i] << "   " << name[i]<<endl;
                for(int h=0; h < num; h++){
                    cout<<"科目:"<<courses[i].getname(h)<<"   "<<"成绩:"<<courses[i].getscore(h)<<endl;
                }
                break;
            }
            if (i == 98) {
                cout << "错误，未查询到该学生";
            }
        }
        char c;
        cout<<"继续输入请按y否则按n";
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
        cout << "请输入学生的学号";
        string a;
        cin >> a;
        for (int i = 0; i < 99; i++) {
            if (ID[i] == a) {
                cout<<"请输入修改的ID和姓名";
                cin>>ID[i];
                cin>>name[i];
                break;
            }
            if (i == 99) {
                cout << "错误，未查询到该学生";
            }
        }
        char c;
        cout<<"继续输入请按y否则按n";
        cin>>c;
        if(c=='y'){
            continue;
        }
        else{
            break;
        }
    }
}
void students::weighting(){//第几个学生和课程数量
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
    cout<<"请输入学生的学号:";
    cin>>a;
    for(h=0; h <= num; h++){
        if(ID[h]==a){
            cout<<ID[h]<<"        "<<name[h]<<endl;
            break;
        }
        if(h == num){
            cout<<"输入错误,请重新输入"<<endl;
            cin>>a;
            h=0;
        }
    }
    int n;
    cout <<"请输入课程的数量";
    cin >> n;
    int i=0;
    for(i=0;i<20;i++){
        if(courses[h].getid(i)=="\0"){
            break;
        }
    }
    for (int e=i;e<i+n;e++) {//h第几个人e第几个课
        cout<<"请输入"<<"第"<<e+1<<"门课程的ID、名称、成绩和学分";
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
    cout << "正在生成或导入学生库文件students.csv"<<endl;
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
                strTemp = strTemp.replace(pos, 1, 1, ' ');  //将字符串中的','用空格代替
                pos = strTemp.find(',');
            }
            sStream << strTemp;  //将字符串导入的流中

            sStream >> students.institute;
            sStream >> students.ID[i];
            sStream >> students.name[i];
            sStream >> students.finalscore[i];
//        ifile >> students.institute <<","<<students.getid(students,i)<<","<<students.getname(students,i)<<","<<students.getfinal(students,i)<<","<<endl;
        }
        cout << "成功！"<<endl;
        returnvalue=0;
    }else{
        cout << "失败！"<<endl;
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
    cout << "      教务管理系统\n\n";
    cout << "      1.课程管理系统\n";
    cout << "      2.学生成绩管理系统\n";
    cout << "      3.清除所有信息退出系统\n";
    cout << "===============================\n";
    cout << "                               \n";
}
void showMenu1()
{
    cout << "                               \n";
    cout << "===============================\n";
    cout << "      学生成绩管理系统\n\n";
    cout << "      1.添加信息\n";//显示所有学生成绩
    cout << "      2.删除信息\n";
    cout << "      3.查询信息\n";
    cout << "      4.更换信息\n";
    cout << "      5.输入成绩\n";
    cout << "      6.加权成绩分析\n";
    cout << "      7.切换到课程管理系统\n";
    cout << "      8.保存信息\n";
    cout << "      9.切换学院\n";
    cout << "      0.退出系统\n";
    cout << "===============================\n";
    cout << "                               \n";
}
void showMenu2()
{
    cout << "                               \n";
    cout << "===============================\n";
    cout << "      课程管理系统\n\n";
    cout << "      1.添加课程\n";
    cout << "      2.删除课程\n";
    cout << "      3.更改课程\n";
    cout << "      4.显示所有课程\n";
    cout << "      5.保存课程\n";
    cout << "      6.切换到学生成绩管理系统\n";
    cout << "      7.切换学院\n";
    cout << "      0.退出系统\n";
    cout << "===============================\n";
    cout << "                               \n";
}
int main() {
    cout<<"请输入学院的数量"<<endl;
    int n;
    cin>>n;
    students student[n];
    for(int i=0;i<n;i++){
        cout<<"请输入第"<<i+1<<"个学院的名称"<<endl;
        student[i].writeintstitute();
    }
    courses courses[n];
    while(1) {
        now:
        int p;
        string order;
        cout<<"请输入想要操作的学院的名称"<<endl;
        cin>>order;
        for(int i=0;i<n;i++){
            if(student[i].getinstitute()==order){
                p=i;

                break;
            }
            if(i==n-1){
                cout<<"错误，请重新输入"<<endl;
                cin>>order;
            }
        }
        students::stuload(student[p]);
        courses::couload(courses[p]);
        showMenu();
        cout << endl;
        int choice;
        cout << "请输入操作对应的序号 : ";
        while (1) {
            cin >> choice;
            switch (choice) {
                case 1: {
                    while (1) {
                        here:
                        showMenu2();
                        cout << "请输入操作对应的序号 : ";
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
                                goto there;//去学生管理系统
                            case 7:
                                goto now;//重新选学院
                            case 0: {
                                return 0;
                            }
                            default:
                                cout << "\n输入序号有误！请输入正确的序号。" << endl;
                        }
                    }
                }
                case 2: {
                    there:
                    while (1) {
                        showMenu1();
                        cout << "请输入操作对应的序号 : ";
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
                                goto here;//返回到课程管理
                            case 8:
                                student[p].showweighting();
                                student[p].stusave(student[p], student[p].num);
                                break;
                            case 9:
                                goto now;//重新选学院
                            case 0: {
                                return 0;
                            }
                            default:
                                cout << "\n输入序号有误！请输入正确的序号。" << endl;
                        }
                    }
                }
                case 3:{
                    fileEmpty("students.csv");
                    fileEmpty("courses.csv");
                    return 0;
                }
                default:
                    cout << "\n输入序号有误！请输入正确的序号。" << endl;
            }
        }
    }
}
