#ifndef PROJECTAED_G24_MENU_H
#define PROJECTAED_G24_MENU_H

#include <string>
using namespace std;

class Menu {

public:
    Menu();

private:
    void mainMenu();
    void SchedulePerStudent();
    void SchedulePerClass();
    void OcupationPerClass();
    void ClassMenu();
    string ConstruirATurma(int ano, int turma);

};

#endif //PROJECTAED_G24_MENU_H