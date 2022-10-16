#include "UniClass.h"
#include <string>
using namespace std;

UniClass::UniClass(int classCode, int ucCode, int weekDay, float startHour, float duration, CLASS_TYPE classType) : CLASSCODE(classCode), UCCODE(ucCode), WEEKDAY(weekDay), STARTHOUR(startHour), DURATION(duration), CLASSTYPE(classType) {}

int UniClass::getClassCode() const{
    return CLASSCODE;
}

int UniClass::getUcCode() const{
    return UCCODE;
}

int UniClass::getWeekDay() const {
    return WEEKDAY;
}

float UniClass::getStartHour() const {
    return STARTHOUR;
}

float UniClass::getDuration() const {
    return DURATION;
}

CLASS_TYPE UniClass::getClassType() const {
    return CLASSTYPE;
}

void UniClass::setClassCode(int classCode) {
    this -> CLASSCODE = classCode;
}

void UniClass::setUcCode(int ucCode) {
    this -> UCCODE = ucCode;
}

void UniClass::setWeekDay(int weekDay) {
    this -> WEEKDAY = weekDay;
}

void UniClass::setStartHour(float startHour) {
    this-> STARTHOUR = startHour;
}

void UniClass::setDuration(float duration) {
    this -> DURATION = duration;
}

void UniClass::setClassType(CLASS_TYPE classType) {
    this -> CLASSTYPE = classType;
}

