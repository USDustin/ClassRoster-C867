//
// Created by Dustin Luttrell on 1/27/23.
//

#include"iostream"
#include"utility"
#include"vector"

#include"degree.h"
#include"student.h"

using std::cout;


void Student::setStudentID(string studentID)
{
    this->studentID = std::move(studentID);
}
string Student::getStudentID() const
{
    return this->studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = std::move(firstName);
}
string Student::getFirstName() const
{
    return this->firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = std::move(lastName);
}
string Student::getLastName() const
{
    return this->lastName;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = std::move(emailAddress);
}
string Student::getEmailAddress() const
{
    return this->emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}
int Student::getAge() const
{
    return this->age;
}

void Student::setDaysToCompleteCourse(std::vector<int> daysToCompleteCourse)
{
    this->daysToCompleteCourse = std::move(daysToCompleteCourse);
}
std::vector<int> Student::getDaysToCompleteCourse() const
{
    return this->daysToCompleteCourse;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}
DegreeProgram Student::getDegreeProgram() const
{
    return this->degreeProgram;
}


void Student::print() const
{

    /*
     *  Requirement D2E: Print specific student data
     *  Call getters to get each piece of the students data
     *  Loop through daysToCompleteCourses vector and print each int
     *  Compare students DegreeProgram to DegreeProgram enum, print string
     */

    std::vector<int> daysToCompleteCourses = this->getDaysToCompleteCourse();
    DegreeProgram program = this->getDegreeProgram();

    cout << this->getStudentID() << "\t";
    cout << "First Name: " << this->getFirstName() << "\t";
    cout << "Last Name: " << this->getLastName() << "\t";
    cout << "Age: " << this->getAge() << "\t";

    cout << "daysInCourse: { ";
    for (int i = 0; i < daysToCompleteCourses.size(); ++i)
    {
        cout << daysToCompleteCourses.at(i);
        if (i < ( daysToCompleteCourses.size() - 1))
        {
            cout << ", ";
        } else if ( i < ( daysToCompleteCourses.size() + 1))
        {
            cout << " }";
        }

    }

    cout << "\t" << "Degree Program: ";
    if (program == DegreeProgram::SECURITY)
    {
        cout << "Security";
    } else if (program == DegreeProgram::SOFTWARE)
    {
        cout << "Software";
    } else if (program == DegreeProgram::NETWORK)
    {
        cout << "Network";
    } else
    {
        cout << "No degree program";
    }

    cout << "\n";
}

Student::Student(
        const string &studentID,
        const string &firstName,
        const string &lastName,
        const string &emailAddress,
        int age,
        std::vector<int> daysToCompleteCourse,
        DegreeProgram degreeProgram)
{
    this->setStudentID(studentID);
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setEmailAddress(emailAddress);
    this->setAge(age);
    this->setDaysToCompleteCourse(daysToCompleteCourse);
    this->setDegreeProgram(degreeProgram);
}

Student::~Student() = default;
