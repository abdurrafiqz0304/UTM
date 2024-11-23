#include <iostream>
using namespace std;

//Find the better solution please...
//This solution looks like nonsense
// 1. How to put hours in 24 format (i got octal error)


int main(){

    double km, h, rate;

    cout << "Enter the expected distance in km: ";
    cin >> km;
    cout << endl << "Enter at what time you will at toll in (12 hours format): ";
    cin >> h;

    if (h >= 8 || h <= 9){

        rate = 4 * km;
        cout << "Total toll fee: RM";
        cout << rate << endl;

    } else {

        rate = 3 * km;
        cout << "Total toll fee: RM";
        cout << rate << endl;

    }

    system("pause");

}