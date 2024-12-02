#include <iostream>
using namespace std;

double getLength(){
    double l;
    cout << "Enter the rectangle's length in m: ";
    cin >> l;

    return l;
}

double getWidth(){
    double w;
    cout << "Enter the rectangle's width in m: ";
    cin >> w;

    return w;
}

double getArea(double l, double w){
    return (l*w);
}

void displayData(double l, double w, double a){
    cout << "\nRectangle's Length = " << l << "m"<< endl;
    cout << "Rectangle's Width  = " << w << "m"<< endl;
    cout << "Rectangle's Area   = " << a << "sq.m"<< endl;
}

int main(){
    double lentgh, width, area;

    lentgh = getLength();
    width = getWidth();

    area = getArea(lentgh,width);

    displayData(lentgh,width,area);

    system("pause");
    return 0;
}