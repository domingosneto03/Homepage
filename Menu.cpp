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
    cout << "Escolha:";
    cin >> option;

    while (option < 1 || option > 4) {
        cout << "Erro, por favor tente novamente!" << endl;
        cout << "Escolha:";
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
    cout << "Introduza o seu numero de estudante:";
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
            cout << weekdayNames[studentAndClassSet.weekDay] << " -> " << studentAndClassSet.ucCode << ": "
                 << app.UcsMap[studentAndClassSet.ucCode] <<
                 " | " << studentAndClassSet.classCode << " | [ClassType] "
                 << classTypeNames[studentAndClassSet.classType] <<
                 " | " << app.FormatDate(startHour) << "-" << app.FormatDate(endHour) << endl;
        }
        string conti;
        cout << "Deseja ver mais algum horario? (y/n)" << endl;
        cin >> conti;
        if(conti == "n" || conti == "N") {
            mainMenu();
        } else if (conti == "Y" || conti == "y") {
            SchedulePerStudent();
        } else {
            cout << "A opcao nao e valida. Introduza novamente:" << endl;
            cin >> conti;
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
    cout << "3 - Inscritos num ano" << endl;
    cout << "4 - Ocupacao da turma" << endl;
    cout << "5 - Voltar ao menu principal" << endl;
    cout << "======================================" << endl;
    cout << "Escolha uma opcao:";
    cin >> option;
    switch (option) {
        case 1:
            SchedulePerClass();
            break;
        case 2:
            StudentNUcs();
            break;
        case 3:
            StudentYears();
            break;
        case 4:
            OcupationPerClass();
            break;
        case 5:
            mainMenu();
            break;
    }
}

string Menu::ConstruirATurma() {
    int ano;
    int turma;

    cout << "Introduza o ano curricular (1 a 3):" << endl;
    cin >> ano;
    while (ano < 1 || ano > 3) {
        cout << "O ano introduzido e invalido! Introduza novamente:" << endl;
        cin >> ano;
    }
    cout << "Introduza o numero da turma (1 a 16):" << endl;
    cin >> turma;
    while (turma < 1 || turma > 16) {
        cout << "A turma introduzida e invalida! Introduza novamente:" << endl;
        cin >> turma;
    }
    string turmaFinal;
    if (turma > 0 && turma < 9) {
        turmaFinal = to_string(ano) + "LEIC0" + to_string(turma);
    } else {
        turmaFinal = to_string(ano) + "LEIC" + to_string(turma);
    }
    return turmaFinal;
}

void Menu::SchedulePerClass() {
    string turmaFinal = ConstruirATurma();
    set<schedule> classesSchedule = app.ClassesSchedule(turmaFinal);
    cout << "A turma " << turmaFinal << " tem o seguinte horario:" << endl;
    for (auto classesScheduleSet: classesSchedule) {
        cout << "UcCode: " << classesScheduleSet.ucCode << " [" << app.UcsMap[classesScheduleSet.ucCode] << "]" << endl;
    }
    string conti;
    cout << "Deseja ver mais algum horario? (y/n)" << endl;
    cin >> conti;
    if(conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        SchedulePerClass();
    } else {
        cout << "A opcao nao e valida. Introduza novamente:" << endl;
        cin >> conti;
    }
}

void Menu::OcupationPerClass() {
    string turmaFinal = ConstruirATurma();
    string uccode;
    cout << "Indique o codigo da Uc (formato: L.EIC00X):";
    cin >> uccode;
    BST<pair<string, string>> studentUc = app.StudentClassUc(uccode, turmaFinal);
    int count = 0;
    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        cout << (*i).first << " [" << (*i).second << "]" << endl;
        count++;
    }
    cout << "Existem " << count << " estudantes inscritos em " << app.UcsMap[uccode] << " na turma " << turmaFinal << endl;
    string conti;
    cout << "Deseja ver mais alguma turma? (y/n)" << endl;
    cin >> conti;
    if(conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        OcupationPerClass();
    } else {
        cout << "A opcao nao e valida. Introduza novamente:" << endl;
        cin >> conti;
    }
}

void Menu::UcNumbers() {
    int n;
    cout << "Indique o numero de Ucs:";
    cin >> n;
    int count = 0;

    BST<StudentUcs> studentUc = app.StudentUC();

    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        if (stoi((*i).count) > n) {
            cout << (*i).name << " [" << (*i).studentCode << "]" << endl;
            count++;
        }
    }
    if (count != 0) {
        cout << "Existem " << count << " estudantes com mais de " << n << " UCs." << endl;
    } else {
        cout << "Nao existem estudantes com mais de " << n << " UCs." << endl;
    }

    string conti;
    cout << "Deseja ver mais algum numero de UCs? (y/n)" << endl;
    cin >> conti;
    if(conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        UcNumbers();
    } else {
        cout << "A opcao nao e valida. Introduza novamente:" << endl;
        cin >> conti;
    }
}

void Menu::StudentYears() {
    int ano;
    cout << "Indique o ano (de 1 a 3):";
    cin >> ano;
    while (ano < 1 || ano > 3) {
        cout << "O ano introduzido e invalido! Introduza novamente:" << endl;
        cin >> ano;
    }
    int count = 0;
    BST<pair<string, string>> studentYear = app.StudentNumbYear(ano);
    for (auto i = studentYear.begin(); i != studentYear.end(); i++) {
        cout << (*i).first << " [" << (*i).second << "]" << endl;
        count++;
    }
    cout << "Existem " << count << " estudantes inscritos no " << ano << " ano."<< endl;
    string conti;
    cout << "Deseja ver mais algum ano? (y/n)" << endl;
    cin >> conti;
    if(conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        StudentYears();
    } else {
        cout << "A opcao nao e valida. Introduza novamente:" << endl;
        cin >> conti;
    }
}

void Menu::StudentNUcs() {
    string uccode;
    cout << "Indique o codigo da Uc (formato: L.EIC0XX):";
    cin >> uccode;
    BST<pair<string, string>> studentUc = app.StudentNumbUc(uccode);
    int count = 0;
    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        cout << (*i).first << " [" << (*i).second << "]" << endl;
        count++;
    }
    cout << "Existem " << count << " estudantes inscritos em " << app.UcsMap[uccode] << endl;
    string conti;
    cout << "Deseja ver mais alguma UC? (y/n)" << endl;
    cin >> conti;
    if(conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        StudentNUcs();
    } else {
        cout << "A opcao nao e valida. Introduza novamente:" << endl;
        cin >> conti;
    }
}

#endif // PROJECT_AED_MENU_CPP