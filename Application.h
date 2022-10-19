
#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H


#include "Student.h"
#include "UniClass.h"

class Application {
public:
    vector<UniClass> readUniclasses();
    vector<Student> readStudents();
    vector<string> StudentClass();
};


#endif //PROJECTAED_G24_APPLICATION_H
