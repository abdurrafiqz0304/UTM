#include <iostream>
#include <cctype>
using namespace std;

int main() {

    char ch;

    cout << "Enter a character: ";
    cin.get(ch) >> ch;

   cout << ((isdigit(ch)) ? ("Digit\n") : ((isalpha(ch)) ? ("Letter\n") : ("Special character\n")));

   system("pause");
   return 0;

}