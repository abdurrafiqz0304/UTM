#include <iostream>
using namespace std;

// Function to convert Fahrenheit to Celsius
double FtoC(double F) {
    return (5.0 / 9.0) * (F - 32);
}

// Function to convert Kelvin to Celsius
double KtoC(double K) {
    return K - 273.15;
}

int main() {
    double F, K;
    char choice, choice1;

    cout << "This Calculator converts Fahrenheit to Celsius and Kelvin to Celsius" << endl;

    do {
        cout << "Press 'f' for Fahrenheit or press 'k' for Kelvin: ";
        cin >> choice;

        // Convert temperature based on user's choice
        switch (choice) {
            case 'f':
            case 'F':
                cout << "Enter the temperature in Fahrenheit: ";
                cin >> F;
                cout << "The temperature is " << FtoC(F) << " degrees Celsius." << endl;
                break;
            case 'k':
            case 'K':
                cout << "Enter the temperature in Kelvin: ";
                cin >> K;
                cout << "The temperature is " << KtoC(K) << " degrees Celsius." << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }

        cout << "Do you want to continue? Press y/n: ";
        cin >> choice1;

    } while (choice1 == 'y' || choice1 == 'Y');

    return 0;
}
