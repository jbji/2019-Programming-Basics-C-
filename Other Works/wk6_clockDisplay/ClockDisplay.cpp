//
// Created by jbji on 20-3-25.
//

#include "ClockDisplay.h"

int ClockDisplay::start() {
    if(!minutes.increase()){
        hours.increase();
    }
}