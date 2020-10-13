//
// Created by jbji on 20-4-17.
//

#ifndef EDUSCORESTATISTIC_STUDENT_H
#define EDUSCORESTATISTIC_STUDENT_H


class Student {
private:
    int NO;
    double scores[3];
    double ave;
    double sum;
public:
    Student();
    virtual ~Student();
    void NOOverwrite(int);
    void scoreOverwrite(int,double);
    int getNO();
    double getAverage();
    double getSum();
};


#endif //EDUSCORESTATISTIC_STUDENT_H
