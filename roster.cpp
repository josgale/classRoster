#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>

using namespace std;

Roster::Roster()
{
    lastIndex = -1;
    capacity = 5;
    classRosterArray = new Student *[capacity];
}

Roster::~Roster()
{
    for (int i = 0; i <= lastIndex; ++i)
    {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

void Roster::parseAndAddStudent(const string &studentData)
{
    string delimiter = ",";
    size_t position = 0;
    string token;
    string tempData = studentData;
    string data[9];

    int i = 0;
    while ((position = tempData.find(delimiter)) != string::npos)
    {
        token = tempData.substr(0, position);
        data[i++] = token;
        tempData.erase(0, position + delimiter.length());
    }
    data[i] = tempData;

    DegreeProgram degreeProgram;
    if (data[8] == "SECURITY")
    {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (data[8] == "NETWORK")
    {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (data[8] == "SOFTWARE")
    {
        degreeProgram = DegreeProgram::SOFTWARE;
    }

    add(data[0], data[1], data[2], data[3], stoi(data[4]), stoi(data[5]), stoi(data[6]), stoi(data[7]), degreeProgram);
}

void Roster::add(const string &studentID, const string &firstName, const string &lastName,
                 const string &emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram)
{
    if (lastIndex < capacity - 1)
    {
        int* daysToCompleteCourses = new int[3];
        daysToCompleteCourses[0] = daysInCourse1;
        daysToCompleteCourses[1] = daysInCourse2;
        daysToCompleteCourses[2] = daysInCourse3;

        Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourses, degreeProgram);
        lastIndex++;
        classRosterArray[lastIndex] = newStudent;
    }
    else
    {
        cout << "Error: Roster is full. Cannot add more students." << endl;
    }
}

void Roster::remove(const string &studentID)
{
    cout << "Removing Student " << studentID << "..." << endl;
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (classRosterArray[i] == nullptr)
        {
            cout << "Error: Student with ID " << studentID << " not found." << endl;
            break;
        }
        else if (studentID == classRosterArray[i]->getStudentID())
        {
            // Delete the student object before setting the array element to nullptr
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            capacity = capacity - 1;
            cout << "Student with ID " << studentID << " deleted from roster..." << endl;
            break; 
        }
    }
}

void Roster::printAll() const
    {
        for (int i = 0; i <= lastIndex; i++)
        {
            if (classRosterArray[i] != nullptr)
            {
                classRosterArray[i]->print();
            }
        }
    }

void Roster::printAverageDaysInCourse(const string &studentID) const
{
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            int *daysToCompleteCourses = classRosterArray[i]->getDaysToCompleteCourses();
            double averageDays = (daysToCompleteCourses[0] + daysToCompleteCourses[1] + daysToCompleteCourses[2]) / 3.0;

            std::cout << "Average number of days in courses for student with ID " << studentID << ": " << averageDays << std::endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printInvalidEmails() const
{
    std::cout << "Invalid email addresses:" << std::endl;
    for (int i = 0; i <= lastIndex; ++i)
    {
        std::string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos)
        {
            std::cout << email << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{
    cout << "Students in Degree Program: ";

    switch (degreeProgram)
    {
    case DegreeProgram::SECURITY:
        cout << "Security";
        break;
    case DegreeProgram::NETWORK:
        cout << "Network";
        break;
    case DegreeProgram::SOFTWARE:
        cout << "Software";
        break;
    default:
        cout << "Unknown";
    }

    cout << endl;

    for (int i = 0; i <= lastIndex; ++i)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
}

Student* Roster::getStudentAt(int index) const
{
    if (index >= 0 && index <= lastIndex)
    {
        return classRosterArray[index];
    }
    return nullptr;
}

int Roster::getLastIndex() const
{
    return lastIndex;
}