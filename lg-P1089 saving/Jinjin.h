//
// Created by jbji on 20-1-22.
//

#ifndef LG_P1089_SAVING_JINJIN_H
#define LG_P1089_SAVING_JINJIN_H


class Jinjin {
private:
    int balance;
    int currentMonth;
    int insfiMon;
    int momDpst;
public:
    Jinjin();
    ~Jinjin();
    int nextMonth();
    void getResult();
};


#endif //LG_P1089_SAVING_JINJIN_H
