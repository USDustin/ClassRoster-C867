//
// Created by Dustin Luttrell on 1/27/23.
//
#pragma once
#ifndef CLASSROSTER_C867_STUDENT_H
#define CLASSROSTER_C867_STUDENT_H

#include"string"
#include"vector"

#include"degree.h"

using std::string;

class Student
{

private:

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    std::vector<int> daysToCompleteCourse;
    DegreeProgram degreeProgram;


public:

    void setStudentID(string studentID);
    string getStudentID() const;

    void setFirstName(string firstName);
    string getFirstName() const;

    void setLastName(string lastName);
    string getLastName() const;

    void setEmailAddress(string emailAddress);
    string getEmailAddress() const;

    void setAge(int age);
    int getAge() const;

    void setDaysToCompleteCourse(std::vector<int> daysToCompleteCourse);
    std::vector<int> getDaysToCompleteCourse() const;

    void setDegreeProgram(DegreeProgram degreeProgram);
    DegreeProgram getDegreeProgram() const;

    void print() const;

    // Student constructor
    Student(
            const string &studentID,
            const string &firstName,
            const string &lastName,
            const string &emailAddress,
            int age,
            std::vector<int> daysToCompleteCourse,
            DegreeProgram degreeProgram);

    // Student deconstructor
    ~Student();

};

#endif //CLASSROSTER_C867_STUDENT_H
