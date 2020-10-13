//
// Created by jbji on 20-6-11.
//

#ifndef INC_20_6_11STUMAN_COURSE_H
#define INC_20_6_11STUMAN_COURSE_H

#include <map>
#include <string>

using namespace std;

class Student;
class Course {
private:
    string CID;
    string name;
    float credit;

    int student_counter;
    float aveScore;
    bool isUpdated;
    Student * stu[1000]; //connector;
public:
    Course(string CID="C202000000", string name="Unnamed Course", float credit=0):CID(CID),name(name),credit(credit),student_counter(0),aveScore(0),isUpdated(true){};
    void connect(Student *);
    void disconnect(Student *);
    string getName();
    string getID();

    void newName(string name);
    void newCredit(float credit);

    static void showBasicTitle();
    void basicInf();
    static void showFullTitleShort();
    void fullInfShort();
    void showFullTitleLong();
    void fullInfLong();

};


void addCos(map<string,Course> &clib,int mode);
void delCos(map<string,Course> &clib);
void showCos(map<string,Course> clib);
void findCos(map<string,Course> &clib,int mode);
void editCos(map<string,Course> &clib);
void addStuToCos(map<string,Student> &ulib,map<string,Course> &clib);
void delStuFromCos(map<string,Student> &ulib,map<string,Course> &clib);

#endif //INC_20_6_11STUMAN_COURSE_H
