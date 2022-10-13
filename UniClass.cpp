//
// Created by InesO on 13/10/2022.
//

#include "UniClass.h"

UniClass::UniClass(int classCode, int UcCode, int weekDay, float startHour, float duration, CLASS_TYPE classType) {
    this->classCode = classCode;
    this->UcCode = UcCode;
    this->weekDay = weekDay;
    this->startHour = startHour;
    this->duration = duration;
    this->classType = classType;
}
