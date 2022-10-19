
#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H


#include "Student.h"
#include "UniClass.h"
#include <map>

struct studentAndClass {
    string studentCode;
    string name;
    string classCode;
    string ucCode;
    int weekDay;
    CLASS_TYPE classType;
    double startHour;
    double duration;
};

class Application {
public:
    vector<UniClass> readUniclasses();
    vector<Student> readStudents();
    vector<studentAndClass> StudentClass();
    vector<studentAndClass> StudentSchedule(string studentCode);
};


#endif //PROJECTAED_G24_APPLICATION_H
