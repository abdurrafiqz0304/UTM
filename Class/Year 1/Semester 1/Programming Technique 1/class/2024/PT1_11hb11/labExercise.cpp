/*Name: Abdurrafiq Bin Zakaria
  Matric: A24CS0031
  Date: 11/11/2024*/

#include <iostream>
using namespace std;

int main(){

    //declairing variables
    char itemCode;
    float price, totalPrice;
    int qty, totalQty, ask;

    //initialization
    qty = 0;
    totalQty = 0;
    totalPrice = 0;

    //greeting
    cout << "Welcome to FreshMart Grocery!\n" << 
             "Available items: \n" <<
             "A - Apples  (RM3.50 per kg) \n" <<
             "B - Bananas (RM2.80 per kg) \n" <<
             "C - Carrots (RM1.60 per kg) \n" <<
             "D - Dates   (RM8.20 per kg) \n";


        cout << "\nEnter item code: ";
        cin >> itemCode;

    //Start while loop
    while(itemCode == 'A' || itemCode == 'B' || itemCode == 'C' || itemCode == 'D'){

        //start switch
        switch (itemCode) {
            case 'A' : price = 3.50;
            break;

            case 'B' : price = 2.80;
            break;

            case 'C' : price = 1.60;
            break;

            case 'D' : price = 8.20;
            break;

            default : cout << "Invalid item code! Please enter a valid code (A, B, C, or D).";
            break; 
           
        } //end of switch

        //Prompt
            cout << "\nEnter item code: ";
            cin >> itemCode;
            cout << "Enter quantity: ";
            cin >> qty;
            cout <<endl;
            
    } //end of while

            cout << "Do you want to purchase another item? (Press 1 to continue): ";
            cin >> ask;
            cout <<endl;
    
system("pause");
return 0;
}