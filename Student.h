
#include <string>
#include <vector>
#include "Schedule.h"
using namespace std;

#ifndef PROJECTAED_G24_STUDENT_H
#define PROJECTAED_G24_STUDENT_H

class Student {

public:
        Student(int studentCode, string name);
        static bool addSchedules(Schedule schedule);
        void setName(string name);
        string getName();
        int getStudentCode();
        void setStudentCode();

private:
    int studentCode;
    string name;
    vector <Schedule>schedules={};


};

#endif //PROJECTAED_G24_STUDENT_H