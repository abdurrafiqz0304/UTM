// Problem 2 : Aggregation

#include <iostream>
#include <string>
using namespace std;

class Advisor
{
private:
    string name;
    string staffId;
    string department;

public:
    Advisor(string _name = "", string _staffId = "", string _department = "")
        : name(_name), staffId(_staffId), department(_department) {}
    string getName() const { return name; }
    string getStaffId() const { return staffId; }
    string getDepartment() const { return department; }
};

// Object contains a pointer to another object

class Student
{
private:
    string name;
    string matric;
    Advisor *adv; // Pointer to an Advisor object. Showing aggregation.

public:
    Student(string _name = "", string _matric = "")
        : name(_name), matric(_matric), adv(NULL) {}
        
        //other way to do it, so can delete line 41-44
        // Student(string _name = "", string _matric = "", Advisor *_adv = NULL)
        // : name(_name), matric(_matric), adv(adv) {}//adv still not pointing anywhere yet!
    string getName() const { return name; }
    string getMatric() const { return matric; }

    // Function to assign an advisor to this student
    void assignAdvisor(Advisor *a) {
        // adv = &a; // Assigning the address of 'a' to 'adv'. To get the address, use '&' operator.
        adv = a; // Assigning the value of 'a' (which is the address of the Advisor object) to 'adv'.
    }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;

        // Only print advisor info if the student has been assigned one.
        cout << "Advisor: " << endl;
        if (adv != NULL){
        cout << "   Name       : " << adv->getName() <<  endl;
        cout << "   Staff ID   : " << adv->getStaffId() << endl;
        cout << "   Department : " << (*adv).getDepartment() << endl;
        }
        else 
            cout << "No advisor assigned" << endl;
        cout << endl << endl;
    }
};

int main()
{
    //! Create an advisor object and three students object
    //!  assign the advisor to only to two students.



    Advisor adv("Abu","12345", "IT");
    // Student stud1("Rashid,", "A1234", &adv); // Creating a student with the advisor's address

    Student stud1("Rashid,", "A1234");
    Student stud2("Ahmad", "B1234");
    Student stud3("Lim", "687sd");

    // Assigning the address of 'adv' to 'stud1', 'stud2', and 'stud3' respectively
    // Assigning advisor to stud1 and stud2 but not stud3
    stud1.assignAdvisor(&adv); // Assigning the address of 'adv' to 'stud1'
    stud2.assignAdvisor(&adv); // Assigning the address of 'adv' to 'stud2'
    //stud3.assignAdvisor(&adv); // Assigning the address of 'adv' to 'stud3'

    stud1.print();
    stud2.print();
    stud3.print();

    system("pause");
    return 0;
}