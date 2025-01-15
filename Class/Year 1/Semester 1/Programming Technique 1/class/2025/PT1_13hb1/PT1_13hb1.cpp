#include <iostream>
#include <string> // Include string header
using namespace std;

struct Address {
    string city,
           state;
};

struct Student {
    string name;
    int year;
    float cpa;
    Address add; //nested structure
};

void getInput(Student arr[], int n); // Declare function after struct definitions

int main() {
    Student arr[3] = {{"Liza", 2}, {"Abu", 3}, {"Rashid", 4}};

    getInput(arr, 3);

    for (int i = 0; i < 3; i++) {
        cout << arr[i].name << '\t';
        cout << arr[i].year << '\n';
        cout << arr[i].add.state << '\n';
    }

    system("pause");
    return 0;
}

void getInput(Student arr[], int n) {
    cout << "Please enter the following information: \n";
    for (int i = 0; i < n; i++) {
        cout << "CPA: ";
        cin >> arr[i].cpa;

        cin.ignore(); // Clear the newline character from the buffer

        cout << "CITY: ";
        getline(cin, arr[i].add.city);

        cout << "STATE: ";
        getline(cin, arr[i].add.state);
    }
}

//Better to use pass by reference so not waste space but
//it will affected the value in main
//so, to overcome, use "const" in function disp (for exp)