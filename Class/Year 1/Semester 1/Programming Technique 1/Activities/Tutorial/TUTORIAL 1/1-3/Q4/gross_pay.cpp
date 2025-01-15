#include <iostream>
using namespace std;

int main(){

    float w, r, o, gp, tax, net, rp, op;
    
    cout << "Please enter the employee's hourly wage: ";
    cin >> w;
    cout << endl;

    cout << "Number of regular hours worked: ";
    cin >> r;
    cout << endl;

    cout << "Number of overtime hours worked: ";
    cin >> o;
    cout << endl;

    rp = w * r;
    op = (w * 1.5) * o;
    gp = rp + op;
    tax = gp * 0.2 ;
    net = gp - tax;

    cout << "Your gross pay is: ";
    cout << gp;
    cout << endl;

    cout << "Your tax is: ";
    cout << tax;
    cout << endl;

    cout << "Your net pay is: ";
    cout << net;
    cout << endl;

    system("pause");

    return 0;

}