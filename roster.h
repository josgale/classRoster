#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

using namespace std;

class Roster {
private:
    Student** classRosterArray;
    int lastIndex;
    int capacity;
    
public:
    Roster();
    ~Roster();

    void parseAndAddStudent(const std::string& studentData);
    void add(
            const string& studentID,
            const string& firstName,
            const string& lastName,
            const string& emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            DegreeProgram degreeProgram
    );
    void remove(const string& studentID);
    void printAll() const;
    void printAverageDaysInCourse(const string& studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    Student* getStudentAt(int index) const;
    int getLastIndex() const;
};

#endif