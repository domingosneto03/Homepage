#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    Application app = Application();
    //app.readUniclasses();
    app.readStudents();
    //mainMenu();
}

void Menu::mainMenu() {
    int option;
    cout << "=======================================" << endl;
    cout << "1 - Horário de estudante" << endl;
    cout << "2 - Menu das turmas" << endl;
    cout << "3 - Sair" << endl;
    cout << "=======================================" << endl;
    cout << "Escolha: ";
    cin >> option;

    if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
    cin.clear();

    switch (option) {
        case 1:
            StudentSchedule();
            break;
        case 2:
            TurmasMenu();
            break;
        case 3:
            break;
    }
}

void Menu::StudentSchedule() {
    int option;
   cout << "Introduza o seu número de estudante";
   cin >> option;



}

void Menu::TurmasMenu() {

}

#endif // PROJECT_AED_MENU_CPP