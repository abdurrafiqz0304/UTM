// ABDURRAFIQ BIN ZAKARIA A24CS0031

#include <iostream>
using namespace std;

class Base {
    public:
        void print() {
            cout << "Base class print function called." << endl;
        }

        virtual void display() { // Polymorphic function
            cout << "Base class display function called." << endl;
        }
};

class Derived1: public Base { // Inherits from Base class
    public:
        void print() { // redefine the print function
            Base::print(); // Call the base class print function
            cout << "Derived1 class print function called." << endl;
        }

        void display() override { // Override the base class display function
            Base::display(); // Call the base class display function
            cout << "Derived1 class display function called." << endl;
        }
};

class Derived2: public Base { // Inherits from Base class
    public:
        void print() { // redefine the print function
            Base::print(); // Call the base class print function
            cout << "Derived2 class print function called." << endl;
        }

        void display() override { // Override the base class display function
            Base::display(); // Call the base class display function
            cout << "Derived2 class display function called." << endl;
        }
};

int main() {
    Base *b;
    Derived1 d1;
    Derived2 d2;

    b = &d1; // Pointing to Derived1 object
    b->print(); // Calls Base's print function, then Derived1's print function
    b->display();

    cout << endl; // Print a new line for better readability
    b = &d2; // Pointing to Derived2 object
    b->print(); // Calls Base's print function, then Derived2's print function
    b->display();

    system("pause"); // Pause the console to view output
    return 0;
}