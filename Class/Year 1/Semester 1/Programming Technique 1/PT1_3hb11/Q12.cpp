//Q12
#include <iostream>
using namespace std;

int main() {

    int a, b;

    cout << "Please enter the value to be tested: ";
    cin >> a ;

    (a >= 0) ? (b = 1) : (b = 2);

    switch (b) {
        case 1 : a ? cout << "The given value is positive\n" : cout << "The given value is zero\n";
            break;
        default : cout << "The give value is negative\n";
            break;
    }

    system("pause");
    return 0;
}