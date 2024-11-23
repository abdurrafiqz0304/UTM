#include <iostream>
using namespace std;
 int main (){

    float a, b, bmi, c;

    cout << "Please enter your weight in kg: \n";
    cin >> a;
    cout << "Please enter your height in cm: \n";
    cin >> b;
    c = b / 100;
    bmi = (a / (c*c));
    cout << "Your BMI is: ";
    cout << bmi << endl;
    system("pause");

 }