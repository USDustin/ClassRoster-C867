//
// Created by Dustin Luttrell on 1/27/23.
//

#include"iostream"
#include"string"
#include"vector"
#include"map"

#include "degree.h"
#include "student.h"
#include "roster.h"

using std::cout;

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{

}

void roster::parseStudentDataTable(const string studentDataTable)
{
    // Find first comma, and get substring between index 0 and comma index
    int delimiter1 = studentDataTable.find(",");
    string studentID = studentDataTable.substr(0, delimiter1);
    std::cout << studentID << std::endl;

    // Move to index after first comma, look for next comma.
    // Take substring between index after first comma and distance between first and second comma.
    int delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string firstName = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);
    std::cout << firstName << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string lastName = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);
    std::cout << lastName << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string emailAddress = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);
    std::cout << emailAddress << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int age = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));
    std::cout << age << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int daysInCourse1 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));
    std::cout << daysInCourse1 << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int daysInCourse2 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));
    std::cout << daysInCourse2 << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int daysInCourse3 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));
    std::cout << daysInCourse3 << std::endl;

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string degreeProgramString = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);
    //std::cout << degreeProgramString << std::endl;

    DegreeProgram degreeProgram;

    static std::map<string, DegreeProgram> degreeProgramMap = {
            {"SECURITY", DegreeProgram::SECURITY},
            {"SOFTWARE", DegreeProgram::SOFTWARE},
            {"NETWORK", DegreeProgram::NETWORK}
    };


    for (std::map<string, DegreeProgram>::iterator p = degreeProgramMap.begin(); p != degreeProgramMap.end(); ++p)
    {
        if (degreeProgramString.compare(p->first))
        {
            degreeProgram = p->second;
            cout << p->first << std::endl;
        }
    }


}

roster::roster(int numberOfStudents)
{
    this->numberOfStudents = numberOfStudents;
}