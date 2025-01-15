#include <iostream>
using namespace std;

bool itemPrice( int &itemCode , float &itemPrice){

    int code;
    float price;

    switch (code){
        case 101 : price = 9.9; return true;
        case 201 : price = 6.90; return true;
        case 305 : price = 7.99; return true;
        case 404 : price = 5.99; return true;
        default : "Invalid code. Please try again!";return false;

        price += price;
    }

    return price;
}
void userInput(){
    int code, quantity; float price, totalPrice;

    do {
        cout << "Enter item's code=>";
        cin >> code;

        if(itemPrice(code, price)){
            cout << "Enter amount of items=>";
        } else {
            cout << "Invalid code. Please try again!";
        }
    } while(false);

    totalPrice = price * quantity;
    cout << "Total amount to pay: " << totalPrice;
}
int main(){
userInput();
system("pause");
return 0;
}