#include <iostream>
using namespace std;

int main(){

float a, b;
cout << "Enter temperature in Fahrenheit: ";
cin >> a;
b = 5 / 9 * (a-32);
cout << a + "in celcius is: " + b;

}