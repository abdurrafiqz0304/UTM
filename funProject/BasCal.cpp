#include <iostream>
using namespace std;

double addOpe() {
    double a, b, c;
    cout << "Enter three numbers to add (separated by spaces): ";
    cin >> a >> b >> c;
    return (a + b + c);
}

double subsOpe() {
    double d, e;
    cout << "Enter two numbers to subtract (separated by spaces): ";
    cin >> d >> e;
    return (d - e);
}

double mulOpe() {
    double f, g;
    cout << "Enter two numbers to multiply (separated by spaces): ";
    cin >> f >> g;
    return (f * g);
}

double divideOpe() {
    double h, i;
    cout << "Enter two numbers to divide (separated by spaces): ";
    cin >> h >> i;
    if (i == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return (h / i);
}

void displayResult(double result) {
    cout << "= " << result << endl;
}

int main() {
    int choice;
    double result;

    do{
        
    cout << "\nTHIS IS A SIMPLE CALCULATOR\n";
    cout << "Press any number to start:\n"
         << "1. Addition\n"
         << "2. Subtraction\n"
         << "3. Multiplication\n"
         << "4. Division\n\n";
    cin >> choice;

    switch (choice) {
        case 1:
            result = addOpe();
            displayResult(result);
            break;
        case 2:
            result = subsOpe();
            displayResult(result);
            break;
        case 3:
            result = mulOpe();
            displayResult(result);
            break;
        case 4:
            result = divideOpe();
            displayResult(result);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    char ans;
    cout << "Proceed to continue? [Y/N]";
    cin >> ans;

    switch (ans) {
        case 'Y':
        case 'y': continue;
            break;
        case 'N':
        case 'n': exit(0);
        default: cout << "Invalid";
        break;
    }

    }while(true);

    return 0;
}
