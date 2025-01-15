#include <iostream>
using namespace std;

// Function to get the length of the rectangle
double getLength() {
    double l;
    cout << "Enter rectangle's length in m: ";
    cin >> l;
    return l;
}

// Function to get the width of the rectangle
double getWidth() {
    double w;
    cout << "Enter the rectangle's width in m: ";
    cin >> w;
    return w;
}

// Function to calculate the area of the rectangle
double getArea(double length, double width) {
    return length * width;
}

// Function to display the length, width, and area of the rectangle
void displayData(double length, double width, double area) {
    cout << "Length: " << length << " meters" << endl;
    cout << "Width: " << width << " meters" << endl;
    cout << "Area: " << area << " square meters" << endl;
}

int main() {
    // Call the functions and store the results
    double length = getLength(); // Calling getLength function
    double width = getWidth(); // Calling getWidth function
    
    // Calculate the area by calling getArea function
    double area = getArea(length, width);
    
    // Display the data by calling displayData function
    displayData(length, width, area);
    
    system("pause"); // This line may be optional depending on your environment
    return 0;
}
