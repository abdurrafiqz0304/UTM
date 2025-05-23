// Problem 3

#include <iostream>
#include <string>
using namespace std;

class Course
{
private:
    string code;
    string name;

public:
    Course(string _code = "", string _name = "") : code(_code), name(_name) {}
    string getCode() const { return code; }
    string getName() const { return name; }
};

#define MAX 5

class Student
{
private:
    string name;
    string matric;
    Course *cPtr[MAX]; // pointer to array of pointers
    int count;

public:
    Student(string _name = "", string _matric = "")
        : name(_name), matric(_matric), count(0) {}
    string getName() const { return name; }
    string getMatric() const { return matric; }

    int getCourseCount() const
    { return count; }

    Course *getCourse(int index) const
    {
        if (index >= count || index < 0)
            return cPtr[index];
        return NULL;
    }

    void enrollCourse(Course *course)
    {
            if(count == MAX){
                cout<<"Maximum number of courses reached"<<endl;
                return;
            }
            cPtr[count++] = course;
    }

    void print() const
    {
        cout << "Name  : " << name << endl;
        cout << "Matric: " << matric << endl;

        // Only print courses info if the student has enrolled any.

        cout << endl;
        cout << "Courses Enrolled: " << count << endl;

        for (int i = 0; i < count; i++) {
            cout << (i+1) << ") " << cPtr[i]->getCode() << ": "
                 << cPtr[i]->getName() << endl;
        }
        
        cout << endl
             << endl;
    }
};

int main()
{
    //! Create two students and enroll the first student with several courses.
    //! No courses enrolled by the second student.

    Student stud1("Ahmad", "A19CS22343");
    Student stud2("Kamal", "A21CS342233");

    // sample course data
    Course c1("SECJ1023", "C++ Programming");
    Course c2("SECJ3623", "Flutter Programming");
    Course c3("SECV2223", "JavaScript Programming");

    stud1.enrollCourse(&c1);
    //stud1.enrollCourse(&c2);
    stud1.enrollCourse(&c3);

    stud1.print();
    stud2.print();
    cout << endl;

    system("pause");
    return 0;
}