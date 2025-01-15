#include <iostream>
using namespace std;

int main() {
    // Declare variables
    int code, quantity, choice;
    float price, totalPrice;

    do {
        cout << "Enter item's code=>";
        cin >> code;

        cout << "Enter amount of items=>";
        cin >> quantity;

        cout << endl;

        switch (code) {
            case 101: price = 9.90; break;
            case 201: price = 6.90; break;
            case 305: price = 7.99; break;
            case 404: price = 5.99; break;
            default: 
                cout << "Invalid code. Please try again!\n";
                continue; // Skip the rest of the loop and ask for input again
        }

        totalPrice = quantity * price;
        cout << "Total amount to pay: " << totalPrice << endl;

        cout << "Enter 0 to continue or any other number to exit: ";
        cin >> choice;

    } while (choice == 0);

    return 0;
}
