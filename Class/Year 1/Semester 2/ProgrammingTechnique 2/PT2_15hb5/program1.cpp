// Problem 1 : Composition

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
    string area;
    string city;
    string state;
    string postCode;

public:
    Address(string _area = "", string _city = "",
            string _state = "", string _postCode = "")
        : area(_area), city(_city),
          state(_state), postCode(_postCode) {
            cout << "From Address constructor: " << area << endl;
          }

    ~Address(){
        cout << "From Address destructor: " << area << endl;
    }

    string getArea() const { return area; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getPostCode() const { return postCode; }
};

class Student
{
private:
    string name;
    string matric;
    Address add; //(1) showing composition

public:
    Student(string _name = "", string _matric = "", string _area = "", string _city = "",
            string _state = "", string _postCode = "")
        : name(_name), matric(_matric), add(_area, _city, _state, _postCode) {
            cout << "Student student constructor: " << name << endl;   
        }

    ~Student(){
        cout << "From Student destructor: " << name << endl;
    } // also destroy the address
    string getName() const { return name; }
    string getMatric() const { return matric; }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;
        cout << "Address: " << endl;
        cout << "   Area     : " << add.getArea()<< endl;
        cout << "   City     : " << add.getCity() << endl;
        cout << "   State    : " << add.getState() << endl;
        cout << "   Post Code: " << add.getPostCode() << endl;
    }
};

int main()
{
    //! Create an object of Student with an address
    Student stud("Abu", "A1234", "Skudai", "JB");
    Student s("Ali", "A4321", "Ayer Keroh");

    stud.print();
    s.print();

    system("pause");
    return 0;
}