#include<iostream>

#include"student.h"
#include"roster.h"
#include"degree.h"

using std::string;
using std::cout;
using std::endl;

void printCourseInfo()
{
// Print course info. F1
    cout << "\n\n";
    cout << "Course Title: C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010433124" << endl;
    cout << "Name: Dustin Luttrell" << "\n\n";
}

int main()
{

// F1
    printCourseInfo();

    string studentDataTable[] =
            {
                    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
                    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                    "A5,Dustin,Luttrell,DustinLuttrell17@gmail.com,25, 17, 15, 20,SOFTWARE",
            };

    int numberOfStudents = sizeof(studentDataTable) / sizeof(studentDataTable[0]);

    DegreeProgram degreeProgram;

// F2 Create instance of Roster class called classRoster
    Roster classRoster(numberOfStudents);

    // Loop through each Student, create Student object, and add them to the class Roster
    for (int i = 0; i < numberOfStudents; i++)
    {
        classRoster.parseStudentDataTable(studentDataTable[i]);
    }

    classRoster.printAll();
// F3 Add each Student to the classRoster

// F4

// classRoster.printAll()

// classRoster.printInvalidEmails()

// Loop through classRosterArray and for each element: classRoster.printAverageDaysInCourse(/*current_object's Student id*/); Use getter for Student id

// classRoster.printByDegreeProgram(SOFTWARE);

// classRoster.remove("A3");

// classRoster.printAll();

// classRoster.remove("A3");

//expected: the above line should print a message saying such a Student with this ID was not found.

// F5

// Implement the destructor to release the memory that was allocated dynamically in Roster.

    return 0;

}