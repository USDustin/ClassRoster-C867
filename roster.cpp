//
// Created by Dustin Luttrell on 1/27/23.
//

#include"iostream"
#include"iomanip"
#include"string"
#include"vector"
#include"map"
#include"regex"

#include "degree.h"
#include "student.h"
#include "roster.h"

#include <utility>

using std::cout;

void Roster::parseStudentDataTable(const string studentDataTable)
{
    DegreeProgram degreeProgram;

    // Find first comma, and get substring between index 0 and comma index
    size_t delimiter1 = studentDataTable.find(',');
    string studentID = studentDataTable.substr(0, delimiter1);

    // Move to index after first comma, look for next comma.
    // Take substring between index after first comma and distance between first and second comma.
    size_t delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    string firstName = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    string lastName = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    string emailAddress = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    int age = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    int daysInCourse1 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    int daysInCourse2 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    int daysInCourse3 = std::stoi(studentDataTable.substr(delimiter2, delimiter1 - delimiter2));

    delimiter2 = delimiter1 + 1;
    delimiter1 = studentDataTable.find(',', delimiter2);
    string degreeProgramString = studentDataTable.substr(delimiter2, delimiter1 - delimiter2);

    static std::map<string, DegreeProgram> degreeProgramMap = {
            {"SECURITY", DegreeProgram::SECURITY},
            {"SOFTWARE", DegreeProgram::SOFTWARE},
            {"NETWORK", DegreeProgram::NETWORK}
    };

    for (auto const & iterator : degreeProgramMap)
    {
        if (degreeProgramString == iterator.first)
        {
            degreeProgram = iterator.second;
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
            std::move(studentID),
            std::move(firstName),
            std::move(lastName),
            std::move(emailAddress),
            age,
            daysToCompleteCourses,
            degreeProgram);
    classRosterArray.reserve(numberOfStudents);
    classRosterArray.push_back(student);
}

void Roster::remove(string studentID)
{

}

void Roster::printAll() const
{
    // For each student object in the class roster array call its print method. E3C
    for (auto & student : classRosterArray)
    {
        student->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) const
{
    std::vector<int> days;
    double daysAverage = 0.00;

    for (auto & student : classRosterArray)
    {
        if (studentID == student->getStudentID())
        {
            days = student->getDaysToCompleteCourse();
            break;
        }
    }

    for (int day : days)
    {
        daysAverage += day;
    }
    daysAverage = ( daysAverage / days.size());
    cout << "\nAverage days for student '" << studentID << "': " << std::setprecision(5) << daysAverage << "\n";
}

void Roster::printInvalidEmails() const
{
    const std::regex pattern
            (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

    int validEmails = 0;

    cout << "\nSearching for invalid emails...\n";

    for (auto & student : classRosterArray)
    {
        if (!std::regex_match(student->getEmailAddress(), pattern))
        {
            cout << "\nStudent '" << student->getStudentID() << "' has an invalid email address: " << student->getEmailAddress();
        } else
        {
            validEmails += 1;
        }
    }

    if (classRosterArray.size() == validEmails)
    {
        cout << "\nNo invalid emails found!\n";
    }

}


Roster::Roster(int numberOfStudents)
{
    this->numberOfStudents = numberOfStudents;
}
Roster::~Roster()
= default;
