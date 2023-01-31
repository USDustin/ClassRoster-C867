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

void Roster::parseStudentDataTable(const string studentDataTable)
{
    DegreeProgram degreeProgram;

    // Find first comma, and get substring between index 0 and comma index
    int delimiter1 = studentDataTable.find(",");
    string studentID = studentDataTable.substr(0, delimiter1);

    // Move to index after first comma, look for next comma.
    // Take substring between index after first comma and distance between first and second comma.
    int delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string firstName = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string lastName = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string emailAddress = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int age = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int daysInCourse1 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int daysInCourse2 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    int daysInCourse3 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(",", delimiter2);
    string degreeProgramString = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    static std::map<string, DegreeProgram> degreeProgramMap = {
            {"SECURITY", DegreeProgram::SECURITY},
            {"SOFTWARE", DegreeProgram::SOFTWARE},
            {"NETWORK", DegreeProgram::NETWORK}
    };

    for (auto iterator = degreeProgramMap.begin(); iterator != degreeProgramMap.end(); iterator++)
    {
        if (degreeProgramString == iterator->first)
        {
            degreeProgram = iterator->second;
            //cout << degreeProgramString << std::endl;
            add(studentID,
                firstName,
                lastName,
                emailAddress,
                age,
                daysInCourse1,
                daysInCourse2,
                daysInCourse3,
                degreeProgram);
        }
    }

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    std::vector<int> daysToCompleteCourses { daysInCourse1, daysInCourse2, daysInCourse3 };
    auto* student = new Student(
            studentID,
            firstName,
            lastName,
            emailAddress,
            age,
            daysToCompleteCourses,
            degreeProgram);
    classRosterArray.reserve(numberOfStudents);
    classRosterArray.push_back(student);
}

void Roster::remove(string studentID)
{

}

void Roster::printAll()
{
    for (int i = 0; i < classRosterArray.size(); ++i)
    {
        classRosterArray.at(i)->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{

}

Roster::Roster(int numberOfStudents)
{
    this->numberOfStudents = numberOfStudents;
}
Roster::~Roster()
= default;
