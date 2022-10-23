#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Application.h"
#include "UniClass.h"
#include "Student.h"

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

vector<UniClass> Application::readUniclasses() {
    vector<UniClass> uniClassList = {};
    fstream fin_classes;
    fin_classes.open("./schedule/classes.csv", ios::in);
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
        uniClassList.emplace_back(UniClass(classCode, UcCode, weekday, stod(StartHour), stod(Duration), ClassType));
    }
    return uniClassList;
}

vector<Student> Application::readStudents() {
    vector<Student> list = {};
    fstream fin;
    fin.open("./schedule/students_classes.csv", ios::in);
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
        vector<string> Aula = {UcCode, ClassCode};


        if (list.size() == 0) {
            list.push_back(Student(StudentCode, StudentName, Aula));
            n++;
        } else if (StudentCode == list[n - 1].getStudentCode()) {
            list[n - 1].addClass(Aula);
        } else {
            list.push_back(Student(StudentCode, StudentName, Aula));
            n++;
        }
    }
    return list;
}

vector<schedule> Application::readClassesPerStudent() {
    vector<schedule> classesPerStudent = {};
    fstream fin;
    fin.open("./schedule/classes_per_uc.csv", ios::in);
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
vector<studentAndClass> Application::StudentClass() {
    vector<Student> list = readStudents();
    vector<UniClass> uniClassList = readUniclasses();
    vector<studentAndClass> studentAndClasses = {};

    for (int i = 0; i < uniClassList.size(); ++i) {
        for (Student st: list) {
            for (vector<string> st_class: st.getClasses()) {
                if (st_class[0] == uniClassList[i].getUcCode() && st_class[1] == uniClassList[i].getClassCode()) {
                    studentAndClasses.push_back(
                            {st.getStudentCode(), st.getName(), uniClassList[i].getClassCode(),
                             uniClassList[i].getUcCode(), uniClassList[i].getWeekDay(),
                             uniClassList[i].getClassType(), uniClassList[i].getStartHour(),
                             uniClassList[i].getDuration()});
                }
            }
        }
    }
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

/* //este metodo é para dizer quantos alunos tem por turma mas nao funciona
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
