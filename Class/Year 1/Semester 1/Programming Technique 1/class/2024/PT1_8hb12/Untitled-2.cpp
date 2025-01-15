#include <iostream>
using namespace std;

void itemPrice(int &itemCode){

    int code;
    float price = 0.0;

    switch (code){
        case 101 : price = 9.90; break;
        case 201 : price = 6.90; break;
        case 305 : price = 7.99; break;
        case 404 : price = 5.99; break;
        default : "Invalid code. Please try again!";break;}
}
void userInput(){
    int code, quantity; float price, totalPrice;

    cout << "Enter item's code=>";
    cin >> code;

    itemPrice(code);

    totalPrice = price * quantity;
    cout << "Total amount to pay: " << totalPrice;
}
int main(){
userInput();
system("pause");
return 0;
}