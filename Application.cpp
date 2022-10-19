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

void Application::readUniclasses() {
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


        // Print the found data
        //cout << "ClassCode:" << classCode << " \n";
        //cout << "UcCode: " << UcCode << "\n";
        //cout << "WeekDay: " << Weekday << "\n";
        //cout << "StartHour: " << StartHour << "\n";
        //cout << "Duration: " << Duration << "\n";
        //cout << "ClassType: " << ClassType << "\n\n";
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

    //código para testar se guardou na lista
    for (int i = 0; i < uniClassList.size(); i++) {
        cout << uniClassList[i].getClassCode() << "\n";
    }
}

void Application::readStudents() {
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

    //código para testar se guardou na lista
    for (int i=0; i<list.size(); i++) {
        cout << list[i].getName() << "\n";
    }
}