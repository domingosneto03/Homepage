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
        if (b.weekDay == a.weekDay) {
            if (b.studentCode == a.studentCode) {
                if (b.name == a.name) {
                    if (b.classCode == a.classCode) {
                        if (b.ucCode == a.ucCode) {

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
        } else {
            return b.weekDay > a.weekDay;
        }
    }
};


struct schedule {
    string classCode;
    string ucCode;
};

class Application {
private:
    set <studentAndClass> studentsClassSet = {};
    set <UniClass*> uniClassSet = {};
    set <Student*> studentSet = {};
    //set <schedule> classesPerStudentSet = {};
public:
    set <UniClass*> readUniclasses();
    set <Student*> readStudents();
    //set <schedule> readClassesPerStudent();
    set <studentAndClass> StudentClass();
    set <studentAndClass> StudentSchedule(string studentCode);
    string StartDate(float startHourClass);
    string EndDate(float endHourClass);

    map <string, string> UcsMap = {{"L.EIC001", "ALGA"},
                                   {"L.EIC002", "AM I"},
                                   {"L.EIC003", "FP"},
                                   {"L.EIC004", "FSC"},
                                   {"L.EIC005", "MD"},
                                   {"L.EIC006", "AC"},
                                   {"L.EIC007", "AM II"},
                                   {"L.EIC008", "F I"},
                                   {"L.EIC009", "P"},
                                   {"L.EIC010", "TC"},
                                   {"L.EIC011", "AED"},
                                   {"L.EIC012", "BD"},
                                   {"L.EIC013", "F II"},
                                   {"L.EIC014", "LDTS"},
                                   {"L.EIC015", "SO"},
                                   {"L.EIC016", "DA"},
                                   {"L.EIC017", "ES"},
                                   {"L.EIC018", "LC"},
                                   {"L.EIC019", "LTW"},
                                   {"L.EIC020", "ME"},
                                   {"L.EIC021", "FSI"},
                                   {"L.EIC022", "IPC"},
                                   {"L.EIC023", "LBAW"},
                                   {"L.EIC024", "PFL"},
                                   {"L.EIC025", "RC"}};

    set<schedule> ClassesSchedule(string classCode);
};

#endif //PROJECTAED_G24_APPLICATION_H