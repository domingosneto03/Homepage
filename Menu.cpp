#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;
Application app;

Menu::Menu() {
    app.readStudents();
    app.readUniclasses();
    mainMenu();
}

void Menu::mainMenu() {
    int option;
    cout << "=======================================" << endl;
    cout << "1 - Horario de estudante" << endl;
    cout << "2 - Horario de uma turma" << endl;
    cout << "2 - Menu das turmas" << endl;
    cout << "3 - Sair" << endl;
    cout << "=======================================" << endl;
    cout << "Escolha: ";
    cin >> option;

    if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
    cin.clear();

    switch (option) {
        case 1:
            SchedulePerStudent();
            break;
        case 2:
            SchedulePerClass();
            break;
        case 3:
            break;
    }
}

void Menu::SchedulePerStudent() {
    string option;
    cout << "Introduza o seu numero de estudante:"  << endl;
    cin >> option;
    string nome;
    vector<studentAndClass> studentAndClass = app.StudentSchedule(option);
    for (int i = 0; i < studentAndClass.size(); i++) {
        if (studentAndClass[i].studentCode == option){
            nome = studentAndClass[i].name;
            break;
        }
    }
    vector<string> weekdayNames = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<string> classTypeNames = {"T", "TP", "PL"};
    cout << "Horario de " << nome << ", up" << option << endl;
    for (int i = 0; i < studentAndClass.size(); i++) {
        int startHour = studentAndClass[i].startHour;
        double startMin = (studentAndClass[i].startHour - startHour)*60;
        int endHour = (studentAndClass[i].startHour + studentAndClass[i].duration);
        double endMin = (studentAndClass[i].startHour + studentAndClass[i].duration - endHour)*60;
        cout << "WeekDay: " << weekdayNames[studentAndClass[i].weekDay] << " | UcCode: " << studentAndClass[i].ucCode << " | ClassCode: " << studentAndClass[i].classCode << " | ClassType: " << classTypeNames[studentAndClass[i].classType] << " | Time: " << startHour << ":" << startMin<<"-"<<endHour<<":"<<endMin<< endl;
    }
}

void Menu::SchedulePerClass() {
    int ano;
    int turma;
    string turmaFinal;
    cout << "Introduza o ano curricular (1 a 3): "  << endl;
    cin >> ano;
    while(ano < 1 || ano > 3) {
        cout << "O ano introduzido e invalido! Introduza novamente: "  << endl;
        cin >> ano;
    }
    cout << "Introduza o numero da turma (1 a 16): "  << endl;
    cin >> turma;
    while(turma < 1 || turma > 16) {
        cout << "A turma introduzida e invalida! Introduza novamente: "  << endl;
        cin >> turma;
    }
    if (turma > 0 && turma < 9) {
        turmaFinal = to_string(ano) + "LEIC0" + to_string(turma);
    }
    else {
        turmaFinal = to_string(ano) + "LEIC" + to_string(turma);
    }

    vector <schedule> classesSchedule = app.ClassesSchedule(turmaFinal);
    cout << "A turma " << turmaFinal << " tem o seguinte horario:" << endl;
    for (int i = 0; i < classesSchedule.size(); i++) {
        cout << "ClassCode: " << classesSchedule[i].classCode << " | UcCode: " << classesSchedule[i].ucCode << endl; // << " | UC: " << UcsMap[classesSchedule[i].ucCode];
    }
}

#endif // PROJECT_AED_MENU_CPP