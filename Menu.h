#ifndef PROJECTAED_G24_MENU_H
#define PROJECTAED_G24_MENU_H

#include <string>
using namespace std;

class Menu {

public:
    Menu();

private:
    /**
    * Prints the initial options on the terminal.
    */
    void mainMenu();

    /**
    * Scrolls through the list of all students and prints the schedule of the student chosen by the user.
    */
    void SchedulePerStudent();

    /**
    * Prints the options about the class information that the user can choose.
    */
    void ClassMenu();

    /**
    * The user enters the year and class he/she wants and it is in the correct format (XLEICXX).
    * @return turmaFinal
    */
    string ConstruirATurma();

    /**
    * Prints the schedule of a class.
    */
    void SchedulePerClass();

    /**
    * Prints the name of all students enrolled in a WC in a specific class and the total number of students.
    */
    void OcupationPerClass();

    /**
    * Prints the name of all students enrolled in a UC and the total number of students.
    */
    void UcNumbers();

    /**
    * Prints the name of all the students enrolled in a year (1, 2 or 3) and the total number of students.
    */
    void StudentYears();

    /**
    * Prints the name of all the students enrolled with more than x Ucs and the total number.
    */
    void StudentNUcs();

    /**
    * Prints the options about the change requests that the user can choose.
    */
    void ChangeRequest();

    /**
    * Remove a class from a student.
    */
    void RemoveClass();

    /**
    * Add a class on a student.
    */
    void AddClass();
};

#endif //PROJECTAED_G24_MENU_H