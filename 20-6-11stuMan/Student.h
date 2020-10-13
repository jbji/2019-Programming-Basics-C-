//
// Created by jbji on 20-6-11.
//

#ifndef INC_20_6_11STUMAN_STUDENT_H
#define INC_20_6_11STUMAN_STUDENT_H

#include <map>
#include <string>
#include "Course.h"
#include "Score.h"


class Course;
using namespace std;
class Student {
private:
    string UID;
    string name;
    int course_counter;
    float credit_counter;
    float weightScore;
    int rank;
    bool isUpdated;
    Course * cos[300]; //connector;
public:
    Student(string UID="U202000000", string name="Unnamed Student"):UID(UID),name(name),
            weightScore(0),course_counter(0),credit_counter(0),rank(0),isUpdated(true){};
    void connect(Course *);
    void disconnect(Course *);
    string getName();
    string getID();

    void newName(string name);

    static void showBasicTitle();
    void basicInf();
    static void showFullTitleShort();
    void fullInfShort();
    void showFullTitleLong();
    void fullInfLong();

};



void addStu(map<string,Student> &ulib,int mode);
void delStu(map<string,Student> &ulib);
void showStu(map<string, Student> ulib);
void findStu(map<string,Student> &ulib,int mode);
void editStu(map<string,Student> &ulib);
void addCosToStu(map<string,Student> &ulib,map<string,Course> &clib);
void delCosFromStu(map<string,Student> &ulib,map<string,Course> &clib);

#endif //INC_20_6_11STUMAN_STUDENT_H
