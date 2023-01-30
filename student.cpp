//
// Created by Dustin Luttrell on 1/27/23.
//

#include<iostream>
#include<string>
#include<vector>

#include"degree.h"
#include"student.h"
#include"roster.h"

/*
    Student class function definitions
*/


// Student ID
void student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
string student::getStudentID()
{
    return this->studentID;
}

// First Name
void student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
string student::getFirstName()
{
    return this->firstName;
}

// Last Name
void student::setLastName(string lastName)
{
    this->lastName = lastName;
}
string student::getLastName()
{
    return this->lastName;
}

// Email Address
void student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
string student::getEmailAddress()
{
    return this->emailAddress;
}

// Age
void student::setAge(int age)
{
    this->age = age;
}
int student::getAge()
{
    return this->age;
}

// Days to complete course
void student::setDaysToCompleteCourse(std::vector<int> daysToCompleteCourse)
{
    this->daysToCompleteCourse = daysToCompleteCourse;
}
std::vector<int> student::getDaysToCompleteCourse()
{
    return this->daysToCompleteCourse;
}

// Degree Program
void student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}
DegreeProgram student::getDegreeProgram()
{
    return this->degreeProgram;
}

// Print specefic student data - D2E
void student::printStudentData(string keyword)
{

}

// Constructor - D2D
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, std::vector<int> daysToCompleteCourse, DegreeProgram degreeProgram)
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
student::~student()
{
}
