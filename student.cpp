//
// Created by Dustin Luttrell on 1/27/23.
//

#include<iostream>
#include<string>
#include<vector>

#include"degree.h"
#include"student.h"
#include"roster.h"

using std::cout;

/*
    Student class function definitions
*/


// Student ID
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
string Student::getStudentID()
{
    return this->studentID;
}

// First Name
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
string Student::getFirstName()
{
    return this->firstName;
}

// Last Name
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
string Student::getLastName()
{
    return this->lastName;
}

// Email Address
void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
string Student::getEmailAddress()
{
    return this->emailAddress;
}

// Age
void Student::setAge(int age)
{
    this->age = age;
}
int Student::getAge()
{
    return this->age;
}

// Days to complete course
void Student::setDaysToCompleteCourse(std::vector<int> daysToCompleteCourse)
{
    this->daysToCompleteCourse = daysToCompleteCourse;
}
std::vector<int> Student::getDaysToCompleteCourse()
{
    return this->daysToCompleteCourse;
}

// Degree Program
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}
DegreeProgram Student::getDegreeProgram()
{
    return this->degreeProgram;
}

// Print specefic Student data - D2E
void Student::print()
{
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

// Constructor - D2D
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, std::vector<int> daysToCompleteCourse, DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToCompleteCourse = daysToCompleteCourse;
    this->degreeProgram = degreeProgram;
}

// Deconstructor
Student::~Student()
{
}
