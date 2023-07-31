#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student
{
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* daysToCompleteCourse;
    DegreeProgram degreeProgram;
    string degreeProgramString;

public:
    Student();
    Student(
        const string &studentID,
        const string &firstName,
        const string &lastName,
        const string &emailAddress,
        int age,
        int* daysToCompleteCourses,
        DegreeProgram degreeProgram);

    ~Student();

    // Mutators
    void setStudentID(const string &studentID);
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setEmailAddress(const std::string &emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourses(int* daysToCompleteCourses);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Accessors
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getDaysToCompleteCourses() const;
    DegreeProgram getDegreeProgram() const;



    void print() const;
};

#endif