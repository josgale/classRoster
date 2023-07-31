#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Student::Student()
{
    daysToCompleteCourse = nullptr;
}

Student::Student(
    const string &studentID,
    const string &firstName,
    const string &lastName,
    const string &emailAddress,
    int age,
    int* daysToCompleteCourses,
    DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourse = daysToCompleteCourses;
    this->degreeProgram = degreeProgram;
}

Student::~Student()
{
    delete[] daysToCompleteCourse;
}

string Student::getStudentID() const
{
    return this -> studentID;
}

void Student::setStudentID(const string &studentID)
{
    this -> studentID = studentID;
}

string Student::getFirstName() const
{
    return firstName;
}

void Student::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

string Student::getLastName() const
{
    return lastName;
}

void Student::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

string Student::getEmailAddress() const
{
    return emailAddress;
}

void Student::setEmailAddress(const string &emailAddress)
{
    this->emailAddress = emailAddress;
}

int Student::getAge() const
{
    return age;
}

void Student::setAge(int age)
{
    this->age = age;
}

int* Student::getDaysToCompleteCourses() const
{
    return daysToCompleteCourse;
}

void Student::setDaysToCompleteCourses(int* daysToCompleteCourses)
{
    this->daysToCompleteCourse = daysToCompleteCourses;
}

DegreeProgram Student::getDegreeProgram() const
{
    return degreeProgram;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}

//Added tab separated as required in the task instructions
void Student::print() const {
    cout << "Student ID: " << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1] << ", " << daysToCompleteCourse[2] << "} ";
    cout << "Degree Program: ";

    switch (degreeProgram) {
        case DegreeProgram::SECURITY:
            cout << "Security";
            break;
        case DegreeProgram::NETWORK:
            cout << "Network";
            break;
        case DegreeProgram::SOFTWARE:
            cout << "Software";
            break;
    }

    cout << endl;
}