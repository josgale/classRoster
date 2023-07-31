#include <iostream>
#include "roster.h"

using namespace std;

int main()
{
    // Create an instance of the Roster class
    Roster classRoster;

    // Add each student to classRoster using the provided studentData array
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,Glam,xxx@xxx.com,31,10,25,29,SOFTWARE"};

    for (int i = 0; i < 5; i++)
    {
        classRoster.parseAndAddStudent(studentData[i]);
    }

    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: xxx" << endl;
    cout << "Your Name: xxxx" << endl;
    cout << endl;
    cout << " " << endl;

    cout << "Complete Roster: " << endl;
    classRoster.printAll();
    cout << " " << endl;
    cout << " " << endl;

    classRoster.printInvalidEmails();
    cout << " " << endl;
    // printing the average days in the courses for each student
    cout << "Average days in course: " << endl;
    for (int i = 0; i <= classRoster.getLastIndex(); ++i)
    {
        Student *student = classRoster.getStudentAt(i);
        if (student != nullptr)
        {
            string studentID = student->getStudentID();
            classRoster.printAverageDaysInCourse(studentID);
        }
    }

    cout << " " << endl;
    cout << " " << endl;

    cout << "Print By Degree Program: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << " " << endl;
    cout << " " << endl;

    classRoster.remove("A3");
    cout << " " << endl;
    cout << " " << endl;

    cout << "Complete Roster: " << endl;
    classRoster.printAll();
    cout << " " << endl;
    cout << " " << endl;

    classRoster.remove("A3");

    return 0;
}