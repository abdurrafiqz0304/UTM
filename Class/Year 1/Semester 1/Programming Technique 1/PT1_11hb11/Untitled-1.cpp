#include <iostream>
using namespace std;

int main() {
    char itemCode;
    float totalCost = 0.0, price = 0.0;
    int qty = 0, ask = 1, totalQty = 0;

    cout << "Welcome to FreshMart Grocery!\n";
    cout << "Available items:\n";
    cout << "A - Apples  (RM3.50 per kg)\n";
    cout << "B - Bananas (RM2.80 per kg)\n";
    cout << "C - Carrots (RM1.60 per kg)\n";
    cout << "D - Dates   (RM8.20 per kg)\n";

    while (ask == 1) {
        cout << "Enter item code: ";
        cin >> itemCode;
        cout << "Enter item quantity (in kg): ";
        cin >> qty;

        switch (itemCode) {
            case 'A': price = 3.50; break;
            case 'B': price = 2.80; break;
            case 'C': price = 1.60; break;
            case 'D': price = 8.20; break;
            default: 
                cout << "Invalid item code! Please enter a valid code (A, B, C, or D).\n";
                continue; // Skip the rest of the loop and ask for the item code again
        }

        totalCost += price * qty;
        totalQty += qty;

        cout << "Do you want to purchase another item? (Press 1 to continue, any other key to stop): ";
        cin >> ask;
    }

    cout << "Total quantity of items purchased: " << totalQty << " kg\n";
    cout << "Total price: RM" << totalCost << endl;

    return 0;
}
