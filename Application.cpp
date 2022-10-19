#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Application.h"
#include "UniClass.h"
#include "Student.h"

using namespace std;

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
    int teste = 0;
    teste++;
    return list;
}

//neste metodo criamos uma lista que junta tudo do primeiro e ultimo ficheiros
vector<studentAndClass> Application::StudentClass() {
    vector<Student> list = readStudents();
    vector<UniClass> uniClassList = readUniclasses();
    vector<studentAndClass> studentAndClasses = {};

    for (int i = 0; i < uniClassList.size(); ++i) {
        for (Student st: list) {
            vector<string> st_class = st.getClass();
            if (st_class[1] == uniClassList[i].getClassCode() && st_class[0] == uniClassList[i].getUcCode()) {
                studentAndClasses.push_back(
                        {st.getStudentCode(), st.getName(), uniClassList[i].getClassCode(), uniClassList[i].getUcCode(), uniClassList[i].getWeekDay(),
                         uniClassList[i].getClassType(),uniClassList[i].getStartHour(),uniClassList[i].getDuration()});
            }
        }
    }
    return studentAndClasses;
}

vector<studentAndClass> Application::StudentSchedule(string studentCode) {
    vector<studentAndClass> studentAndClasses = StudentClass();
    vector<studentAndClass> studentSchedule = {};
    for (int i = 0; i < studentAndClasses.size(); ++i) {
        if (studentAndClasses[i].studentCode == studentCode) {
            studentSchedule.push_back(studentAndClasses[i]);
        }
    }
    return studentSchedule;
}