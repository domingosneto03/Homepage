
#include "Student.h"
#include <string>
using namespace std;

Student::Student(int studentCode, string name) {
    this->studentCode = studentCode;
    this->name = name;
    this->schedules = schedules;
}

bool Student::addSchedules(Schedule schedule) {
    //confirmar se o aluno já tem aulas a essa hora
    return false;
}

void Student::setName(string name) {
    this -> name = name;
}

void Student::setStudentCode(){
    this -> studentCode = studentCode;
}

int Student::getStudentCode()  {
    return this->studentCode;
}

string Student::getName() {
    return this->name;
}