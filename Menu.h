#ifndef PROJECTAED_G24_MENU_H
#define PROJECTAED_G24_MENU_H

#include <string>

class Menu {

public:
    Menu();

private:
    void mainMenu();
    void SchedulePerStudent();
    void SchedulePerClass();
    void OcupationPerClass();
    void ClassMenu();

    std::__cxx11::basic_string<char> ConstruirATurma(int ano, int turma);
};

#endif //PROJECTAED_G24_MENU_H