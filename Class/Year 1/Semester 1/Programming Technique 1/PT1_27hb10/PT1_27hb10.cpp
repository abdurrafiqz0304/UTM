#include <iostream>
using namespace std;

int main() {
    int n1 = 75; //Decimal 
    int n2 = 075; //Octal
    int n3 = 0x75A; //Hexadecimal 

    char s1[10] = "Liza"; //can accept 10 character
    string s2; //unlimited

   // s1 = "Liza"; can not be assign
    s2 = "Hello";

    cout << "Decimal = " << n1
         << oct << "\nOctal = " << n2
         << dec << "\nHexadecimal = " << n3 <<endl;
         //oct, dec, hex  , without << hex << will output decimal

         cout << sizeof(int) << endl
              << sizeof(n2) << endl; //show file size
        cout << 8 - (3 + 9/2) + 2 *  5;
    system("pause");
    return 0;
}