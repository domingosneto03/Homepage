#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "Application.h"
#include "UniClass.h"

using namespace std;

void Application() {

}

void Application::readUniclasses() {
    vector<UniClass> list = {};
    fstream fin;
    fin.open("./schedule/classes.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;

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

        // Print the found data
        cout << "ClassCode:" << row[0] << " \n";
        cout << "UcCode: " << row[1] << "\n";
        cout << "WeekDay: " << row[2] << "\n";
        cout << "StartHour: " << row[3] << "\n";
        cout << "Duration: " << row[4] << "\n";
        cout << "ClassType: " << row[5] << "\n\n";
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
        list.emplace_back(row[0], row[1], weekday, stod(row[3]), stod(row[4]), row[5]);
    }
}