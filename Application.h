#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H


#include "Student.h"
#include "UniClass.h"
#include <map>
#include <set>

struct studentAndClass {
    string studentCode;
    string name;
    string classCode;
    string ucCode;
    int weekDay;
    CLASS_TYPE classType;
    double startHour;
    double duration;

    friend bool operator<(studentAndClass a, studentAndClass b) {
        if (b.studentCode == a.studentCode) {
            if (b.name == a.name) {
                if (b.classCode == a.classCode) {
                    if (b.ucCode == a.ucCode) {
                        if (b.weekDay == a.weekDay) {
                            if (b.classType == a.classType) {
                                if (b.startHour == a.startHour) {
                                        return b.studentCode < a.studentCode;
                                } else {
                                    return b.startHour < a.startHour;
                                }
                            } else {
                                return b.classCode < a.classCode;
                            }
                        } else {
                            return b.weekDay < a.weekDay;
                        }
                    } else {
                        return b.ucCode < a.ucCode;
                    }
                } else {
                    return b.classCode < a.classCode;
                }
            } else {
                return b.name < a.name;
            }
        } else {
            return b.studentCode < a.studentCode;
        }
    }
};

struct schedule {
    string classCode;
    string ucCode;
};

class Application {
private:
    set<studentAndClass> studentsClassSet = {};
public:
    set<UniClass*> readUniclasses();
    set<Student*> readStudents();
    vector<schedule> readClassesPerStudent();
    set<studentAndClass> StudentClass();
    set<studentAndClass> StudentSchedule(string studentCode);
    string StartDate(float startHourClass);
    string EndDate(float endHourClass);
   /*   vector<studentAndClass> StudentSchedule(string studentCode);
      vector<schedule> ClassesSchedule(string classCode);
      vector<string> StudentPerClass(string classCode);
   */

};

#endif //PROJECTAED_G24_APPLICATION_H