#include <iostream>
using namespace std;

int main(){

int product, number, count, lastNumber;
    product, number = 1;
    count = 20; 

lastNumber = 2 * count - 1 ;
while (number <= lastNumber) {

    product = product * number;
    number = number + 2; 
    cout << product << endl;    

}

    system("pause");

    return 0;

}