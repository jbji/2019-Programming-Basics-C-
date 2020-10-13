#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
const int MAX_STUDENT_NUM=100;
const int MAX_COURSE_NUM=20;


class Student;

class Course{
public:
    int id; //课程id
    string name; //课程名称
    float credit; //学分

    Student * stu[MAX_STUDENT_NUM];
    float * score;

    void write(){//录入课程
        cout << "请依次输入课程ID，课程名称，该课程的学分:";
        cin >> id;
        cin >> name;
        cin >> credit;
//        cin >> score;
    }
//    void showall(int a){
//        for(int i=0; i <= MAX_COURSE_NUM; i++){
//            cout << name[i];
//        }
//    }
};

// 1 课程操作 1.1 添加课程 1.2 删除课程 1.3 显示可陈晓琯溪 2 学生操作 2.1 添加学生 2.2 删除学生 2.3 显示学生信息 2.4 学生信息修改 2.4.1 给学生添加课程 2.4.23 成绩分析
//INPUT FUNC: 1 INPUT BASIC STU DATA ; 2 INPUT COURSE SCORE; 2.1 INPUT SCORE OF EXSITED COURSE 2.2(OR MANY COURSES AND MANY SCORES, AND COURSES ARE SEPERATE FROM EACH OTHER)



/*
 * Student a;
 * a.inputRegularGrade(0);
 * courseId
 * Student <- course1, course2, course3, course4;
 *  Stu a -> 线代 数分 C语言 英语
 * Stu b - > 数分 C语言 线代
 * Stu c ->
 * 显示单一学生的分数细节 以及所有学生的分数加权排名
 * */


class Student
{
	public:
		void inputId();//输入学号
		void inputName();// 输入姓名
//        Course course[MAX_COURSE_NUM];
		void inputRegularGrade(Course);//输入平时成绩
		void inputFinaExam(Course);//输入期末考试成绩
		string getId();// 获得学号
		static void heading()//输出成绩标题
		{
			cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"平时"<<setw(10)<<"期末"<<endl;
		}
		void output();//输出成绩信息
		float Finalscore(Course);//计算总评成绩=平时*50%+期末*50%
	private:
		string id;//学号
		char name[20]; //姓名
		Course * course[MAX_COURSE_NUM];
};





void Student::inputId()
{
	cout<<"请输入学号:";
	cin>>id;
}
void Student::inputName()
{
	cin.ignore(80,'\n');
	cout<<"请输入姓名：";
	cin.getline(name,20);
}
void Student::inputRegularGrade(Course course)
{
	cout<<"请输入平时成绩（0-100之间）：";
	cin>>course.regularGrade;
	while(course.regularGrade<0||course.regularGrade>100)
    {
        cout<<"输入错误，成绩应该在0到100之间！"<<endl;
        cout<<"请输入平时成绩（0-100之间）：";
        cin>>course.regularGrade;
    }
}
void Student::inputFinaExam(Course course)
{
	cout<<"请输入期末考试成绩（0-100之间）：";
	cin>>course.finalExam;
	while(course.finalExam<0||course.finalExam>100)
    {
      	cout<<"输入错误，成绩应该在0到100之间！"<<endl;
      	cout<<"请输入期末考试成绩（0-100之间）：";
        cin>>course.finalExam;
    }
}
string Student::getId()
{
	return id;
}

void Student::output()
{
    Course course;
	cout<<setw(10)<<id<<setw(10)<<name<<setiosflags(ios::fixed)<< setprecision(1)<<setw(10)<<course.regularGrade<<setw(10)<<course.finalExam<<endl;
}//意图是输出原始数据

float Student::Finalscore(Course course)
{
	return course.regularGrade*0.5+course.finalExam*0.5;
}//需要修改








