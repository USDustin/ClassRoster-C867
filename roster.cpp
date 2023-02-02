//
// Created by Dustin Luttrell on 1/27/23.
//

#include"iostream"
#include"iomanip"
#include"string"
#include"vector"
#include"map"
#include"regex"
#include"utility"

#include"degree.h"
#include"student.h"
#include"roster.h"

using std::cout;

void Roster::parseStudentDataTable(const string &studentDataTable)
{

    /*
     *  Parse string containing individual student information. Comma seperated strings
     *  Use string find() method to locate first comma then use string substr() method to get the string between 0 and first comma
     *  Move delimiter to one position past first comma and search for the next comma, substr to get the next string
     *  Continue for each value
     *  Create map to convert degree program string to DegreeProgram type
     *  Loop through map comparing degreeProgramString to the maps key
     *  If match found set degreeProgram to the keys value
     *  Call add method with the 9 values found
     */

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

    /*
     *  Requirement E3A: Define add method that sets the 9 instance variables for student
     *  Creates a new student object using the 9 parameters and adds the object onto the classRosterArray
     */

    std::vector<int> daysInCourses;
    daysInCourses.insert(daysInCourses.end(), { daysInCourse1, daysInCourse2, daysInCourse3 } );
    auto* student = new Student(
            studentID,
            firstName,
            lastName,
            emailAddress,
            age,
            daysInCourses,
            degreeProgram);
    classRosterArray.reserve(numberOfStudents);
    classRosterArray.push_back(student);
}

void Roster::remove(const string &studentID)
{

    /*
     *  Requirement E3B: Define remove method that removes student from roster using the students ID
     *  If ID does not exist in the class roster, print an error
     *  Loop through roster, check if student matches the provided student ID
     *  If match found remove student from roster, print message, update boolean
     */

    bool studentFound = false;
    for (int i = 0; i < classRosterArray.size(); i++)
    {
        if (classRosterArray.at(i)->getStudentID() == studentID)
        {
            cout << "\nRemoving student '" << classRosterArray.at(i)->getStudentID() << "'...\n";
            classRosterArray.erase(classRosterArray.begin() + i);
            cout << "'" << studentID << "' successfully removed!\n";
            studentFound = true;
        }
    }
    if (!studentFound)
    {
        cout << "\nError: student '" << studentID << "' was not found\n";
    }
}

void Roster::printAll() const
{
    /*
     *  Requirement E3C: Call print method on each student object.
     *  Prints ID, first name, last name, age , days in course, and degree program. Tab seperated.
     *  E3C does NOT say to print student email addresses.
     */

    cout << "\nPrinting all students...\n\n";
    for (auto & student : classRosterArray)
    {
        student->print();
    }
}

void Roster::printAverageDaysInCourse(const string &studentID) const
{

    /*
     *  Requirement E3D: Print average number of days between the 3 courses.
     *  Finds student matching studentID and calls its method to get the days as a vector
     *  Adds the days together and divides by the number of days for the average.
     *  Prints the average.
     */

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
    cout << "\nAverage days for student '" << studentID << "': " << std::setprecision(5) << daysAverage;
}

void Roster::printInvalidEmails() const
{

    /*
     *  Requirement E3E: Verifies student email address and print all invalid email addresses
     *  Regex pattern checks if email contains '@', '.', and does not contain ' '.
     *  Loop through students in roster, compare their email address to the regex pattern
     *  If email does not match print the address
     *  If all match, print no invalid emails found
     */

    const std::regex pattern
            (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

    int validEmails = 0;

    cout << "\nSearching for invalid emails...\n";

    for (auto & student : classRosterArray)
    {
        if (!std::regex_match(student->getEmailAddress(), pattern))
        {
            cout << "\nStudent '" << student->getStudentID() << "' has an invalid email address: "
                << student->getEmailAddress();
        } else
        {
            validEmails += 1;
        }
    }

    if (classRosterArray.size() == validEmails)
    {
        cout << "\nNo invalid emails found!\n";
        return;
    }

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const
{

    /*
     *  Requirement E3F: Print out students degree program specified by enumerated type
     *  Loop through students, compare to their degree program, if match found print student info, update studentsFound
     *  If no students found print message
     */

    string degreeProgramAsString = getDegreeProgramAsString(degreeProgram);
    int studentsFound = 0;
    cout << "\n\nSearching for students with degree program: " << degreeProgramAsString << "\n\n";
    for(auto & student : classRosterArray)
    {
        if (student->getDegreeProgram() == degreeProgram)
        {
            student->print();
            studentsFound++;
        }
    }

    if (studentsFound == 0)
    {
        cout << "\nNo students found with degree program: " << degreeProgramAsString << "\n";
    }
}

string Roster::getDegreeProgramAsString(DegreeProgram degreeProgram)
{

    /*
     *  Method to convert DegreeProgram to string
     */

    if (degreeProgram == DegreeProgram::SOFTWARE)
    {
        return "SOFTWARE";
    } else if (degreeProgram == DegreeProgram::SECURITY)
    {
        return "SECURITY";
    } else if (degreeProgram == DegreeProgram::NETWORK)
    {
        return "NETWORK";
    }
    return "404";
}


Roster::Roster(int numberOfStudents)
{
    this->numberOfStudents = numberOfStudents;
}
Roster::~Roster()
{
    cout << "\nRoster Deconstructor called\n";
}
