


#include <iostream>
#include "student.h"
#include "degree.h"



class Roster {
public:

    //constructors-deconstructors
    Roster(const string studentData[], int sizeofStudentData);
    ~Roster();
    
    Student** classRosterArray;
    
    void add(const string newStudentData);
    void remove(string id);
    void printAll();
    void printInvalidEmails();
    void printAverageDaysInCourse();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // assuming that there is a max capacity of students on the roster
private:
    int maxCapacity;
    int studentCount;
    int initialStudents;
    
};

