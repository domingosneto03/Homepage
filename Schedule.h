
#ifndef PROJECTAED_G24_HORARIOS_H
#define PROJECTAED_G24_HORARIOS_H

#include <vector>
#include "UniClass.h"
using namespace std;

class Schedule {

public:
    Schedule(vector <UniClass> classes);
    bool addClass(UniClass classAdd);

private:
    vector <UniClass> classes;
};

#endif //PROJECTAED_G24_HORARIOS_H
