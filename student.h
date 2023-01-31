//
// Created by Dustin Luttrell on 1/27/23.
//
#pragma once
#ifndef CLASSROSTER_C867_STUDENT_H
#define CLASSROSTER_C867_STUDENT_H



#include"string"
#include"vector"

#include"degree.h"
//#include"Roster.h"
//#include"Student.h"

using std::string;

class Student
{

private:

    // Private instance variables - D2C
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    std::vector<int> daysToCompleteCourse;
    DegreeProgram degreeProgram;


public:
    // Accessor and mutator functions for each instance variable - D2A, D2B

    // Student ID
    void setStudentID(string studentID);
    string getStudentID();

    // First Name
    void setFirstName(string firstName);
    string getFirstName();

    // Last Name
    void setLastName(string lastName);
    string getLastName();

    // Email Address
    void setEmailAddress(string emailAddress);
    string getEmailAddress();

    // Age
    void setAge(int age);
    int getAge();

    // Days to complete course
    void setDaysToCompleteCourse(std::vector<int> daysToCompleteCourse);
    std::vector<int> getDaysToCompleteCourse();

    // Degree Program
    void setDegreeProgram(DegreeProgram degreeProgram);
    DegreeProgram getDegreeProgram();

    // Student data print function
    void print();

    // Student constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, std::vector<int> daysToCompleteCourse, DegreeProgram degreeProgram);

    // Student deconstructor
    ~Student();

};


#endif //CLASSROSTER_C867_STUDENT_H
