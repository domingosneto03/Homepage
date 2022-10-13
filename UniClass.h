//
// Created by InesO on 13/10/2022.
//

#ifndef PROJECTAED_G24_CLASS_H
#define PROJECTAED_G24_CLASS_H

enum CLASS_TYPE {
    T, TP, PL
};

class UniClass {
public:
    UniClass(int classCode, int UcCode, int weekDay, float startHour, float duration, CLASS_TYPE classType);

private:
    int classCode;
    int UcCode;
    int weekDay;
    float startHour;
    float duration;
    CLASS_TYPE classType;
};


#endif //PROJECTAED_G24_CLASS_H