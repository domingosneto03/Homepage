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
            TurmasMenu();
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
            nome== studentAndClass[i].name;
            break;
        }
    }
    cout << "Horario da " << nome << ", com up" << option << endl;
    for (int i = 0; i < studentAndClass.size(); i++) {
        cout << "WeekDay: " << studentAndClass[i].weekDay << " | UcCode: " << studentAndClass[i].ucCode << " | ClassCode: " << studentAndClass[i].classCode << " | ClassType: " << studentAndClass[i].classType << " | Duration: " << studentAndClass[i].duration << endl;
    }
}

void Menu::TurmasMenu() {

}

#endif // PROJECT_AED_MENU_CPP