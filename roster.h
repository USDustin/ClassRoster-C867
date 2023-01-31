//
// Created by Dustin Luttrell on 1/27/23.
//
#pragma once
#ifndef CLASSROSTER_C867_ROSTER_H
#define CLASSROSTER_C867_ROSTER_H

#include"string"
#include"vector"
//#include "student.h"

using std::string;

class Roster
{
    public:

        std::vector<Student*> classRosterArray;
        int numberOfStudents;

        void parseStudentDataTable(string studentDataTable);

        void add(string studentID,
                 string firstName,
                 string lastName,
                 string emailAddress,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram);
        void remove(string studentID);

        void printAll() const;
        void printAverageDaysInCourse(string studentID) const;
        void printInvalidEmails() const;

        explicit Roster(int numberOfStudents);
        ~Roster();
};

#endif //CLASSROSTER_C867_ROSTER_H
