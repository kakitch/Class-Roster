#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
#include <sstream>
using std::remove;
using std::cout;
using namespace std;

Roster::Roster(const string studentData[], int sizeofStudentData) {
    
    this->initialStudents = sizeofStudentData;
    this->maxCapacity = 20;
    this->studentCount = 0;
    this->classRosterArray = new Student * [maxCapacity] ;
    
    for (studentCount; studentCount < initialStudents; studentCount) {
        add(studentData[studentCount]);
    }
}

Roster::~Roster() {
    delete[] classRosterArray;
}
          
void Roster::printAll() {
    for (int i = 0; i < studentCount; ++i) {
        classRosterArray[i]->print();
        }
    cout << endl;
}
        
void Roster::printInvalidEmails() {
    int count = 0;
    std::cout << "Displaying Invalid Email Addresses : " << std::endl << std::endl;
    bool found = false; // Any invalid emails found?

    for (int i = 0; i < studentCount; i++)
    { // search for "@",".", and " ".
        
        string email = classRosterArray[i]->GetEmail();
        {   //if "@" symbol is missing
            if (email.find('@') == string::npos) {
                cout << email<< "\t" << "Missing an @ symbol"  << endl;
                count++;
            }
            // if period is not found
            else if (email.find('.') == string::npos) {
                cout << email << "\t" << "Missing a '.'  "  << endl;
                count++;
            }
            // if a space is found
            else if (email.find(' ') != string::npos) {
                cout << email << "\t" << "Spaces are not allowed in emails " << endl;
                count++;
            }
            
         
            
        }
        
    }
    cout << endl;
     if (count == 0)
     {
        std::cout << "No Invalid emails" << endl << endl;
     }
    
}

void Roster::printAverageDaysInCourse()
{   //function Title
    cout << "Displaying Student ID and Corresponding average days to complete a course" << endl;
    
    for (int i = 0; i < studentCount; ++i) {
        string id = classRosterArray[i]->GetId();
        
        if (classRosterArray[i]->GetId() == id) {
            cout << "Student ID " << classRosterArray[i]->GetId() << ": ";
            int* days = classRosterArray[i]->GetDaystoComplete();
            cout << "Average number of days in courses: " << (days[0] + days[1] + days[2]) / 3 << endl;
            
            }
        }
    
    cout << endl;

}
 

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{   
    cout << endl;
    //Function output Title
    string degreeProgramName[] = { "SECURITY","NETWORK","SOFTWARE" };
    
        cout << "Displaying Students in the " << degreeProgramName[degreeProgram] << " degree program" << endl << endl;

        // outputs students in Degree Program of corresponding input
        for (int i = 0; i < studentCount; i++)
        {
            if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram)
            {
                this->classRosterArray[i]->print();
                cout << endl;
            }
        }
    
    cout << endl;
}
     
    
void Roster::add(const string newStudentData) {
    
      
        // initializing parsed data container
        string studentAttributes[9];
        //function that takes the input string of student information
        stringstream streamInput( newStudentData );
        string next;
        int i = 0;
        // seperating the string by ",", and pushing into studentAttributes array
        while (getline(streamInput, next, ',')) {
            studentAttributes[i] = next;
            ++i;

        }
        

        // convert strings to int
        int daysToComplete[3] = { std::stoi(studentAttributes[5]), std::stoi(studentAttributes[6]), std::stoi(studentAttributes[7]) };
        int age = std::stoi(studentAttributes[4]);

        //// convert string to enum
        DegreeProgram degreeProgram = SOFTWARE;
        if (studentAttributes[8].compare("SECURITY") == 0) {
            degreeProgram = SECURITY;
        }
        else if (studentAttributes[8].compare("NETWORK") == 0) {
            degreeProgram = NETWORK;
        }
        else if (studentAttributes[8].compare("SOFTWARE") == 0) {
            degreeProgram = SOFTWARE;
        }
        else {
            degreeProgram = SOFTWARE;
        }

        //add student to classRosterArray[]
        classRosterArray[studentCount] = new Student(studentAttributes[0], studentAttributes[1], studentAttributes[2], studentAttributes[3], age, daysToComplete, degreeProgram);
        
    studentCount++;
    
}

void Roster::remove(string id) {
    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        
        if (this->classRosterArray[i]->GetId() == id) {
            classRosterArray[i] = classRosterArray[studentCount-1];
            --studentCount;
            found = true;
            
        }
        
    }
    if (found == true) {
        cout << "\t" << id << " Successfully Removed" << endl;
    }

    else if (found == false) {
        cout << "\t" << "Error: Student not found." << endl;
    }
    cout << endl;
}
