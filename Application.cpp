#include <vector>
#include <string>
#include <iostream>
#include "Application.h"
#include "UniClass.h"
#include "Student.h"
#include "bst.h"
#include <iterator>
#include <set>

using namespace std;

void Application() {

}

set<UniClass *> Application::readUniclasses() {
    if (uniClassSet.size() > 0) {
        return uniClassSet;
    }
    fstream fin_classes;
    fin_classes.open("../schedule/classes.csv", ios::in);
    vector<string> row;
    string line, word;
    int count = 0;

    while (true) {
        row.clear();
        getline(fin_classes, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (count == 0) {
            count++;
            continue;
        }
        string classCode = row[0];
        string UcCode = row[1];
        string Weekday = row[2];
        string StartHour = row[3];
        string Duration = row[4];
        string ClassType = row[5];

        int weekday;

        if (row[2] == "Monday") {
            weekday = 1;
        } else if (row[2] == "Tuesday") {
            weekday = 2;
        } else if (row[2] == "Wednesday") {
            weekday = 3;
        } else if (row[2] == "Thursday") {
            weekday = 4;
        } else if (row[2] == "Friday") {
            weekday = 5;
        }
        UniClass *uniClass;
        uniClassSet.insert(new UniClass(classCode, UcCode, weekday, stod(StartHour), stod(Duration), ClassType));
    }

    return uniClassSet;
}

set<Student *> Application::readStudents() {
    if (studentSet.size() > 0) {
        return studentSet;
    }
    fstream fin;
    fin.open("../schedule/students_classes.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;
    int n = 0;
    //set<string> codes = {};
    while (true) {
        row.clear();
        getline(fin, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (count == 0) {
            count++;
            continue;
        }
        string StudentCode = row[0];
        string StudentName = row[1];
        string UcCode = row[2];
        string ClassCode = row[3];
        // For MacOS users!!!
        if (ClassCode[ClassCode.size() - 1] == '\r') {
            ClassCode.pop_back();
        }
        vector<string> Aula = {UcCode, ClassCode};

        Student *student;
        studentSet.insert(new Student(StudentCode, StudentName, Aula));
    }
    return studentSet;
}

set<schedule> Application::readClassesPerUC() {
    if (classesPerUcSet.size() > 0) {
        return classesPerUcSet;
    }
    fstream fin;
    fin.open("../schedule/classes_per_uc.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;
    int n = 0;
    while (true) {
        row.clear();
        getline(fin, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (count == 0) {
            count++;
            continue;
        }
        string UcCode = row[0];
        string ClassCode = row[1];

        schedule schedule;
        schedule.ucCode = UcCode;
        schedule.classCode = ClassCode;
        classesPerUcSet.insert(schedule);

    }
    return classesPerUcSet;
}

set<studentAndClass> Application::StudentClass() {
    if (studentsClassSet.size() > 0) {
        return studentsClassSet;
    }
    set<Student *> student = readStudents();
    set<UniClass *> uniClassSet = readUniclasses();
    set<studentAndClass> studentAndClasses;

    for (auto uniClassNew: uniClassSet) {
        for (auto studentNew: student) {
            for (vector<string> st_class: studentNew->getClasses()) {
                if (st_class[0] == uniClassNew->getUcCode() && st_class[1] == uniClassNew->getClassCode()) {
                    studentAndClasses.insert(
                            {studentNew->getStudentCode(), studentNew->getName(), uniClassNew->getClassCode(),
                             uniClassNew->getUcCode(), uniClassNew->getWeekDay(), uniClassNew->getClassType(),
                             uniClassNew->getStartHour(), uniClassNew->getDuration()});
                }
            }
        }
    }
    studentsClassSet = studentAndClasses;
    return studentAndClasses;
}

string Application::FormatDate(float hour) {
    int startMin;
    int startHour;
    string finalHour;
    if (hour - int(hour) == 0) {
        startHour = int(hour);
        startMin = 00;
    } else {
        startHour = int(hour);
        startMin = 30;
    }
    finalHour = to_string(startHour) + "h:" + to_string(startMin) + "m";
    return finalHour;
}

//neste metodo criamos uma lista com os estudantes que tinham o up que o utilizador introduziu
set<studentAndClass> Application::StudentSchedule(string studentCode) {
    if (studentSchedule.size() > 0) {
        return studentSchedule;
    }
    set<studentAndClass> studentAndClasses = StudentClass();
    set<studentAndClass> studentScheduleList = {};
    for (auto studentAndClassesSet: studentAndClasses) {
        if (studentAndClassesSet.studentCode == studentCode) {
            studentScheduleList.insert(studentAndClassesSet);
        }
    }
    studentSchedule=studentScheduleList;
    return studentSchedule;
}

set<ClassSchelude> Application::ClassesSchedule(string classCode) {
    if (classSchedule.size() > 0) {
        return classSchedule;
    }
    set<schedule> classesPerStudentSet = readClassesPerUC();
    set<studentAndClass> studentAndClasses = StudentClass();
    set<schedule> classScheduleAux = {};
    set<ClassSchelude> classScheduleList = {};

    for (auto newClassesPerStudentSet: classesPerStudentSet) {
        if (newClassesPerStudentSet.classCode == classCode) {
            classScheduleAux.insert(newClassesPerStudentSet);
        }
    }
    for (auto classesScheduleSet: classScheduleAux) {
        for (auto x: studentAndClasses) {
            if (classesScheduleSet.ucCode == x.ucCode && classesScheduleSet.classCode == x.classCode) {
                classScheduleList.insert({x.ucCode, x.weekDay, x.classType, x.startHour, x.duration});
            }
        }
    }
    classSchedule=classScheduleList;
    return classSchedule;
}

BST<StudentUcs> Application::StudentUC() {
    set<Student *> student = readStudents();
    BST<string> studentCount = BST<string>{""};
    StudentUcs studentUcsNull = {"", "", ""};
    BST<StudentUcs> studentUcBst = BST<StudentUcs>(studentUcsNull);

    for (auto nameStudent: student) {
        string name = nameStudent->getName();
        if (studentCount.find(name) != name) {
            studentCount.insert(name);
            int count = 0;
            for (auto compararName: student) {
                if (compararName->getName() == name) {
                    count++;
                }
            }
            StudentUcs studentUcs = {name, nameStudent->getStudentCode(), to_string(count)};
            studentUcBst.insert(studentUcs);
        }
    }
    return studentUcBst;
}

BST<pair<string, string>> Application::StudentNumbYear(int ano) {
    set<Student *> student = readStudents();
    BST<string> studentCount = BST<string>{""};
    pair<string, string> studentNull = {"", ""};
    BST<pair<string, string>> studentYearBst = BST<pair<string, string>>(studentNull);

    for (auto studentList: student) {
        for (vector<string> st_class: studentList->getClasses()) {
            if (st_class[1].at(0) - '0' == ano) {
                pair<string, string> studentYear = {studentList->getName(), studentList->getStudentCode()};
                studentYearBst.insert(studentYear);
            }
        }
    }
    return studentYearBst;
}

BST<pair<string, string>> Application::StudentNumbUc(string uccode) {
    set<Student *> student = readStudents();
    BST<string> studentCount = BST<string>{""};
    pair<string, string> studentNull = {"", ""};
    BST<pair<string, string>> studentUcBst = BST<pair<string, string>>(studentNull);

    for (auto studentList: student) {
        for (vector<string> st_class: studentList->getClasses()) {
            if (st_class[0] == uccode) {
                pair<string, string> studentUc = {studentList->getName(), studentList->getStudentCode()};
                studentUcBst.insert(studentUc);
            }
        }
    }

    return studentUcBst;
}

BST<pair<string, string>> Application::StudentClassUc(string uccode, string turmaFinal) {
    set<Student *> student = readStudents();
    BST<string> studentCount = BST<string>{""};
    pair<string, string> studentNull = {"", ""};
    BST<pair<string, string>> studentUcBst = BST<pair<string, string>>(studentNull);

    for (auto studentList: student) {
        for (vector<string> st_class: studentList->getClasses()) {
            if (st_class[0] == uccode && st_class[1] == turmaFinal) {
                pair<string, string> studentUc = {studentList->getName(), studentList->getStudentCode()};
                studentUcBst.insert(studentUc);
            }
        }
    }
    return studentUcBst;
}

void Application::RemoveClass(string studentCode, string ucCode) {
    if (studentsClassSet.size() == 0) {
        StudentClass();
    }
    for (auto it = studentsClassSet.begin(); it != studentsClassSet.end(); it++) {
        if (it->studentCode == studentCode && it->ucCode == ucCode) {
            studentsClassSet.erase(it);
        }
    }
}

string Application::StudentName(string studentCode) {
    for (auto x: studentsClassSet) {
        if (x.studentCode == studentCode) {
            return x.name;
        }
    }
    return "";
}

bool Application::Overlapping(int weekday, double startHour, double duration, CLASS_TYPE classtype) {
    vector<string> classTypeNames = {"T", "TP", "PL"};
    for (auto x: studentSchedule) {
        if (x.weekDay == weekday && (classTypeNames[x.classType]=="TP" || classTypeNames[x.classType]=="PL") && (classTypeNames[classtype]=="TP" || classTypeNames[classtype]=="PL")) {
            cout << "entrei no if" << endl;
            if (startHour + duration > x.startHour and startHour < x.startHour + duration) {
                return true;
            }
            if (x.startHour + x.duration > startHour and x.startHour < startHour + duration) {
                return true;
            }
        }
    }
    return false;
}

bool Application::AddClass(string studentCode, string ucCode, string classCode, int ocupation, int cap) {
    bool sair = false;
    int weekDay;
    double startHour;
    double duration;
    CLASS_TYPE classtype;
    for (auto x: studentsClassSet) {
        if (x.ucCode == ucCode && x.classCode == classCode) {
            weekDay = x.weekDay;
            classtype = x.classType;
            startHour = x.startHour;
            duration = x.duration;
            sair = true;
        }
        if (sair) break;
    }

    if (studentsClassSet.size() == 0) {
        StudentClass();
    }

    if (studentSchedule.size() == 0) {
        StudentSchedule(studentCode);
    }

    if (ocupation >= cap) {
        cout << "estou muito ocupado" << endl;
        return false;
    } else if (Overlapping(weekDay, startHour, duration, classtype)) {
        cout << "deu overlaping" << endl;
        return false;
    }
    cout << "vou adicionar" << endl;
    cout << studentsClassSet.size() << endl;
    string name = StudentName(studentCode);
    studentsClassSet.insert({studentCode, name, classCode, ucCode, weekDay, classtype, startHour, duration});
    cout << studentsClassSet.size() << endl;
    return true;
}

void Application::AddAddRequest(string studentCode, string ucCode, string classCode, int cap) {
    Request newRequest = Request();
    newRequest.type = ADD;
    newRequest.studentCode = studentCode;
    newRequest.ucCode = ucCode;
    newRequest.classCode = classCode;
    newRequest.cap= cap;
    requests.push(newRequest);
}

void Application::AddChangeRequest(string studentCode, string ucCode, string classCode, int cap) {
    Request newRequest = Request();
    newRequest.type = CHANGE;
    newRequest.studentCode = studentCode;
    newRequest.ucCode = ucCode;
    newRequest.classCode = classCode;
    newRequest.cap= cap;
    requests.push(newRequest);
}

void Application::AddRemoveRequest(string studentCode, string ucCode) {
    Request newRequest = Request();
    newRequest.type = REMOVE;
    newRequest.studentCode = studentCode;
    newRequest.ucCode = ucCode;
    requests.push(newRequest);
}

int Application::OcupationPerUcClass(string ucCode, string classCode) {
    BST<pair<string, string>> studentUc = StudentClassUc(ucCode, classCode);
    int count = 0;
    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        count++;
    }
    return count;
}

void Application::ResolveRequests() {
    while (requests.size()) {
        Request requestNew = requests.front();
        requests.pop();
        switch (requestNew.type) {
            case ADD: {
                int ocupation = OcupationPerUcClass(requestNew.ucCode, requestNew.classCode);
                if (!AddClass(requestNew.studentCode, requestNew.ucCode, requestNew.classCode, ocupation,
                              requestNew.cap));
                requestDenied.push_back(requestNew);
                break;
            }

            case REMOVE: {
                RemoveClass(requestNew.studentCode, requestNew.ucCode);
                break;
            }

            case CHANGE: {
                int ocupation = OcupationPerUcClass(requestNew.ucCode, requestNew.classCode);
                if (!AddClass(requestNew.studentCode, requestNew.ucCode, requestNew.classCode, ocupation,
                              requestNew.cap)) {
                    requestDenied.push_back(requestNew);
                } else {
                    RemoveClass(requestNew.studentCode, requestNew.ucCode);
                }
                break;
            }
        }
    }
}