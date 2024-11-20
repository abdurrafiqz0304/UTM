
//Q6 3hb11
#include <iostream>
using namespace std;

int main() {

    char grade;
    double price;

    cout << "Our pineapple has three grades:\n";
    cout << "A, B, and C. Which do you want pricing for? ";
    cin >> grade;

    switch (grade)
    {
    case 'A':
    case 'a': price = 50.00;
        break;

    case 'B':
    case 'b': price = 30.00;
        break;

    case 'C':
    case 'c': price = 15.00;
        break;

    default: cout << "Invalid grade.";
        break;
    }

    cout << grade << " grade pineapple is RM" << price << " per kilogram.\n";

    system("pause");
    return 0;
}