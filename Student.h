
#include <string>
#include <vector>
#include "Schedule.h"
using namespace std;

#ifndef PROJECTAED_G24_STUDENT_H
#define PROJECTAED_G24_STUDENT_H

class Student {

public:
        Student(string studentCode, string name,vector<string> Class);
        static bool addSchedules(Schedule schedule);
        void setName(string name);
        string getName();
        string getStudentCode();
        vector<vector<string>> getClasses();
        void setStudentCode();
        void addClass(vector<string> Class);

private:
    string studentCode;
    string name;
    vector <Schedule>schedules={};
    vector <vector<string>>classes={};


};

#endif //PROJECTAED_G24_STUDENT_H