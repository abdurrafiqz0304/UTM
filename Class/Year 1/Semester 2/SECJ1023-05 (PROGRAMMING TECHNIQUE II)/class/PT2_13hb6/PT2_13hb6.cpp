#include <iostream>
using namespace std;

// Composition
class Point {
    public:
        class ExceptionZero{};
    };

    // Alone
class newException: public exception {
    public:
        const char* what() const noexcept override {
            return "An error occurred";
        }
};

int main() {
    int opt;

    cout << "Enter an integer number: ";
    cin >> opt;

    try {
        switch (opt) {
            case 1:
                throw opt;
            case 2:;
                throw "Error";
            case 3:
                throw Point::ExceptionZero(); // This is a nested exception class
            case 4:
                throw newException();

        };
        cout << "In try block" << endl;
    }

   // cout << "try" << endl; // Error because in between try and catch blocks

    catch (const char *s) {
        cout << "Caught a string: " << s << endl;
    }
    catch (Point::ExceptionZero) {
        cout << "Caught a double: " << endl;
    }

    catch (int n) {
        cout << "Caught an integer: " << n << endl;
    }
    catch (double d) {
        cout << "Caught a double: " << d << endl;
    }

    catch (newException &e) {
        cout << "Caught a newException: " << e.what() << endl;
    }

    
    catch (const char *s) {
        cout << s << endl;
        cout << "In catch block" << endl; // This will execute after the catch block if match with the thrown exception (char)
    }

    catch (...) {
        cout << "Caught an unknown exception" << endl;
    }

    // Exception handling in C++ allows you to manage errors gracefully.

    system("pause");
    return 0;
}