//录入或插入学生信息
void Input(Student stu[], int &num)
{
//	float score;//学生成绩
	int i=0; //人数
	string str;//用来判断是否继续输入的字符串
    Course course[20];
	if(num==0)
	{
		while(true)
		{
			stu[i].inputId();
			for(int j=0;j<num;j++)
			{
				if(stu[i].getId()==stu[j].getId())
				{
					cout<<"学号不允许重复，该学号已经存在！\n";
					stu[i].inputId();
				}
			}
			stu[i].inputName();
			for(int i=0; i < MAX_COURSE_NUM; i++) {
                course.writecourse(i);
                stu[i].inputRegularGrade(course);
                stu[i].inputFinaExam(course);
            }
			i++;
			num=i;
			cout<<"继续输入学生数据请按y或Y;否则按n或N";
			cin>>str;
			if(i==MAX_STUDENT_NUM)
			{
				cout<<"人数已达到"<<MAX_STUDENT_NUM<<"人上限，无法再输入！\n";
				break;
			}
			if(str=="y" || str=="Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	else //插入学生信息
	{
		if(num==MAX_STUDENT_NUM)
		{
			cout<<"人数已达到"<<MAX_STUDENT_NUM<<"人上限，无法再插入！\n";
		}
		else
		{
			i=num;//当前数组元素个数
			while(true)
			{
				stu[i].inputId();
				for(int j=0;j<num;j++)
				{
					if(stu[i].getId()==stu[j].getId())
					{
						cout<<"学号不允许重复，该学号已经存在！\n";
						stu[i].inputId();
					}
				}
				stu[i].inputName();
                for(int i=0; i < MAX_COURSE_NUM; i++) {
                    course.writecourse(i);
                    stu[i].inputRegularGrade(course);
                    stu[i].inputFinaExam(course);
                }
				i++;
				num=i;
				cout<<"继续输入学生数据请按y或Y：";
				cin>>str;
				if(i==MAX_STUDENT_NUM)
				{
					cout<<"人数已达到"<<MAX_STUDENT_NUM<<"人上限，无法再输入！\n";
					break;
				}
				if(str=="y" || str=="Y")
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
	}
}
//输出显示成绩信息
void Output(Student stu[], int num)
{
	if(num!=0)
	{
		stu[0].heading();//学生信息标题
		for(int i=0;i<num;i++)
		{
			stu[i].output();
		}
	}
	else
	{
		cout<<"暂无成绩信息，请选择1=录入学生信息"<<endl;
	}
}
//根据总评排序
void Order(Student stu[], int num)
{
	if(num!=0)
	{
		int i,j,k;
		Course course;
		Student temp;
		for(i=0;i<num;i++)
		{
			for(j=i;j<num;j++)
			{
				if(stu[i].Finalscore(course) < stu[j].Finalscore(course))
				{
					temp = stu[j];
					stu[j] = stu[i];
					stu[i] = temp;
				}
			}
		}
		stu[0].heading();//学生信息标题
		for(k=0;k<num;k++)
		{
			stu[k].output();
		}
		cout<<endl;
	}
	else
	{
		cout<<"暂无成绩信息，请选择1=录入学生信息"<<endl;
	}
}//需要修改

//查找学生信息
void Search(Student stu[], int num)
{
	string id;
	string str;//用来判断是否继续输入的字符串
	while(true) {
        cout << "请输入您要查找的学号：";
        cin >> id;
        int flag = 0;
        for (int i = 0; i < num; i++) {
            if (stu[i].getId()==id) {
                flag++;
            }
        }
        if (flag == 0) {
            cout << "没有该学号学生信息！" << endl;
        } else {
            stu[0].heading();//学生信息标题
            for (int i = 0; i < num; i++) {
                if (stu[i].getId() == id) {
                    stu[i].output();
                }
            }
        }
        cout << "继续查找请按y或Y：";
        cin >> str;
        if (str == "y" || str == "Y") {
            continue;
        } else {
            break;
        }
    }

}

void Delete(Student stu[], int &num)
{
	string id;
	string str;//用来判断是否继续输入的字符串
	while(true)
	{
		cout<<"请输入要删除学生的学号：";
		cin>>id;
		int flag=0;//用来统计删除后剩余的数组元素个数
		Student a[100];
        for(int i=0;i<num;i++)
        {
            if(stu[i].getId()!=id)
            {
                a[flag]=stu[i];
                flag++;
            }
        }
        if(flag==num)
        {
            cout<<"没有该学号学生！"<<endl;
        }
        else
        {
            num=flag;
            for(int k=0;k<num;k++)
            {
                stu[k]=a[k];
            }
            cout<<id<<"号学生信息删除成功！"<<endl;
        }
        cout<<"继续删除其他学生请按y或Y：";
        cin>>str;
        if(str=="y" || str=="Y")
        {
            continue;
        }
        else
        {
            break;
        }
	}
}

/*/统计人数
/void Statis(Student stu[], int num)
{
	int	i,a[5]={0};
	for(i=0;i<num;i++)
	{
		if(stu[i].Finalscore() >= 90 && stu[i].Finalscore() <= 100)
		{
			a[0] +=1;
		}
		else if(stu[i].Finalscore() >= 80 && stu[i].Finalscore() < 90)
		{
			a[1] +=1;
		}
		else if(stu[i].Finalscore() >= 70 && stu[i].Finalscore() < 80)
		{
			a[2] +=1;
		}
		else if(stu[i].Finalscore() >= 60 && stu[i].Finalscore() < 70)
		{
			a[3] +=1;
		}
		else
		{
			a[4] +=1;
		}
	}
	cout<<"     100~90    89~80    79~70    69~60     <60"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<setw(9)<<a[i];
	}
	cout<<endl;
}
*/
//主菜单
void Menu()
{
	cout<<"          =================================================\n";
	cout<<"          =              欢迎使用成绩管理系统             =\n";
	cout<<"          =           1=录入学生     2=显示信息           =\n";
	cout<<"          =           3=排序总评     4=查找学生           =\n";
	cout<<"          =           5=插入学生     6=删除学生           =\n";
	cout<<"          =           7=统计人数     0=退出               =\n";
	cout<<"          =================================================\n";
	cout<<"请选择:";
}

int main()
{
	int currentN=0;
	Student stu[MAX_STUDENT_NUM];
	/*从文件读数据 */
	ifstream filein("students.dat",ios::binary);
	if(filein)
	{
		filein.read((char*)&currentN,sizeof(currentN));
		for(int i=0;i<currentN;i++)
		{
			filein.read((char*)&stu[i],sizeof(stu[i]));
		}
	}
	filein.close();
	string a;//用来判断菜单选择,用string
	Menu();
	while(cin>>a)
	{
		if(a=="1")
		{
			cout<<"您选择了1=录入学生"<<endl;
			Input(stu, currentN);//输入
			Menu();
		}
		else if(a=="2")
		{
			cout<<"您选择了2=显示信息"<<endl;
			Output(stu, currentN);//输出成绩信息
			Menu();
		}
		else if(a=="3")
		{
			cout<<"您选择了3=排序总评"<<endl;
			Order(stu, currentN);
			Menu();
		}
		else if(a=="4")
		{
			cout<<"您选择了4=查找学生"<<endl;
			Search(stu, currentN);
			Menu();
		}
		else if(a=="5")
		{
			cout<<"您选择了5=插入学生"<<endl;
			Input(stu, currentN);
			Menu();
		}
		else if(a=="6")
		{
			cout<<"您选择了6=删除学生"<<endl;
			Delete(stu, currentN);
			Menu();
		}
		else if(a=="7")
		{
			cout<<"您选择了7=统计人数"<<endl;
			//Statis(stu, currentN);
			Menu();
		}
		else if(a=="0")
		{
			/*往文件写入数据*/
			ofstream fileout("students.dat",ios::binary);
			if(!fileout)
			{
				cout<<"文件不能被打开！"<<endl;
				return 0;
			}
			fileout.write((char*)&currentN,sizeof(currentN));
			for(int i=0;i<currentN;i++)
			{
				fileout.write((char*)&stu[i],sizeof(stu[i]));
			}
			fileout.close();
			cout<<"退出成功！"<<endl;
			return 0;
		}
		else
		{
			cout<<"输入非法，请重新输入！"<<endl;
			Menu();
		}
	}
	return 0;
}