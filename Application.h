#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H

#include "Student.h"
#include "UniClass.h"
#include "bst.h"
#include <map>
#include <set>
#include "bits/stdc++.h"

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

    friend bool operator<(schedule a, schedule b) {
        if (b.ucCode == a.ucCode) {
            if (b.classCode == a.classCode) {
            } else {
                return b.classCode < a.classCode;
            }
        } else {
            return b.ucCode < a.ucCode;
        }
    }
};

struct StudentUcs {
    string name;
    string studentCode;
    string count;

    friend bool operator<(StudentUcs a, StudentUcs b) {
        if (b.name == a.name) {
            if (b.studentCode == a.studentCode) {
                if (b.count == a.count) {
                } else {
                    return b.count < a.count;
                }
            } else {
                return b.studentCode < a.studentCode;
            }
        } else {
            return b.name > a.name;
        }
    }
};

class Application {

public:
    /**
    * Reads the file classes.csv and stores it in a set, using the UniClass constructor.
    * @return set<UniClass*>
    */
    set<UniClass*> readUniclasses();

    /**
    * Reads the file students_classes.csv and stores it in a set, using the Student constructor.
    * @return set<UniClass*>
    */
    set<Student*> readStudents();

    /**
    * Reads the file classes_per_uc.csv and stores it in a set, using the schedule struct.
    * @return set<UniClass*>
    */
    set<schedule> readClassesPerUC();

    /**
    * Joins the sets from the functions readUniclasses and readStudents into a single set, to join all the information about schedules and students.
    * @return set<studentAndClass>
    */
    set<studentAndClass> StudentClass();

    /**
    * Goes through the set of the function StudentClass and adds to a new set (without duplicates) the student's classes that the user entered.
    * @param studentCode
    * @return set<UniClass*>
    */
    set<studentAndClass> StudentSchedule(string studentCode);

    /**
    * Puts the time in the correct format (hh:mm).
    * @param hour
    * @return hourStart
    */
    string FormatDate(float hour);

    /**
    * Creates a set with all the lessons in a class, entered by the use.
    * @param classCode
    * @return set<UniClass*>
    */
    set<schedule> ClassesSchedule(string classCode);

    /**
    * Create a bst with all students and their number of Ucs
    * @return BST<StudentUcs>
    */
    BST<StudentUcs> StudentUC();

    /**
    * Creates a bst with all students of a certain year (1, 2 or 3).
    * @param ano
    * @return  BST<pair<string, string>>
    */
    BST<pair<string, string>> StudentNumbYear(int ano);

    /**
    * Creates a bst with all students enrolled in a given Uc.
    * @param uccode
    * @return BST<pair<string, string>>
    */
    BST<pair<string, string>> StudentNumbUc(string uccode);

    /**
    * Creates a bst with all students enrolled in a specific Uc in a specific class.
    * @param uccode
    * @param turmaFinal
    * @return set<UniClass*>
    */
    BST<pair<string, string>> StudentClassUc(string uccode, string turmaFinal);

    map<string, string> UcsMap = {{"L.EIC001", "ALGA"},
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


private:
    set<studentAndClass> studentsClassSet = {};
    set<UniClass *> uniClassSet = {};
    set<Student *> studentSet = {};
    set<schedule> classesPerUcSet = {};
    set<studentAndClass> studentSchedule = {};
    set<schedule> classSchedule = {};
};

#endif //PROJECTAED_G24_APPLICATION_H