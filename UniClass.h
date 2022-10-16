#ifndef PROJECTAED_G24_CLASS_H
#define PROJECTAED_G24_CLASS_H

enum CLASS_TYPE {
    T, TP, PL
};

class UniClass {



public:
    UniClass(int classCode, int ucCode, int weekDay, float startHour, float duration, CLASS_TYPE classType);
    int getClassCode() const;
    int getUcCode() const;
    int getWeekDay() const;
    float getStartHour() const;
    float getDuration() const;
    CLASS_TYPE getClassType() const;
    void setClassCode(int classCode);
    void setUcCode(int ucCode);
    void setWeekDay(int weekDay);
    void setStartHour(float startHour);
    void setDuration(float duration);
    void setClassType(CLASS_TYPE classType);

private:
    int CLASSCODE;
    int UCCODE;
    int WEEKDAY;
    float STARTHOUR;
    float DURATION;
    CLASS_TYPE CLASSTYPE;
};

#endif //PROJECTAED_G24_CLASS_H