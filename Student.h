#include <string>
#include <vector>

using namespace std;

#ifndef PROJECTAED_G24_STUDENT_H
#define PROJECTAED_G24_STUDENT_H

class Student {

public:
    /**
    * Creates an object of the struct Student.
    * @param studentCode
    * @param name
    * @param vector<string> Class
    */
    Student(string studentCode, string name, vector<string> Class);

    /**
    * Returns the Student's name.
    * @return
    */
    string getName() const;

    /**
   * Returns the Student's code.
   * @return
   */
    string getStudentCode();

    /**
   * Returns the Student's classes vector.
   * @return
   */
    vector<vector<string>> getClasses() const;

    /**
    * Sets the Student's name.
    * @param name
    */
    void setName(string name);

    /**
    * Sets the Student's student code.
    * @param studentcode
    */
    void setStudentCode(string studentcode);

    /**
    * Adds a class to the array of student classes.
    * @param vector<string> Class
    */
    void addClass(vector<string> Class);

    bool operator<(const Student &s1) const;

    bool operator>(const Student &s1) const;

    bool operator==(const Student &s1) const;

private:
    string studentCode;
    string name;
    vector<vector<string>> classes = {};
};

#endif //PROJECTAED_G24_STUDENT_H