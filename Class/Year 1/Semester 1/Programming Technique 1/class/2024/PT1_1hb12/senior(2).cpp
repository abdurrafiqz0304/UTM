#include <iostream>

double getPositiveInput(const std::string& prompt) {
    double value;
    do {
        std::cout << prompt;
        std::cin >> value;
        if (value <= 0.0) {
            std::cout << "Please enter a positive number.\n";
        }
    } while (value <= 0.0);
    return value;
}

void displayResults(double length, double width) {
    double area = length * width;
    double perimeter = 2 * (length + width);
    std::cout << "\nRectangle's Length: " << length << "m"
              << "\nRectangle's Width : " << width << "m"
              << "\nRectangle's Area  : " << area << " sq.m"
              << "\nRectangle's Perimeter: " << perimeter << "m\n";
}

int main() {
    std::cout << "This Is Rectangle Area Calculator\n";
    char choice;
    do {
        double length = getPositiveInput("\nEnter Rectangle's Length (positive number): ");
        double width = getPositiveInput("Enter Rectangle's Width (positive number): ");
        
        displayResults(length, width);

        std::cout << "\nDo you want to continue? [y/n] ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
