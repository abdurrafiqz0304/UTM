#include <iostream>
using namespace std;

double getLength() {
    double l;
    cout << "\nRectangle's length: ";
    cin >> l;
    return l;
}

double getWidth() {
    double w;
    cout << "Rectangle's width: ";
    cin >> w;
    return w;
}

double getArea(double l, double w) {
    return (l * w);
}

void displayData(double length, double width, double area) {
    cout << "\nRectangle's Length: " << length << "m"
         << "\nRectangle's Width : " << width << "m"
         << "\nRectangle's Area  : " << area << "sq.m" << endl;
}

void validateInput(double &input) {
    while (input <= 0.0) {
        cout << "Please enter a positive number: ";
        cin >> input;
    }
}

int main() {
    cout << "This Is Rectangle Area Calculator\n";
    do {
        cout << "\nEnter Rectangle's Length and Width\n";

        // Get the rectangle's length
        double length = getLength();
        validateInput(length);

        // Get the rectangle's width
        double width = getWidth();
        validateInput(width);

        // Calculate the rectangle's area
        double area = getArea(length, width);
        displayData(length, width, area);

        double perimeter = 2 * (length + width);
        cout << "\nThe Perimeter of the Rectangle is " << perimeter << "m";

        cout << "\n\nDo you want to continue? [y/n] \n";
        char choice;
        cin >> choice;

        switch(choice) {
            case 'Y':
            case 'y':
                break;
            case 'N':
            case 'n':
                return 0;
            default:
                cout << "\nInvalid Choice!";
        }
    } while(true);
}
