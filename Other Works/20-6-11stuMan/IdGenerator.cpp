//
// Created by jbji on 20-6-12.
//

#include "IdGenerator.h"
#include "ctime"

string idGenerator(string prefix) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    srand((int)now);
    return prefix.append(to_string(1900+ltm->tm_year))
                 .append(to_string(ltm->tm_mon%10)).append(to_string(1000 + (int)9999 * rand() / (RAND_MAX + 1)));
}
