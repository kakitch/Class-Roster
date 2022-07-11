

#include <iostream>
#include "student.h"
#include "roster.h"
using namespace std;


int main()
{

    cout << "-------------------------------------------------------------" << endl;
    cout << "C867: Scripting and Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "ID: 001417219" << endl;
    cout << "Kyle Kitchens" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    //A.  Modify the “studentData Table” to include your personal information as the last item.
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kyle,Kitchens,kkitc24@wgu.edu,33,19,16,15,SOFTWARE",
    };


    //create new instance of Roster
    Roster* classRoster = new Roster(studentData, std::size(studentData));
    
    cout << "Full Student Roster:" << endl;

    classRoster->printAll();
    classRoster->printInvalidEmails();
    classRoster->printAverageDaysInCourse();
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->printAll();
    classRoster->remove("A2");
    classRoster->printAll();
    classRoster->remove("A2");
    classRoster->~Roster();

}