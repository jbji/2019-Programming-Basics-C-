#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "howmuch.h"
#include "mysort.h"

#include <QMessageBox>
#include <QFileDialog>
//#include <QSqlQuery>
//#include <QSqlDatabase>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
#define DEliM '#'

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统 测试版");
    /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":/lib1/lib1/a.db");

    if(!db.open()){
        ui->workStation->setText("failure");
    }
    else{
        ui->workStation->setText("success");
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInsert_clicked()
{
    QString namestr = ui->nameOfStudent->text();
    string _namestr = namestr.toStdString();
    int num = ui->idOfStudent->text().toInt();
    double score = ui->scoreOfStudent->text().toDouble();
    if (namestr == NULL || num == 0 || ui->scoreOfStudent->text() == NULL) //插入信息的时候需要输入完整的信息
    {
        QMessageBox::warning(this, tr("Waring"),
                             tr("请输入完整信息！"),
                             QMessageBox::Yes);
    }
    else
    {
        /*
            QString str = QString("insert into student(num, name, score) values('%1', '%2', '%3')").arg(num).arg(namestr).arg(score);
            QSqlQuery query;
            query.exec(str); //执行插入操作
            */
        //BinaryToTxt("a.dat");

        //写入对象的数据成员
        bool repeat = false; //学号查重

        int i = howMuch("a.dat");
        ifstream filein0("a.dat", ios::in | ios::binary);
        string *_score = new string[i];
        string *_id = new string[i];
        string *_name = new string[i];

        int k = 0; //给数组赋值

        int tempID;
        stringstream tempSS;
        while (1)
        {
            string get_id_account = "null"; //防止溢出
            getline(filein0, get_id_account, DEliM);
            if (get_id_account == "") //判断是否溢出
            {
                break;
            }
            _name[k] = get_id_account;
            getline(filein0, _id[k], DEliM);
            getline(filein0, _score[k], DEliM);

            tempSS << _id[k];
            tempSS >> tempID;
            tempSS.clear();

            if (num == tempID)
            {
                //用于寻找重复学号
                repeat = true;
                break;
            }
            k++;
        }
        filein0.close();

        delete[] _score;
        delete[] _id;
        delete[] _name;

        if(repeat){
            QMessageBox::warning(this, tr("Waring"),
                                 tr("这个学号已经被占用！"),
                                 QMessageBox::Yes);

        }
        else{
            ofstream fileout("a.dat", ios::app | ios::binary); //打开文件
            if (!fileout)                                      //读取失败
            {
                fileout.close();
                ui->workStation->setText("failure"); //判断是否打开成功
            }
            else
            {
                ui->workStation->setText("success");
            }
            fileout << _namestr << DEliM
                    << num << DEliM
                    << score << DEliM;

            fileout.close();
            //TxtToBinary("a.dat");


            QMessageBox::warning(this, tr("Waring"),
                                 tr("插入成功！"),
                                 QMessageBox::Yes);
        }
        ui->nameOfStudent->clear();
        ui->idOfStudent->clear();
        ui->scoreOfStudent->clear();
        ui->sum->clear();
    }
}

void MainWindow::on_pushButtonDelete_clicked()
{
    QString name = ui->nameOfStudent->text(); //从行编辑框中获取需要删除的人名
    QString id = ui->idOfStudent->text();     //从行编辑框中获取需要删除的学号
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this, "警告", "是否要删除该学生信息？",
                                   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (result == QMessageBox::Yes)
    {
        if (name == NULL || id == NULL)
        {

            QMessageBox::warning(this, tr("Waring"),
                                 tr("请输入要删除的人的名字和学号！"),
                                 QMessageBox::Yes);
        }

        else
        {
            ifstream filein("a.dat", ios::app | ios::binary); //打开文件
            if (!filein)                                      //读取失败
            {
                filein.close();
                ui->workStation->setText("failure");
            }
            else
            {
                ui->workStation->setText("success");
            }
            string getName, getId, getScore;
            int i = 0;
            while (getline(filein, getName, DEliM) && getline(filein, getId, DEliM) && getline(filein, getScore, DEliM))
            {
                i++; //统计学生数目
            }

            filein.close();
            ifstream filein0("a.dat", ios::in | ios::binary);
            string *_score = new string[i];
            string *_id = new string[i];
            string *_name = new string[i];

            int k = 0; //给数组赋值
            int idWD;  //用于寻找要删除的那一组数据
            int tempID;
            stringstream tempSS;
            while (1)
            {
                string get_id_account = "null"; //防止溢出
                getline(filein0, get_id_account, DEliM);
                if (get_id_account == "") //判断是否溢出
                {
                    break;
                }
                _name[k] = get_id_account;
                getline(filein0, _id[k], DEliM);
                getline(filein0, _score[k], DEliM);

                tempSS << _id[k];
                tempSS >> tempID;
                tempSS.clear();

                if (tempID == id.toInt())
                { //用于寻找要删除的那一组数据，以学号为准，毕竟姓名会重复
                    idWD = k;
                }
                k++;
            }
            filein0.close();

            ofstream fileout("b.dat", ios::app | ios::binary); //打开文件
            if (!fileout)                                      //读取失败
            {
                fileout.close();
                ui->workStation->setText("failure"); //判断是否打开成功
            }
            else
            {
                ui->workStation->setText("success");
            }
            //写入对象的数据成员
            for (int j = 0; j < i; j++)
            {
                if (j != idWD)
                {
                    fileout << _name[j] << DEliM
                            << _id[j] << DEliM
                            << _score[j] << DEliM;
                }
            }

            fileout.close();
            remove("a.dat");
            rename("b.dat", "a.dat");

            delete[] _name;
            delete[] _id;
            delete[] _score;
        }
        ui->nameOfStudent->clear();
        ui->idOfStudent->clear();
        ui->scoreOfStudent->clear();
        ui->sum->clear();
    }
}

void MainWindow::on_pushButtonSearch_clicked()
{
    QString searchname = ui->nameOfStudent->text();

    if (searchname == NULL)
    {
        QMessageBox::warning(this, tr("Waring"),
                             tr("请输入要查询的同学的名字"),
                             QMessageBox::Yes);
    }
    else
    {
        //从数据库中查询是否有这么一个人
        /*QString str = QString("select *from student where name = '%1'").arg(searchname);
            QSqlQuery query;
            query.exec(str);

            QString name;
            int number;
            double score;

            while (query.next())
            {
                number = query.value(0).toInt();
                name = query.value(1).toString();
                score =  query.value(2).toDouble();
            }
*/
        //BinaryToTxt("a.dat");
        ifstream filein("a.dat", ios::app | ios::binary); //打开文件
        if (!filein)                                      //读取失败
        {
            filein.close();
            ui->workStation->setText("failure");
        }
        else
        {
            ui->workStation->setText("success");
        }
        string getName, getId, getScore;
        int i = 0;
        double sumOfScore = 0;
        int tempScore;
        stringstream tempSS;
        while (getline(filein, getName, DEliM) && getline(filein, getId, DEliM) && getline(filein, getScore, DEliM))
        {
            i++; //统计学生数目

            tempSS << getScore;
            tempSS >> tempScore;
            tempSS.clear();
            sumOfScore += tempScore; //用于求平均成绩
        }
        if (i)
        { //当学生数量不为0时展示平均成绩
            QString scoreOS = QString::number(sumOfScore / i);
            ui->aveScore->setText(scoreOS);
        }

        QString numOS = QString::number(i);
        ui->totalNumOfStudent->setText(numOS);
        filein.close();
        ifstream filein0("a.dat", ios::in | ios::binary);
        string *_score = new string[i];
        string *_id = new string[i];
        string *_name = new string[i];

        int k = 0; //给数组赋值
        while (1)
        {
            string get_id_account = "null"; //防止溢出
            getline(filein0, get_id_account, DEliM);
            if (get_id_account == "") //判断是否溢出
            {
                break;
            }
            _name[k] = get_id_account;
            getline(filein0, _id[k], DEliM);
            getline(filein0, _score[k], DEliM);

            k++;
        }
        filein0.close();
        //TxtToBinary("a.dat");

        string _sum = ""; //用于展示学生列表
        for (int j = 0; j < i; j++)
        {
            _sum.append(_name[j]);
            _sum.append("\t");
            _sum.append(_id[j]);
            _sum.append("\t");
            _sum.append(_score[j]);
            _sum.append("\n");
        }
        QString tempSum = QString::fromStdString(_sum);
        ui->sum->setText(tempSum);

        bool if_have = false;
        string temp = searchname.toStdString();
        for (int j = 0; j < i; j++)
        {
            if (_name[j] == temp)
            {
                QString temp2 = QString::fromStdString(_name[j]);
                QString temp3 = QString::fromStdString(_id[j]);
                QString temp4 = QString::fromStdString(_score[j]);

                ui->nameOfStudent->setText(temp2);
                ui->idOfStudent->setText(temp3);
                ui->scoreOfStudent->setText(temp4);
                QMessageBox::warning(this, tr("Waring"),
                                     tr("查找成功！"),
                                     QMessageBox::Yes);
                if_have = true;
                break;
            }
        }
        if (!if_have)
        {
            QMessageBox::warning(this, tr("Waring"),
                                 tr("没有这个人，请重新输入"),
                                 QMessageBox::Yes);
            ui->nameOfStudent->clear();
            ui->idOfStudent->clear();
            ui->scoreOfStudent->clear();
        }
        delete[] _name;
        delete[] _id;
        delete[] _score;
    }
}

void MainWindow::on_pushButtonUpdate_clicked()
{
    QString name = ui->nameOfStudent->text(); //从行编辑框中获取需要修改的人名
    QString id = ui->idOfStudent->text();     //从行编辑框中获取需要修改的人的学号
    QString score = ui->scoreOfStudent->text();
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this, "警告", "是否要修改该学生的成绩？",
                                   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (result == QMessageBox::Yes)
    {
        if (name == NULL || id == NULL || score == NULL)
        {

            QMessageBox::warning(this, tr("Waring"),
                                 tr("请完整输入最新的数据！"),
                                 QMessageBox::Yes);
        }

        else
        {
            ifstream filein("a.dat", ios::app | ios::binary); //打开文件
            if (!filein)                                      //读取失败
            {
                filein.close();
                ui->workStation->setText("failure");
            }
            else
            {
                ui->workStation->setText("success");
            }
            string getName, getId, getScore;
            int i = 0;
            while (getline(filein, getName, DEliM) && getline(filein, getId, DEliM) && getline(filein, getScore, DEliM))
            {
                i++; //统计学生数目
            }

            filein.close();
            ifstream filein0("a.dat", ios::in | ios::binary);
            string *_score = new string[i];
            string *_id = new string[i];
            string *_name = new string[i];

            int k = 0; //给数组赋值
            int idWD;  //用于寻找要删除的那一组数据
            int tempID;
            stringstream tempSS;
            while (1)
            {
                string get_id_account = "null"; //防止溢出
                getline(filein0, get_id_account, DEliM);
                if (get_id_account == "") //判断是否溢出
                {
                    break;
                }
                _name[k] = get_id_account;
                getline(filein0, _id[k], DEliM);
                getline(filein0, _score[k], DEliM);

                tempSS << _id[k];
                tempSS >> tempID;
                tempSS.clear();

                if (tempID == id.toInt())
                { //用于寻找要删除的那一组数据，以学号为准，毕竟姓名会重复
                    idWD = k;
                }
                k++;
            }
            filein0.close();

            ofstream fileout("b.dat", ios::app | ios::binary); //打开文件
            if (!fileout)                                      //读取失败
            {
                fileout.close();
                ui->workStation->setText("failure"); //判断是否打开成功
            }
            else
            {
                ui->workStation->setText("success");
            }
            //写入对象的数据成员
            for (int j = 0; j < i; j++)
            {
                if (j != idWD)
                {
                    fileout << _name[j] << DEliM
                            << _id[j] << DEliM
                            << _score[j] << DEliM;
                }
            }
            string temp1 = name.toStdString();
            string temp2 = id.toStdString();
            string temp3 = score.toStdString();
            fileout << temp1 << DEliM
                    << temp2 << DEliM
                    << temp3 << DEliM;

            fileout.close();
            remove("a.dat");
            rename("b.dat", "a.dat");

            delete[] _name;
            delete[] _id;
            delete[] _score;
        }
        ui->nameOfStudent->clear();
        ui->idOfStudent->clear();
        ui->scoreOfStudent->clear();
        ui->sum->clear();
    }
}

void MainWindow::on_action_Exit_triggered()
{
    qApp->quit();
}

void MainWindow::on_action_FileOut_triggered()
{
    ifstream filein("a.dat", ios::app | ios::binary); //打开文件
    if (!filein)                                      //读取失败
    {
        filein.close();
        ui->workStation->setText("failure");
    }
    else
    {
        ui->workStation->setText("success");
    }
    string getName, getId, getScore;
    int i = 0;
    while (getline(filein, getName, DEliM) && getline(filein, getId, DEliM) && getline(filein, getScore, DEliM))
    {
        i++; //统计学生数目
    }

    filein.close();


    ifstream filein0("a.dat", ios::in | ios::binary);


    string *_score = new string[i];
    string *_id = new string[i];
    string *_name = new string[i];
    int k = 0;
    while (1)
    {
        string get_id_account = "null"; //防止溢出
        getline(filein0, get_id_account, DEliM);
        if (get_id_account == "") //判断是否溢出
        {
            break;
        }
        _name[k] = get_id_account;
        getline(filein0, _id[k], DEliM);
        getline(filein0, _score[k], DEliM);


        k++;
    }
    filein0.close();

    QString fileName;
        fileName = QFileDialog::getSaveFileName(this,
            tr("Open Config"), "StudentInformation", tr("Text File (*.txt)"));

        if (!fileName.isNull())
        {
                         //fileName是文件名

            ofstream fileout(fileName.toStdString() , ios::app | ios::binary); //打开文件
            if (!fileout)                                      //读取失败
            {
                fileout.close();
                ui->workStation->setText("failure"); //判断是否打开成功
            }
            else
            {
                ui->workStation->setText("success");
            }
            //写入对象的数据成员
            fileout << "------------------学生信息汇总表-----------------" << "\n";
            for (int j = 0; j < i; j++)
            {

                    fileout << "| " << setw(10) << _name[j] << " |" << "\t"
                            << "| " << setw(10) << _id[j] << " |" << "\t"
                            << "| " << setw(10) << _score[j] << " |" << "\n";

            }
            fileout.close();



        }




    delete[] _name;
    delete[] _id;
    delete[] _score;

}

void MainWindow::on_asc_sort_byScore_clicked()//按照成绩升序
{
    int i = howMuch("a.dat");
    _student *stu = new _student[i];
    ifstream filein0("a.dat", ios::in | ios::binary);



    int k = 0;
    while (1)
    {
        string get_id_account = "null"; //防止溢出
        getline(filein0, get_id_account, DEliM);
        if (get_id_account == "") //判断是否溢出
        {
            break;
        }
        stu[k].Name = get_id_account;
        getline(filein0, stu[k].Num , DEliM);
        getline(filein0, stu[k].Score , DEliM);


        k++;
    }
    filein0.close();
    asc_sort_byScore(stu,i);
    string _sum = ""; //用于展示学生列表
    for (int j = 0; j < i; j++)
    {
        string rankOfStudent = to_string(j+1);
        _sum.append(rankOfStudent);
        _sum.append(("\t"));
        _sum.append(stu[j].Name);
        _sum.append("\t");
        _sum.append(stu[j].Num);
        _sum.append("\t");
        _sum.append(stu[j].Score);
        _sum.append("\n");
    }
    QString tempSum = QString::fromStdString(_sum);
    ui->sum->setText(tempSum);
    delete[] stu;
}

void MainWindow::on_desc_sort_byScore_clicked() //按照成绩降序
{
    int i = howMuch("a.dat");
    _student *stu = new _student[i];
    ifstream filein0("a.dat", ios::in | ios::binary);



    int k = 0;
    while (1)
    {
        string get_id_account = "null"; //防止溢出
        getline(filein0, get_id_account, DEliM);
        if (get_id_account == "") //判断是否溢出
        {
            break;
        }
        stu[k].Name = get_id_account;
        getline(filein0, stu[k].Num , DEliM);
        getline(filein0, stu[k].Score , DEliM);


        k++;
    }
    filein0.close();
    desc_sort_byScore(stu,i);
    string _sum = ""; //用于展示学生列表
    for (int j = 0; j < i; j++)
    {
        string rankOfStudent = to_string(j+1);
        _sum.append(rankOfStudent);
        _sum.append(("\t"));
        _sum.append(stu[j].Name);
        _sum.append("\t");
        _sum.append(stu[j].Num);
        _sum.append("\t");
        _sum.append(stu[j].Score);
        _sum.append("\n");
    }
    QString tempSum = QString::fromStdString(_sum);
    ui->sum->setText(tempSum);
    delete[] stu;
}

void MainWindow::on_asc_sort_byNum_clicked()//按照学号升序
{
    int i = howMuch("a.dat");
    _student *stu = new _student[i];
    ifstream filein0("a.dat", ios::in | ios::binary);



    int k = 0;
    while (1)
    {
        string get_id_account = "null"; //防止溢出
        getline(filein0, get_id_account, DEliM);
        if (get_id_account == "") //判断是否溢出
        {
            break;
        }
        stu[k].Name = get_id_account;
        getline(filein0, stu[k].Num , DEliM);
        getline(filein0, stu[k].Score , DEliM);


        k++;
    }
    filein0.close();
    asc_sort_byNum(stu,i);
    string _sum = ""; //用于展示学生列表
    for (int j = 0; j < i; j++)
    {
        string rankOfStudent = to_string(j+1);
        _sum.append(rankOfStudent);
        _sum.append(("\t"));
        _sum.append(stu[j].Name);
        _sum.append("\t");
        _sum.append(stu[j].Num);
        _sum.append("\t");
        _sum.append(stu[j].Score);
        _sum.append("\n");
    }
    QString tempSum = QString::fromStdString(_sum);
    ui->sum->setText(tempSum);
    delete[] stu;
}

void MainWindow::on_desc_sort_byNum_clicked()//按照学号降序
{
    int i = howMuch("a.dat");
    _student *stu = new _student[i];
    ifstream filein0("a.dat", ios::in | ios::binary);



    int k = 0;
    while (1)
    {
        string get_id_account = "null"; //防止溢出
        getline(filein0, get_id_account, DEliM);
        if (get_id_account == "") //判断是否溢出
        {
            break;
        }
        stu[k].Name = get_id_account;
        getline(filein0, stu[k].Num , DEliM);
        getline(filein0, stu[k].Score , DEliM);


        k++;
    }
    filein0.close();
    desc_sort_byNum(stu,i);
    string _sum = ""; //用于展示学生列表
    for (int j = 0; j < i; j++)
    {
        string rankOfStudent = to_string(j+1);
        _sum.append(rankOfStudent);
        _sum.append(("\t"));
        _sum.append(stu[j].Name);
        _sum.append("\t");
        _sum.append(stu[j].Num);
        _sum.append("\t");
        _sum.append(stu[j].Score);
        _sum.append("\n");
    }
    QString tempSum = QString::fromStdString(_sum);
    ui->sum->setText(tempSum);
    delete[] stu;
}
