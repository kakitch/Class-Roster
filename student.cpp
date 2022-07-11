#include "student.h"
#include "degree.h"

Student::Student(string id, string FirstName, string LastName, string Email, int age, int daysToComplete[], DegreeProgram degreeProgram)
{
    this->id = id;
    this->FirstName = FirstName;
    this->LastName = LastName;
    this->age = age;
    this->Email = Email;
    this->daysToComplete = new int[NUMCOURSES];
    for (int i = 0; i < NUMCOURSES; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}
//getters
string Student::GetId() 
{
    return id;
}
string Student::GetFirstName() 
{
    return FirstName;
}
string Student::GetLastName()
{
    return LastName;
}
string Student::GetEmail() 
{
    return Email;
} 
int Student::GetAge()
{
    return age;
}
int* Student::GetDaystoComplete()
{
    return daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() 
{
    return degreeProgram;
}

//setters
void Student::SetId(string studentID)
{
    this->id = id;
}
void Student::SetFirstName(string FirstName)
{
    this->FirstName = FirstName;
}
void Student::SetLastName(string LastName)
{
    this->LastName = LastName;
}
void Student::SetEmail(string Email)
{
    this->Email = Email;
}
void Student::SetAge(int age)
{
    this->age = age;
}



















void Student::print() {
    cout << id << '\t' << "First name: " << FirstName << '\t' << "Last name: " << LastName << '\t';
    cout << "Email: " << Email << '\t' << "Age: " << age << '\t' << "Days In Course: ";

    cout << "{";

    for (int i = 0; i < NUMCOURSES; i++) {
        cout << daysToComplete[i];
        if (i != NUMCOURSES - 1) {
            cout << ", ";
        }
    }
    cout << "}";
    cout << '\t';
    cout << "Degree Program: ";

    switch (degreeProgram) {
    case SECURITY:
        cout << "SECURITY";
        break;
    case NETWORK:
        cout << "NETWORK";
        break;
    case SOFTWARE:
        cout << "SOFTWARE";
        break;
    }
    cout << endl;
    return;
}