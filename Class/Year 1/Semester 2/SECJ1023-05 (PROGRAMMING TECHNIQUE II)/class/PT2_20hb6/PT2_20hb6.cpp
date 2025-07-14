#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Course {
    string id, name;

public:
    Course(string _id = "", string n = "") : id(_id), name(n) {}

    void print() const {
        cout << name << " (" << id << ")" << endl;
    }
};

class Student {
    string matrics, name;
    float cpa;
    vector<Course*> cList;

public:
    Student(string m = "", string n = "", float c = 0.0) : matrics(m), name(n), cpa(c) {}

    void addCourse(Course* c) {
        cList.push_back(c); // only write c because it's a pointer in parameter, same with cList
    }

    void print() const {
        cout << "Name: " << name << ", Matric: " << matrics << ", CPA: " << cpa << endl;
    }

    void printInfo() {
        print();
        cout << "Number of Courses enrolled: " << cList.size() << endl;

        cout << "List of Courses: " << endl;

        for (auto i = cList.begin(); i < cList.end(); i++)
            (*i)->print();
    }
};

int main() {


    map<string, Course> courses = {{"SECJ1023", Course("SECJ1023", "PT2")},
                                    {"SECJ2154", {"SECJ2154", "OOP"}},
                                    {"SECJ2013", {"SECJ2013", "DSA"}}
                                  };

    Student s("A24CS0031", "ABDURRAFIQ BIN ZAKARIA", 3.72);

    for (auto i = courses.begin() ; i != courses.end(); i++)
        i->second.print();
        
        string code = "";
        char opt;
        bool status = 1;

        while(status) {
            cout << "Please enter course code to enroll: ";
            cin >> code;

            if (courses.find(code) != courses.end())
                s.addCourse(&courses[code]); // code is string, put the key we want to find in [] // &bank[nak_cari_apa]
            else
                cout << "Code is not foundn\n\n";

            cout << "Do you want to enroll other course? [y/n]: ";
            cin >> opt;

            if (tolower(opt) != 'y') status = 0;
        }

    s.printInfo();

    system("pause");
    return 0;
}