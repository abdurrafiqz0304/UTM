
// Use this program template to answer Question 3

// Programming Technique II (SCSJ1023)
// Semester 1, 2019/2020

// Programming Technique II (SECJ1023)
// Semester 1, 2020/2021

// Exercise 3: Polymorphism and inheritance

// Write your name and your partner's name.
// Only one submission is required per pair
// Submit only the source code file.
// Use only one source code file for this exercise. However, class declaration and definition
//  must be separated within the same file.

//! Pair Programming - Members Names and Location
//! Name 1:
//! Name 2:

#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------------------------
// Class declarations >> Student, Mentor, Coach, Support and Mentee
//-------------------------------------------------------------------------------------------------------------
// Class Student is fully given. Do nothing on this class.

class Student
{
protected:
    string name;

public:
    Student(string n = "");
    string getName() const;
    void setName(string n);
};

// Task 1(a): Declare the class Mentor.
class Mentor : public Student
{
protected:
    double cpa;

public:
    Mentor(string n, double c);
    virtual void edit() = 0; // Pure virtual function to make Mentor an abstract class
    virtual void print(); // Pure virtual function to make Mentor an abstract class
};

// Task 1(b): Declare the class Coach.
class Coach : public Mentor
{
protected:
public:
    Coach(string name, double cpa, string expertise);
    string getExpertise() const; // Getter for expertise
    void setExpertise(string e); // Setter for expertise
    virtual void edit() override; // Override the pure virtual function from Mentor
    virtual void print();
};

// Task 1(c): Declare the class Support.
class Support : public Mentor
{
protected:
    string phone;

public:
    Support(string name, double cpa, string phone);
    string getPhone() const; // Getter for phone
    void setPhone(string p); // Setter for phone
    virtual void edit() override; // Override the pure virtual function from Mentor
    virtual void print();
};

// Task 1(d): Declare the class Mentee.
class Mentee : public Student
{
protected:
    int level;
    Mentor* mentor; // Pointer to the assigned mentor

public:
    Mentee(string name, int level);
    int getLevel() const; // Getter for level
    void setLevel(int l); // Setter for level
    Mentor* getMentor() const; // Getter for mentor
    void setMentor(Mentor* m); // Setter for mentor
    void displayInfo() const; // Method to display mentee info
};

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Student
//-------------------------------------------------------------------------------------------------------------
// Class Student is given. Do nothing on this class.

Student::Student(string n) : name(n) {}
string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Mentor
//-------------------------------------------------------------------------------------------------------------
// Task 2: Define all methods for the class Mentor.
Mentor(string n, double c);
    // virtual void edit() = 0; // Pure virtual function to make Mentor an abstract class
    virtual void print(); // Pure virtual function to make Mentor an abstract class

Mentor::Mentor(string n, double c) : Student(n), cpa(c) {}
void Mentor::print() {
    cout << "Mentor Name: " << getName() <<endl << " CPA: " << cpa << endl;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Coach
//-------------------------------------------------------------------------------------------------------------
// Task 3:  Define all methods for the class Coach.
Coach::Coach(string name, double cpa, string expertise) : Mentor(name, cpa) {
    this->expertise = expertise;
}

string Coach::getExpertise() const {
    return expertise;
}

void Coach::setExpertise(string e) {
    expertise = e;
}

void Coach::edit() {
    cout << "You are editing the Coach details." << endl;
    cout << "Enter new name: ";
    getline(cin, name);
    // Implementation for editing Coach details
}

void Coach::print() {
    cout << "Mentor information:" << endl;
    cout << "Mentor type: Coach" << endl;
    Mentor::print();
    cout << "Expertise: " << expertise << endl;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Support
//-------------------------------------------------------------------------------------------------------------
// Task 4: Define all methods for class Support.
Support::Support(string name, double cpa, string phone) : Mentor(name, cpa){
    this->phone = phone;
}

string Support::getPhone() const {
    return phone;
}

void Support::setPhone(string p) {
    phone = p;
}

void Support::edit() {
    cout << "You are editing the Support details." << endl;
    cout << "Enter new name: ";
    getline(cin, name);
    // Implementation for editing Support details
}

void Support::print() {
    cout << "Mentor information:" << endl;
    cout << "Mentor type: Support" << endl;
    Mentor::print();
    cout << "Phone: " << phone << endl;
}

//-------------------------------------------------------------------------------------------------------------
// Class definition >> Mentee
//-------------------------------------------------------------------------------------------------------------
// Task 5: Define all methods for the class Mentee.
Mentee::Mentee(string name, int level) {
    this->name = name;
    this->level = level;
    this->mentor = nullptr; // Initially, no mentor is assigned
}
int Mentee::getLevel() const {
    cout << "Mentee Name: " << name << endl;
    cout << "Mentee Level: " << level << endl;
    return level;
}

//-------------------------------------------------------------------------------------------------------------
// The menu function is given
int menu()
{
    cout << endl;
    cout << "========== Menu ==========" << endl;
    cout << "1. Select first mentor" << endl;
    cout << "2. Select second mentor" << endl;
    cout << "3. Display selected mentor" << endl;
    cout << "4. Edit selected mentor" << endl;
    cout << "5. Assign selected mentor to mentee" << endl;
    cout << "6. Unassign mentor from mentee" << endl;
    cout << "7. Display all mentees" << endl;
    cout << "9. Exit" << endl;
    cout << endl;

    int choice;
    cout << "Choose an operation [1-7, or 9] => ";
    cin >> choice;

    cin.ignore();
    cout << endl;

    return choice;
}

//-------------------------------------------------------------------------------------------------------------
// The Main Function
//-------------------------------------------------------------------------------------------------------------

int main()
{
    // Given an array of mentees.
    Mentee mentees[3] = {Mentee("Abdul Samad", 2),
                         Mentee("Nurdiana", 1),
                         Mentee("Nurazlan", 2)};
    int index; // the index of mentee that the user wants to work on. To be used in case 5 and case 6

    // Given two mentors
    Coach mentor1("Ahmad Kamal", 3.87, "Programming");
    Support mentor2("Siti Aminah", 3.98, "0123456789");

    // Task 6(a): Declare a pointer to be used for pointing to a coach-mentor or a support-mentor.
    //            Initialize this pointer to point to any of the mentors (mentor1 or mentor2).
    
    int operation; // menu operation chosen by the user

    operation = menu();

    while (operation != 9)
    {
        switch (operation)
        {
        case 1: // Task 6(b): Select the first mentor (mentor1), as the current mentor.
            cout << "First mentor is selected" << endl;
            currentMentor = &mentor1;
            break;

        case 2: // Task 6(c): Select the second mentor (mentor2), as the current mentor.
            cout << "Second mentor is selected" << endl;
            break;

        case 3: // Task 6(d): Display the name of the selected mentor.
            cout << "Current selected mentor: " << endl;
            break;

        case 4: // Task 6(e): Edit the selected mentor.
            break;

        case 5: // Task 6(f): Assign the selected mentor to a mentee.
            cout << "Enter the index of mentee to assign with the current mentor => ";
            cin >> index;
            break;

        case 6: // Task 6(g): Unassign the mentor from a mentee.
            cout << "Enter the index of mentee to remove its mentor => ";
            cin >> index;
            break;

        case 7: // Task 6(h): Display the info for each of the mentees.
            cout << "List of mentees:" << endl;
            break;

        } // switch

        operation = menu();

    } // while

    system("pause"); // You may want to comment out this line (system("pause")) if you are using Dev C++
    return 0;
}
