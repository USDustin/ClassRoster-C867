#include<iostream>

#include"student.h"
#include"roster.h"
#include"degree.h"

using std::string;
using std::cout;
using std::endl;

void printCourseInfo()
{
    cout << "\nCourse Title: C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010433124" << endl;
    cout << "Name: Dustin Luttrell" << "\n\n";
}

int main()
{

    string studentDataTable[] =
            {
                    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
                    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                    "A5,Dustin,Luttrell,DustinLuttrell17@gmail.com,25, 17, 15, 20,SOFTWARE",
            };

    int numberOfStudents = sizeof(studentDataTable) / sizeof(studentDataTable[0]);
    Roster classRoster(numberOfStudents);

    printCourseInfo();

    // Loop through each student in data table. Add them to class roster.
    for (int i = 0; i < numberOfStudents; i++)
    {
        classRoster.parseStudentDataTable(studentDataTable[i]);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    cout << "\n\nPrinting average days in course for each student...\n";
    for (auto & student : classRoster.classRosterArray)
    {
        classRoster.printAverageDaysInCourse(student->getStudentID());
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;

}
