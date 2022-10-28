#ifndef PROJECTAED_G24_CLASS_H
#define PROJECTAED_G24_CLASS_H

#include <string>
using namespace std;

enum CLASS_TYPE {
    T, TP, PL
};

class UniClass {

public:
    /**
    * Creates an object of the struct UniClass.
    * @param classCode
    * @param ucCode
    * @param weekDay
    * @param startHour
    * @param duration
    * @param classType
    */
    UniClass(string classCode, string ucCode, int weekDay, double startHour, double duration, string classType);

    /**
    * Returns the UniClass's class code.
    * @return
    */
    string getClassCode() const;

    /**
    * Returns the UniClass's uc code.
    * @return
    */
    string getUcCode() const;

    /**
    * Returns the UniClass's week day.
    * @return
    */
    int getWeekDay() const;

    /**
    * Returns the UniClass's start hour.
    * @return
    */
    double getStartHour() const;

    /**
    * Returns the UniClass's duration.
    * @return
    */
    double getDuration() const;

    /**
    * Returns the UniClass's class type.
    * @return
    */
    CLASS_TYPE getClassType() const;

    /**
     * Sets the UniClass's class code.
     * @param classCode
     */
    void setClassCode(string classCode);

    /**
     * Sets the UniClass's uc code.
     * @param ucCode
     */
    void setUcCode(string ucCode);

    /**
     * Sets the UniClass's week day.
     * @param weekDay
     */
    void setWeekDay(int weekDay);

    /**
     * Sets the UniClass's start hour.
     * @param startHour
     */
    void setStartHour(double startHour);

    /**
     * Sets the UniClass's duration.
     * @param duration
     */
    void setDuration(double duration);

    /**
     * Sets the UniClass's class type.
     * @param classType
     */
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