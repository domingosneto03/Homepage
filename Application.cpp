#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Application.h"
#include "UniClass.h"
#include "Student.h"
#include <iterator>
#include <set>

using namespace std;

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

void Application() {

}

set<UniClass *> Application::readUniclasses() {
    set<UniClass *> uniClassSet;
    fstream fin_classes;
    fin_classes.open("../schedule/classes.csv", ios::in);
    vector<string> row;
    string line, word, temp;
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
    set<Student *> studentSet;
    fstream fin;
    fin.open("../schedule/students_classes.csv", ios::in);
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
        student = new Student(StudentCode, StudentName, Aula);
        studentSet.insert(student);
    }
    return studentSet;
}

vector<schedule> Application::readClassesPerStudent() {
    vector<schedule> classesPerStudent = {};
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
        classesPerStudent.push_back({ClassCode, UcCode});
    }
    return classesPerStudent;
}

//neste metodo criamos uma lista que junta tudo do primeiro e ultimo ficheiros
set<studentAndClass> Application::StudentClass() {
    if (studentsClassSet.size() > 0) {
        return studentsClassSet;
    }
    set<Student*> student = readStudents();
    set<UniClass*> uniClassSet = readUniclasses();
    set<studentAndClass> studentAndClasses;

    for (auto uniClassNew: uniClassSet) {
        for (auto studentNew: student) {
            for (vector<string> st_class: studentNew->getClasses()) {
                if (st_class[0] == uniClassNew->getUcCode() && st_class[1] == uniClassNew->getClassCode()) {
                    studentAndClasses.insert({studentNew->getStudentCode(), studentNew->getName(), uniClassNew->getClassCode(), uniClassNew->getUcCode(),
                    uniClassNew->getWeekDay(),uniClassNew->getClassType(), uniClassNew->getStartHour(), uniClassNew->getDuration()});
                }
            }
        }
    }

    studentsClassSet = studentAndClasses;
    return studentAndClasses;
}

string Application::StartDate(float startHourClass) {
    int startMin;
    int startHour;
    string horaInicio;
    if (startHourClass - int(startHourClass) == 0) {
        startHour = int(startHourClass);
        startMin = 00;
    } else {
        startHour = int(startHourClass);
        startMin = 30;
    }
    horaInicio = to_string(startHour) + "h:" + to_string(startMin) + "m";
    return horaInicio;
}

string Application::EndDate(float endHourClass) {
    int endMin;
    int endHour;
    string horaInicio;
    if (endHourClass - int(endHourClass) == 0) {
        endHour = int(endHourClass);
        endMin = 00;
    } else {
        endHour = int(endHourClass);
        endMin = 30;
    }
    horaInicio = to_string(endHour) + "h:" + to_string(endMin) + "m";
    return horaInicio;
}

//neste metodo criamos uma lista com os estudantes que tinham o up que o utilizador introduziu
set<studentAndClass> Application::StudentSchedule(string studentCode) {
    set<studentAndClass> studentAndClasses = StudentClass();
    set<studentAndClass> studentSchedule = {};
    for (auto studentAndClassesSet: studentAndClasses) {
        if (studentAndClassesSet.studentCode == studentCode) {
            studentSchedule.insert(studentAndClassesSet);
        }
    }
    return studentSchedule;
}


/*
//neste metodo criamos uma lista com os estudantes que tinham o up que o utilizador introduziu
vector<studentAndClass> Application::StudentSchedule(string studentCode) {
    vector<studentAndClass> studentAndClasses = StudentClass();
    vector<studentAndClass> studentSchedule = {};
    for (int i = 0; i < studentAndClasses.size(); i++) {
        if (studentAndClasses[i].studentCode == studentCode) {
            studentSchedule.push_back(studentAndClasses[i]);
        }
    }
    return studentSchedule;
}


vector<schedule> Application::ClassesSchedule(string classCode) {
    vector<schedule> classesPerStudentList = readClassesPerStudent();
    vector<schedule> classSchedule = {};

    for (int i = 0; i < classesPerStudentList.size(); i++) {
        if (classesPerStudentList[i].classCode == classCode) {
            classSchedule.push_back(classesPerStudentList[i]);
        }
    }
    return classSchedule;
}

 //este metodo é para dizer quantos alunos tem por turma mas nao funciona
vector <string> Application::StudentPerClass(string classCode) {
    vector<studentAndClass> studentAndClasses = StudentClass();
    vector<string> studentPerClass = {};

    for (int i = 0; i < studentAndClasses.size(); i++) {
        for (int j = 0; j < studentAndClasses.size(); j++) {
            if (studentAndClasses[i].classCode == classCode) {
                if(studentAndClasses[i].studentCode != studentAndClasses[j].studentCode){
                    studentPerClass.push_back(studentAndClasses[i].name);
                    break;
                }
            }
        }
    }
    return studentPerClass;
}
*/
