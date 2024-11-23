#include <iostream>
using namespace std;

int main(){

    //Initialization && Variables
    char cont = 'Y';
    int intNum, qtty, totQtyy = 0;
    float price, totPrice = 0;

    do {
        cout << "Enter item number: ";
        cin >> intNum;

        switch (intNum){

        case 11 : price = 5; break;
        case 22 : price = 6.5; break;
        case 33 : price = 7; break;
        case 44 : price = 7.5; break;
        
        default: cout << "Invalid number, try again (11, 22, 33, 44)\n"; break;
            continue;
        }

        cout << "Enter the quantity: ";
        cin >> qtty;

        //Updated statement
        totQtyy += qtty;
        totPrice += price * qtty;

        //If want to continue...
        cout << "Do you want to continue? Press 'Y' ";
        cin >> cont;

    } while (cont == 'Y' || cont == 'y');

    cout << "\nTotal items ordered: " << totQtyy << endl
         << "Total price: RM" << totPrice << endl;

         system("pause");
         return 0;

}