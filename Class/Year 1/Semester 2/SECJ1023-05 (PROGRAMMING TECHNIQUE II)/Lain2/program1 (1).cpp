#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Course {
private:
    string name;
    int credit;

public:
    Course(string _name = "", int _credit = 1) : name(_name), credit(_credit) {}
    string getName() const { return name; }
    int getCredit() const { return credit; }
    void print() const {
        cout << "Course: " << name << "   Credit=" << credit << endl;
    }
};

class Student {
private:
    string name, matric;
    vector<Course *> courses;

public:
    Student(string _name = "", string _matric = "") : name(_name), matric(_matric) {}
    string getName() const { return name; }
    void enrollToCourse(Course *c) {
        courses.push_back(c);
    }
    int getEnrolledCount() const {
        return courses.size();
    }
    int getTotalCredit() const {
        int totCredit = 0;
        for (int i = 0; i < courses.size(); i++) {
            totCredit += courses[i]->getCredit();
        }
        return totCredit;
    }
    void printCourses() const {
        for (int i = 0; i < courses.size(); i++) {
            cout << "Course: " << courses[i]->getName() << endl;
        }
    }
    void printSummary() const {
        cout << "Name: " << name << endl;
        cout << "Matric: " << matric << endl;
        cout << "Number of courses enrolled: " << getEnrolledCount() << endl;
        cout << "Total credit carried: " << getTotalCredit() << endl;
    }
};

int main() {
    vector<Course> cList = {
        {"Programming Technique I", 3},
        {"Programming Technique II", 3},
        {"Operating Systems", 3},
        {"Web Programming", 3},
        {"Digital Logic", 3},
        {"Object-Oriented Programming", 4},
        {"Application Development", 4},
        {"Final Year Project I", 2},
        {"Software Engineering", 3},
        {"Graduate Success Attributes", 2}
    };

    map<string, Student> students = {
        {"A16EC4041", Student("Mario Max", "A16EC4041")},
        {"A16EC4045", Student("Wilma Mumduya", "A16EC4045")},
        {"A18EC4056", Student("Anna Sthesia", "A18EC4056")},
        {"A16EC9043", Student("Paul Molive", "A16EC9043")},
        {"A19EC4002", Student("Anna Mull", "A19EC4002")},
        {"A16EC4032", Student("Gail Forcewind", "A16EC4032")},
        {"A16EC3002", Student("Paige Turner", "A16EC3002")},
        {"A17EC3003", Student("Bob Frapples", "A17EC3003")},
        {"A17EC4043", Student("Robin Banks", "A17EC4043")},
        {"A18EC4044", Student("Jimmy Changa", "A18EC4044")}
    };

    for (auto &course : cList) {
        course.print();
    }

    string matricNumber;
    cout << "Enter student matric number to enroll in courses: ";
    cin >> matricNumber;

    if (students.find(matricNumber) != students.end()) {
        Student &student = students[matricNumber];
        string courseName;
        char opt;
        bool status = true;

        while (status) {
            cout << "Please enter course name to enroll: ";
            cin.ignore();
            getline(cin, courseName);

            bool found = false;
            for (auto &course : cList) {
                if (course.getName() == courseName) {
                    student.enrollToCourse(&course);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Course not found\n\n";
            }

            cout << "Do you want to enroll in another course? [y/n]: ";
            cin >> opt;

            if (tolower(opt) != 'y') status = false;
        }

        student.printSummary();
        student.printCourses();
    } else {
        cout << "Student not found.\n";
    }

    return 0;
}
