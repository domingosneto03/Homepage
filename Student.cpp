//
// Created by InesO on 13/10/2022.
//

#include "Student.h"

Student::Student(int studentCode, string name, vector<Schedule>schedules) {
    this->studentCode = studentCode;
    this->name = name;
    this->schedules=schedules;
}

bool Student::addSchedules(Schedule schedule) {
    return false;
}