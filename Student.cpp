#include "Student.h"
#include <string>
using namespace std;

Student::Student(string studentCode, string name,vector<string> Class) {
    this->studentCode = studentCode;
    this->name = name;
    classes.push_back(Class);
}

bool Student::addSchedules(Schedule schedule) {
    //confirmar se o aluno já tem aulas a essa hora
    return false;
}
void Student::addClass(vector<string> Class){
    classes.push_back(Class);
}
void Student::setName(string name) {
    this -> name = name;
}

void Student::setStudentCode(){
    this -> studentCode = studentCode;
}

string Student::getStudentCode()  {
    return this->studentCode;
}

string Student::getName() const{
    return this->name;
}

vector <vector<string>> Student::getClasses() const {
    return this->classes;
}

bool Student::operator<(const Student &s1) const {
    if (classes.size() == s1.getClasses().size()) return name < s1.getName();
    return classes.size() < s1.classes.size();
}

bool Student::operator>(const Student &s1) const {
    if (classes.size() == s1.getClasses().size()) return name > s1.getName();
    return classes.size() > s1.classes.size();
}

bool Student::operator==(const Student &s1) const{
    return (this->studentCode == s1.studentCode);
}