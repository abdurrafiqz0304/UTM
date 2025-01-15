#include <iostream>
using namespace std;
    int code, quantity;
    double price = 0.0;
    double totalPrice;

void itemPrice(int &code){
    double price = 0.0;
    switch (code){
        case 101 : price = 9.90; code =1; break;
        case 201 : price = 6.90; code =1; break;
        case 305 : price = 7.99; code =1; break;
        case 404 : price = 5.99; code =1; break;
        default : cout << "Invalid code. Please try again!\n\n"; code = 0; break ;
       
    }
}


double userInput(){

    do {
        cout << "Enter item's code=>";
        cin >> code;

        itemPrice(code);

        if (code) break; 

        totalPrice = price * quantity;

        cout << "Total amount to pay: " << totalPrice;
    } while (code == 1);

    return totalPrice;
}

int main(){
    userInput();

    system("pause");
    return 0;
}