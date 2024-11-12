/*_____________________________________________________

                        ARRAY!!!!!
  _____________________________________________________*/

#include <iostream>
using namespace std;

int main() {
    //Variables declaration
    int num1;
    float num2;
    char ch;
    char str[10];

    //Input purposes
    cout << "Enter an integer: ";
    cin >> num1;

    cout << "Enter an decimal: ";
    cin >> num2;

    cout << "Enter a single character: ";
    cin >> ch;

    cout << "Enter an array of character: ";
    cin >> str;

    //Output purposes
    cout << "\nYour integer = " << num1 << endl
         << "Your decimal number = " << num2 << endl
         << "Your single character = " << ch << endl
         << "Your single character in ASCII = " << (int) ch << endl
         << "Your string = " << str << endl;

    cout << num1 + ch << endl;


    system("pause");
    return 0;
}