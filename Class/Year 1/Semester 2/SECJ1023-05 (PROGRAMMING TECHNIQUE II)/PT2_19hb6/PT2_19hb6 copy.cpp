#include <iostream>
#include <vector>
using namespace std;

class Student {
    string name;
    int year;
    float cpa;

public:
    Student(string n = "", int y = 0, float c = 0.0) : name(n), year(y), cpa(c) {}

    void print() const {
        cout << "Name: " << name << ", Year: " << year << ", CPA: " << cpa << endl;
    }
};

// ✅ Move menu() outside of the class
int menu() {
    int option;
    cout << "\n(1) Insert a new student" << endl;
    cout << "(2) Remove student" << endl;
    cout << "(3) Display all students" << endl;
    cout << "(0) Exit" << endl;
    cout << "Enter your option: ";
    cin >> option;
    return option;
}

int main() {
    vector<Student> stuList;
    int opt;

    do {
        opt = menu();
        cin.ignore(); // Clear newline

        switch (opt) {
            case 1: {
                string name;
                int year;
                float cpa;
                cout << "Enter student name: ";
                getline(cin >> ws, name);
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter CPA: ";
                cin >> cpa;
                stuList.push_back(Student(name, year, cpa));
                break;
            }
            case 2: {
                if (stuList.empty()) {
                    cout << "No students to remove." << endl;
                    break;
                }

                for (int i = 0; i < stuList.size(); i++) {
                    cout << "Student " << i + 1 << ": ";
                    stuList.at(i).print();
                }

                cout << "Enter the ID of student to remove: ";
                int id;
                cin >> id;

                if (id >= 1 && id <= stuList.size()) {
                    stuList.erase(stuList.begin() + id - 1);
                    cout << "Student removed successfully." << endl;
                } else {
                    cout << "Invalid ID." << endl;
                }
                break;
            }
            case 3: {
                if (stuList.empty()) {
                    cout << "No students to display." << endl;
                    break;
                }
                for (int i = 0; i < stuList.size(); i++) {
                    cout << "Student " << i + 1 << ": ";
                    stuList[i].print();
                }
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (opt != 0);

    return 0;
}
