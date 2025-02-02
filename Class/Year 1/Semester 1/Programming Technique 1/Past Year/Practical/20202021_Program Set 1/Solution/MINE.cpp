#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee {
    string name;
    string department;
    float basicSalary = 0;;
    int numOT;
    float OTP = 0.0;
    float totSalary = 0.0;
};

// Function Prototypes
int readInput(Employee emp[], int &size);
float determineRate(const string &department);
void displayOutput(Employee emp[], int size);

int main() {

    int size = 30; //assume first

    Employee emp[size];

    size = readInput(emp, size);

    displayOutput(emp,size);

    system("pause");
    return 0;
}

int readInput(Employee emp[], int &size){

    ifstream input("input.txt");

    if(!input){
        cout << "Error opening file" << endl;
    }

    int cnt = 0;

        while (cnt < size && input >> emp[cnt].department >> emp[cnt].basicSalary >> emp[cnt].numOT) {
            input.ignore();
            getline(input, emp[cnt].name);


            float rate = determineRate(emp[cnt].department);
            emp[cnt].OTP       = rate * emp[cnt].numOT;
            emp[cnt].totSalary = emp[cnt].basicSalary + emp[cnt].OTP;
            
            cnt++;

        }

    input.close();

    return cnt;

}

float determineRate(const string &department){

    if (department == "Quality") {
        return 11.5;
    } else if (department == "Production") {
        return 10.0;
    } else if (department == "Accounting") {
        return 12.5;
    } else {
        return 15.0;
    }

    return 0.0;

}

void displayOutput(Employee emp[], int size){

    cout << string(78, '-') << endl;

    cout << left << setw(20) << "NAME"
                 << setw(15) << "DEPARTMENT"
                 << setw(11) << "BASIC(RM)"
                 << setw(10) << "OT(HOUR)"
                 << setw(12) << "OT PAY(RM)"
                 << setw(10) << "SALARY(RM)"
                             << endl;

    cout << string(78, '-') << endl;

    for (int i=0;i<size;i++){

        cout << left << setw(20) << emp[i].name
                     << setw(16) << emp[i].department
                     << setw(13) << fixed << setprecision(2) << emp[i].basicSalary
                     << setw(8)  << emp[i].numOT
                     << setw(12) << fixed << setprecision(2) << emp[i].OTP
                     << setw(9)  << emp[i].totSalary
                                 << endl;

    }

    cout << string(78, '-') << endl;

}
