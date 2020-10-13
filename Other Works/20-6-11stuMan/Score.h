//
// Created by jbji on 20-6-11.
//

#ifndef INC_20_6_11STUMAN_SCORE_H
#define INC_20_6_11STUMAN_SCORE_H

#include "IO.h"
#include <utility>

class Student;
class Course;

using namespace std;
//分数库

extern map<pair<Student,Course>,float> slib;

void addScoreOfStuAndCos(map<string,Student> &ulib,map<string,Course> &clib);
void addScoreOfCourse(map<string,Course> &clib);
void addScoreOfStudent(map<string,Student> &ulib);

void cosAna(map<string,Course> &clib);
void stuAna_Single(map<string,Student> &ulib);
void stuAna_All(map<string,Student> &ulib);

#endif //INC_20_6_11STUMAN_SCORE_H
