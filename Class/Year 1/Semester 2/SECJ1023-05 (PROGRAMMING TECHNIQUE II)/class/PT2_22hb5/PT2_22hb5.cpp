#include <iostream>
using namespace std;

class Insect { // Base class
    public:
     Insect() {
        cout << "Insect constructor called" << endl;
    }

    Insect(string s) {
        cout << "Insect constructor called" << s << endl;
    }
};
class Bee : public Insect { // Derived class
    public:
        Bee() : Insect(": Hello") { // Call base class constructor
            cout << "Bee constructor called" << endl;
        }
};
class GrassHopper : public Insect { // Derived class
    public:
        GrassHopper() {
            cout << "GrassHopper constructor called" << endl;
        }
};

int main() {
    Insect insect; // Create an object of the base class
    Bee b1, b2; // Create two objects of the derived class
    GrassHopper gh; // Create two objects of the derived class

    insect = b1; // Assign derived class object to base class object

    system("pause");
    return 0;
}