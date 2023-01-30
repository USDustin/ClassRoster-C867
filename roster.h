//
// Created by Dustin Luttrell on 1/27/23.
//

#ifndef CLASSROSTER_C867_ROSTER_H
#define CLASSROSTER_C867_ROSTER_H

#pragma once

#include"string"
#include"vector"

using std::string;

class roster
{
    private:
        std::vector<int> classRosterArray;
        int numberOfStudents;
    public:
        void parseStudentDataTable(string studentDataTable);
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

        roster(int numberOfStudents);
};

#endif //CLASSROSTER_C867_ROSTER_H
