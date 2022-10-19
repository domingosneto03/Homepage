#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;

Menu::Menu() {
    Application app = Application();
    app.readUniclasses();
    app.readStudents();
    //mainMenu();
}

void Menu::mainMenu() {
    int option;
    cout << "=======================================" << endl;
    cout << "1 - Menu das faculdades" << endl;
    cout << "2 - Menu das turmas" << endl;
    cout << "3 - Sair" << endl;
    cout << "=======================================" << endl;
    cout << "Escolha: ";
    cin >> option;

    if (option < 1 || option > 3) cout << "Erro, por favor tente novamente!" << endl;
    cin.clear();

    switch (option) {
        case 1:
            FaculdadeMenu();
            break;
        case 2:
            TurmasMenu();
            break;
        case 3:
            break;
    }
}

void Menu::FaculdadeMenu() {
   cout << "entrou";
}

void Menu::TurmasMenu() {

}

#endif // PROJECT_AED_MENU_CPP