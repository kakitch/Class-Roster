#pragma once 
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

#define NUMCOURSES 3


class Student {
public:
        
    //Constructor 
    Student(string id, string FirstName, string LastName, string Email, int age, int daysToComplete[], DegreeProgram degreeProgram);
    

    //Getters
    string GetId();
    string GetFirstName();
    string GetLastName();
    string GetEmail();
    int GetAge();
    int* GetDaystoComplete();
    DegreeProgram GetDegreeProgram();

    //Setters
    void SetId(string id);
    void SetFirstName(string FirstName);
    void SetLastName(string LastName);
    void SetAge(int age);
    void SetEmail(string Email);
    void SetDaystoComplete(int daysToComplete[]);
    void SetDegreeProgram(DegreeProgram degreeProgram);

    //print() to print specific student data
    void print();

    //D1, D2c. variables accessible only internally
private:
    string id;
    string FirstName;
    string LastName;
    int age;
    string Email;
    int* daysToComplete;
    DegreeProgram degreeProgram;
};

