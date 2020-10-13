//
// Created by jbji on 20-3-25.
//

#ifndef WK6_CLOCKDISPLAY_CLOCKDISPLAY_H
#define WK6_CLOCKDISPLAY_CLOCKDISPLAY_H

#include "NumberDisplay.h"

class ClockDisplay {
public:
    int start();
private:
    NumberDisplay hours;
    NumberDisplay minutes;
};


#endif //WK6_CLOCKDISPLAY_CLOCKDISPLAY_H
