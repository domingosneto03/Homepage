#ifndef PROJECTAED_G24_CLASS_H
#define PROJECTAED_G24_CLASS_H

#include <string>
using namespace std;

enum CLASS_TYPE {
    T, TP, PL
};

class UniClass {



public:
    UniClass(string classCode, string ucCode, int weekDay, double startHour, double duration, string classType);
    string getClassCode() const;
    string getUcCode() const;
    int getWeekDay() const;
    double getStartHour() const;
    double getDuration() const;
    CLASS_TYPE getClassType() const;
    void setClassCode(string classCode);
    void setUcCode(string ucCode);
    void setWeekDay(int weekDay);
    void setStartHour(double startHour);
    void setDuration(double duration);
    void setClassType(CLASS_TYPE classType);

private:
    string CLASSCODE;
    string UCCODE;
    int WEEKDAY;
    float STARTHOUR;
    float DURATION;
    CLASS_TYPE CLASSTYPE;
};

#endif //PROJECTAED_G24_CLASS_H