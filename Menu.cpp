#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;
Application app;

Menu::Menu() {
    mainMenu();
}

void Menu::mainMenu() {
    int option;
    cout << "===============MAIN MENU===============" << endl;
    cout << "1 - Horario de estudante" << endl;
    cout << "2 - Menu das turmas" << endl;
    cout << "3 - Estudantes com mais de n UCs" << endl;
    cout << "4 - Sair" << endl;
    cout << "=======================================" << endl;
    cout << "Escolha: ";
    cin >> option;

    while (option < 1 || option > 4) {
        cout << "Erro, por favor tente novamente!" << endl;
        cout << "Escolha: ";
        cin >> option;
    }

    switch (option) {
        case 1:
            SchedulePerStudent();
            break;
        case 2:
            ClassMenu();
            break;
        case 3:
            UcNumbers();
            break;
        case 4:
            exit(-1);
    }
}


void Menu::SchedulePerStudent() {
    string option;
    cout << "Introduza o seu numero de estudante:" << endl;
    cin >> option;
    string nome;
    set<studentAndClass> studentAndClass = app.StudentSchedule(option);
    for (auto studentAndClassSet: studentAndClass) {
        if (studentAndClassSet.studentCode == option) {
            nome = studentAndClassSet.name;
            break;
        }
    }

    vector<string> weekdayNames = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<string> classTypeNames = {"T", "TP", "PL"};

    if (studentAndClass.size() != 0) {
        cout << "Horario de " << nome << ", up" << option << endl;
        for (auto studentAndClassSet: studentAndClass) {
            float startHour = studentAndClassSet.startHour;
            float endHour = (studentAndClassSet.startHour + studentAndClassSet.duration);
            cout << weekdayNames[studentAndClassSet.weekDay] << " -> " << studentAndClassSet.ucCode << ": " << app.UcsMap[studentAndClassSet.ucCode] <<
                 " | " << studentAndClassSet.classCode << " | [ClassType] " << classTypeNames[studentAndClassSet.classType] <<
                 " | " << app.StartDate(startHour) << "-" << app.EndDate(endHour) << endl;
        }
    } else {
        cout << "O numero que introduziu nao e valido!" << endl;
        SchedulePerStudent();
    }
}

void Menu::ClassMenu() {
    int option;
    cout << "==============CLASS MENU==============" << endl;
    cout << "1 - Horario da turma" << endl;
    cout << "2 - Inscritos numa UC" << endl;
    cout << "3 - Ocupacao da turma" << endl;
    cout << "4 - Voltar ao menu principal" << endl;
    cout << "======================================" << endl;
    cout << "Escolha uma opcao: ";
    cin >> option;
    switch (option) {
        case 1:
            SchedulePerClass();
            break;
        case 2:
            break;
        case 3:
            OcupationPerClass();
            break;
        case 4:
            mainMenu();
            break;
    }
}


string Menu::ConstruirATurma(int ano, int turma) {
    string turmaFinal;

    if (turma > 0 && turma < 9) {
        turmaFinal = to_string(ano) + "LEIC0" + to_string(turma);
    } else {
        turmaFinal = to_string(ano) + "LEIC" + to_string(turma);
    }
    return turmaFinal;
}

void Menu::SchedulePerClass() {
    int ano;
    int turma;

    cout << "Introduza o ano curricular (1 a 3): " << endl;
    cin >> ano;
    while (ano < 1 || ano > 3) {
        cout << "O ano introduzido e invalido! Introduza novamente: " << endl;
        cin >> ano;
    }
    cout << "Introduza o numero da turma (1 a 16): " << endl;
    cin >> turma;
    while (turma < 1 || turma > 16) {
        cout << "A turma introduzida e invalida! Introduza novamente: " << endl;
        cin >> turma;
    }
    string turmaFinal = ConstruirATurma(ano, turma);


    set<schedule> classesSchedule = app.ClassesSchedule(turmaFinal);
    cout << "A turma " << turmaFinal << " tem o seguinte horario:" << endl;
    for (auto classesScheduleSet: classesSchedule) {
        cout << "UcCode: " << classesScheduleSet.ucCode << " [" << app.UcsMap[classesScheduleSet.ucCode] << "]" << endl;
    }

}

void Menu::OcupationPerClass() {
    int ano;
    int turma;
    cout << "Introduza o ano curricular (1 a 3): " << endl;
    cin >> ano;
    while (ano < 1 || ano > 3) {
        cout << "O ano introduzido e invalido! Introduza novamente: " << endl;
        cin >> ano;
    }
    cout << "Introduza o numero da turma (1 a 16): " << endl;
    cin >> turma;
    while (turma < 1 || turma > 16) {
        cout << "A turma introduzida e invalida! Introduza novamente: " << endl;
        cin >> turma;
    }
    string turmaFinal = ConstruirATurma(ano, turma);
}

void Menu::UcNumbers() {
    int n;
    cout << "Indique o numero de Ucs: ";
    cin >> n;
    int count=0;

    BST<StudentUcs> studentUc = app.StudentUC();

    for(auto i=studentUc.begin(); i!=studentUc.end() ; i++) {
        if (stoi((*i).count) > n) {
            cout << (*i).name << " [" << (*i).studentCode << "]" << endl;
            count++;
        }
    }
    if(count!=0){
        cout << "Existem " << count << " estudantes com mais de " << n << " UCs." << endl;
    } else {
        cout << "Nao existem estudantes com mais de " << n << " UCs." << endl;
    }
}

#endif // PROJECT_AED_MENU_CPP