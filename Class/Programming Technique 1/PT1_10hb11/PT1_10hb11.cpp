#include <iostream>
#include <cctype>
using namespace std;

int main() 
{ 
 char choice; 
 int qty; 
 float price, tot_Price = 0;
 
 //input
cout << "Enter the item id: ";
cin >> choice; //initialization
choice = toupper(choice);

cout << "Enter the quantity of item: ";
cin >> qty;

while (choice == 'A' || choice == 'O' || choice == 'L'){

//process
switch (choice)
{
//case A
case 'A': price = 2;
    break;

//case O
case 'O': price = 2.5;
    break;

default: price = 1.8;
    break;
}

tot_Price += qty * price;

cout << "Enter the item id: ";
cin >> choice; //updating statement
}

//output
cout << "The total price is: " << tot_Price << endl;

system("pause");
return 0;
}