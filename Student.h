//
// Created by InesO on 13/10/2022.
//
#include <string>
#include <vector>
#include "Schedule.h"
using namespace std;

#ifndef PROJECTAED_G24_STUDENT_H
#define PROJECTAED_G24_STUDENT_H



class Student {

public:
        Student(int studentCode, string name, vector <Schedule> schedules);
        bool addSchedules(Schedule schedule);
private:
    int studentCode;
    string name;
    vector <Schedule>schedules;

};


#endif //PROJECTAED_G24_STUDENT_H