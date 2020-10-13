//
// Created by jbji on 20-6-11.
//

#ifndef INC_20_6_11STUMAN_IO_H
#define INC_20_6_11STUMAN_IO_H


#include "Course.h"
#include "Student.h"
#include "Score.h"

#include <map>
#include <string>
#include <iostream>

using namespace std;

void mainMenu();

void cosMenu(int &p, map<string,Student> &ulib, map <string, Course> &clib);
void cosMenu_3(int &p, map<string,Student> &ulib, map<string,Course> &clib);
void stuMenu(int &p, map<string,Student> &ulib, map<string,Course> &clib);
void stuMenu_3(int &p, map<string,Student> &ulib, map<string,Course> &clib);
void scoMenu(int &p, map<string,Student> &ulib, map<string,Course> &clib);
void scoMenu_1(map<string,Student> &ulib, map<string,Course> &clib);


void saveAndExit(int &pointer,map<string,Student> &ulib,map<string,Course> &clib);

void defaultInput(int &pointer);
void exitOnly(int &pointer);
void clr();
void navi(int &p,string mode);
void navi(int &p);
void navi();

void spe();
#endif //INC_20_6_11STUMAN_IO_H
